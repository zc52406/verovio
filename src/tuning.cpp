/////////////////////////////////////////////////////////////////////////////
// Name:        tuning.cpp
// Author:      Laurent Pugin
// Created:     2019
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "tuning.h"

//----------------------------------------------------------------------------

#include <assert.h>
#include <string>

//----------------------------------------------------------------------------

#include "comparison.h"
#include "course.h"
#include "editorial.h"

namespace vrv {

//----------------------------------------------------------------------------
// Tuning
//----------------------------------------------------------------------------

static const ClassRegistrar<Tuning> s_factory("tuning", TUNING);

Tuning::Tuning() : Object(TUNING, "tuning-"), AttCourseLog()
{
    RegisterAttClass(ATT_COURSELOG);

    Reset();
}

Tuning::~Tuning() {}

void Tuning::Reset()
{
    Object::Reset();
    ResetCourseLog();
}

bool Tuning::IsSupportedChild(Object *child)
{
    if (child->Is(COURSE)) {
        assert(dynamic_cast<Course *>(child));
    }
    else if (child->IsEditorialElement()) {
        assert(dynamic_cast<EditorialElement *>(child));
    }
    else {
        return false;
    }
    return true;
}

int Tuning::CalcPitchPos(int course, data_NOTATIONTYPE notationType, int lines)
{
    switch (notationType) {
        case NOTATIONTYPE_tab_lute_french:
            // all courses >= 7 are positioned above line 0
            return (lines - std::min(course, 7)) * 2 + 1; // above the line
        case NOTATIONTYPE_tab_lute_italian: return (course - 1) * 2;
        case NOTATIONTYPE_tab_guitar: [[fallthrough]];
        default: return abs(course - lines) * 2;
    }
}

int Tuning::CalcPitchNumber(int course, int fret, data_NOTATIONTYPE notationType)
{
    // Use <tuning><course>s, if available
    // else use @tuning.standard, if available
    // else use @notationType

    // Do we have the tuning for this course?
    AttNNumberLikeComparison cnc(COURSE, std::to_string(course));
    Course *courseTuning = vrv_cast<Course *>(FindDescendantByComparison(&cnc));

    if (courseTuning && courseTuning->HasPname() && courseTuning->HasOct()) {

        // Distance in semitones from the octave's starting C to the given note
        int midiBase = 0;
        switch (courseTuning->GetPname()) {
            case PITCHNAME_c: midiBase = 0; break;
            case PITCHNAME_d: midiBase = 2; break;
            case PITCHNAME_e: midiBase = 4; break;
            case PITCHNAME_f: midiBase = 5; break;
            case PITCHNAME_g: midiBase = 7; break;
            case PITCHNAME_a: midiBase = 9; break;
            case PITCHNAME_b: midiBase = 11; break;
            case PITCHNAME_NONE: break;
        }

        const int octave = courseTuning->GetOct();

        // As this does not represent historical notation of any kind the only
        // accidentals we should ever see are "s" and "f"
        int alter = 0;
        if (courseTuning->HasAccid()) {
            if (courseTuning->GetAccid() == ACCIDENTAL_WRITTEN_s)
                alter = 1;
            else if (courseTuning->GetAccid() == ACCIDENTAL_WRITTEN_f)
                alter = -1;
        }

        return (octave + 1) * 12 + midiBase + alter + fret; // MIDI note C4 = 60
    }

    // no <tuning><course> specified, fall back to @tuning.standard
    // TODO what other values for @tuning.standard will there be?

    //                                 E4  B3  G3  D3  A2  E2
    static const int guitarPitch[] = { 64, 59, 55, 50, 45, 40 }; // modern guitar

    //                                      E4  B3  G3  D3  A2  D2
    static const int guitarDropDPitch[] = { 64, 59, 55, 50, 45, 38 }; // modern guitar drop D

    //                               G4  D4  A3  F3  C3  G2
    static const int lutePitch[] = { 67, 62, 57, 53, 48, 43 }; // 6 course renaissance lute

    const int *pitch = nullptr;
    int pitchSize = 0;

    switch (GetTuningStandard()) {
        case COURSETUNING_guitar_drop_D:
            pitch = guitarDropDPitch;
            pitchSize = sizeof(guitarDropDPitch);
            break;

        case COURSETUNING_lute_renaissance_6:
            pitch = lutePitch;
            pitchSize = sizeof(lutePitch);
            break;

        case COURSETUNING_NONE: [[fallthrough]];

        default:
            // @tuning.standard is not specified, use @notationType

            if (notationType == NOTATIONTYPE_tab_lute_french || notationType == NOTATIONTYPE_tab_lute_italian
                || notationType == NOTATIONTYPE_tab_lute_german) {
                // lute tablature, assume 6 course renaissance lute
                pitch = lutePitch;
                pitchSize = sizeof(lutePitch);
            }
            else {
                // assume modern guitar
                pitch = guitarPitch;
                pitchSize = sizeof(guitarPitch);
            }
            break;
    }

    return (course > 0 && course <= pitchSize) ? pitch[course - 1] + fret : 0;
}

} // namespace vrv
