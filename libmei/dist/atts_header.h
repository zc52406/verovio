/////////////////////////////////////////////////////////////////////////////
// Authors:     Laurent Pugin and Rodolfo Zitellini
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
//
// Code generated using a modified version of libmei
// by Andrew Hankinson, Alastair Porter, and Others
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// NOTE: this file was generated with the Verovio libmei version and
// should not be edited because changes will be lost.
/////////////////////////////////////////////////////////////////////////////

#ifndef __LIBMEI_ATTS_HEADER_H__
#define __LIBMEI_ATTS_HEADER_H__

#include "att.h"
#include "attdef.h"
#include "pugixml.hpp"

//----------------------------------------------------------------------------

#include <string>

namespace vrv {

//----------------------------------------------------------------------------
// AttBifoliumSurfaces
//----------------------------------------------------------------------------

class AttBifoliumSurfaces : public Att {
protected:
    AttBifoliumSurfaces();
    ~AttBifoliumSurfaces() = default;

public:
    /** Reset the default values for the attribute class **/
    void ResetBifoliumSurfaces();

    /** Read the values for the attribute class **/
    bool ReadBifoliumSurfaces(pugi::xml_node element, bool removeAttr = true);

    /** Write the values for the attribute class **/
    bool WriteBifoliumSurfaces(pugi::xml_node element);

    /**
     * @name Setters, getters and presence checker for class members.
     * The checker returns true if the attribute class is set (e.g., not equal
     * to the default value)
     **/
    ///@{
    void SetOuterRecto(std::string outerRecto_) { m_outerRecto = outerRecto_; }
    std::string GetOuterRecto() const { return m_outerRecto; }
    bool HasOuterRecto() const;
    //
    void SetInnerVerso(std::string innerVerso_) { m_innerVerso = innerVerso_; }
    std::string GetInnerVerso() const { return m_innerVerso; }
    bool HasInnerVerso() const;
    //
    void SetInnerRecto(std::string innerRecto_) { m_innerRecto = innerRecto_; }
    std::string GetInnerRecto() const { return m_innerRecto; }
    bool HasInnerRecto() const;
    //
    void SetOuterVerso(std::string outerVerso_) { m_outerVerso = outerVerso_; }
    std::string GetOuterVerso() const { return m_outerVerso; }
    bool HasOuterVerso() const;
    ///@}

private:
    /**
     * A reference to a surface element positioned on the outer recto side of a
     * (folded) sheet.
     **/
    std::string m_outerRecto;
    /**
     * A reference to a surface element positioned on the inner verso side of a
     * (folded) sheet.
     **/
    std::string m_innerVerso;
    /**
     * A reference to a surface element positioned on the inner recto side of a
     * (folded) sheet.
     **/
    std::string m_innerRecto;
    /**
     * A reference to a surface element positioned on the outer verso side of a
     * (folded) sheet.
     **/
    std::string m_outerVerso;
};

//----------------------------------------------------------------------------
// InstBifoliumSurfaces
//----------------------------------------------------------------------------

/**
 * Instantiable version of AttBifoliumSurfaces
 */

class InstBifoliumSurfaces : public AttBifoliumSurfaces {
public:
    InstBifoliumSurfaces() = default;
    virtual ~InstBifoliumSurfaces() = default;
};

//----------------------------------------------------------------------------
// AttFoliumSurfaces
//----------------------------------------------------------------------------

class AttFoliumSurfaces : public Att {
protected:
    AttFoliumSurfaces();
    ~AttFoliumSurfaces() = default;

public:
    /** Reset the default values for the attribute class **/
    void ResetFoliumSurfaces();

    /** Read the values for the attribute class **/
    bool ReadFoliumSurfaces(pugi::xml_node element, bool removeAttr = true);

    /** Write the values for the attribute class **/
    bool WriteFoliumSurfaces(pugi::xml_node element);

    /**
     * @name Setters, getters and presence checker for class members.
     * The checker returns true if the attribute class is set (e.g., not equal
     * to the default value)
     **/
    ///@{
    void SetRecto(std::string recto_) { m_recto = recto_; }
    std::string GetRecto() const { return m_recto; }
    bool HasRecto() const;
    //
    void SetVerso(std::string verso_) { m_verso = verso_; }
    std::string GetVerso() const { return m_verso; }
    bool HasVerso() const;
    ///@}

private:
    /** A reference to a surface element positioned on the recto side of the sheet. **/
    std::string m_recto;
    /** A reference to a surface element positioned on the verso side of the sheet. **/
    std::string m_verso;
};

//----------------------------------------------------------------------------
// InstFoliumSurfaces
//----------------------------------------------------------------------------

/**
 * Instantiable version of AttFoliumSurfaces
 */

class InstFoliumSurfaces : public AttFoliumSurfaces {
public:
    InstFoliumSurfaces() = default;
    virtual ~InstFoliumSurfaces() = default;
};

//----------------------------------------------------------------------------
// AttRecordType
//----------------------------------------------------------------------------

class AttRecordType : public Att {
protected:
    AttRecordType();
    ~AttRecordType() = default;

public:
    /** Reset the default values for the attribute class **/
    void ResetRecordType();

    /** Read the values for the attribute class **/
    bool ReadRecordType(pugi::xml_node element, bool removeAttr = true);

    /** Write the values for the attribute class **/
    bool WriteRecordType(pugi::xml_node element);

    /**
     * @name Setters, getters and presence checker for class members.
     * The checker returns true if the attribute class is set (e.g., not equal
     * to the default value)
     **/
    ///@{
    void SetRecordtype(recordType_RECORDTYPE recordtype_) { m_recordtype = recordtype_; }
    recordType_RECORDTYPE GetRecordtype() const { return m_recordtype; }
    bool HasRecordtype() const;
    ///@}

private:
    /** --- **/
    recordType_RECORDTYPE m_recordtype;
};

//----------------------------------------------------------------------------
// InstRecordType
//----------------------------------------------------------------------------

/**
 * Instantiable version of AttRecordType
 */

class InstRecordType : public AttRecordType {
public:
    InstRecordType() = default;
    virtual ~InstRecordType() = default;
};

//----------------------------------------------------------------------------
// AttRegularMethod
//----------------------------------------------------------------------------

class AttRegularMethod : public Att {
protected:
    AttRegularMethod();
    ~AttRegularMethod() = default;

public:
    /** Reset the default values for the attribute class **/
    void ResetRegularMethod();

    /** Read the values for the attribute class **/
    bool ReadRegularMethod(pugi::xml_node element, bool removeAttr = true);

    /** Write the values for the attribute class **/
    bool WriteRegularMethod(pugi::xml_node element);

    /**
     * @name Setters, getters and presence checker for class members.
     * The checker returns true if the attribute class is set (e.g., not equal
     * to the default value)
     **/
    ///@{
    void SetMethod(regularMethod_METHOD method_) { m_method = method_; }
    regularMethod_METHOD GetMethod() const { return m_method; }
    bool HasMethod() const;
    ///@}

private:
    /** Indicates the method employed to mark corrections and normalizations. **/
    regularMethod_METHOD m_method;
};

//----------------------------------------------------------------------------
// InstRegularMethod
//----------------------------------------------------------------------------

/**
 * Instantiable version of AttRegularMethod
 */

class InstRegularMethod : public AttRegularMethod {
public:
    InstRegularMethod() = default;
    virtual ~InstRegularMethod() = default;
};

} // namespace vrv

#endif // __LIBMEI_ATTS_HEADER_H__
