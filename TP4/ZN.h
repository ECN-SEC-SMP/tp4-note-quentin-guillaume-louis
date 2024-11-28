#pragma once

#include "Constructible.h"

/**
 * @class ZN
 * @brief Template class representing a "Zone Naturelle."
 *
 * This class defines a natural zone with a constructible surface area.
 * It is derived from the Constructible interface, providing specialized behavior.
 *
 * @tparam T Type representing the surface (e.g., int, float, double).
 */
template<typename T>
class ZN : public Constructible<T>
{
public:
    /**
     * @brief Deleted default constructor.
     */
    ZN() = delete;


    ZN(int num, std::string prop, Polygone<T> forme);

    /**
     * @brief Destructor.
     */
    ~ZN();

    /**
     * @brief Returns the constructible surface area for the zone.
     *
     * @return The constructible surface area, which is always 0 for ZN.
     */
    T surfaceConstructible() override;

    /**
     * @brief Sets the constructible surface area.
     *
     * @param surfaceConstructible New constructible surface area.
     */
    void setSurfaceConstruite(const T& surfaceConstructible) const;

    /**
     * @brief Retrieves the type of zone.
     *
     * @return A string representing the type ("Zone Naturelle").
     */
    std::string typeZone() const override ;


    void setType(const std::string& type);

protected:
    Parcelle<T>* parcelle_; ///< Pointer to the associated parcel.
    T surfaceConstruite_; ///< Constructible surface area.
};

template<typename T>
ZN<T>::ZN(int num, std::string prop, Polygone<T> forme) : Constructible<T>(num,prop,forme)
{
    parcelle_ = static_cast<Parcelle<T>*>(this);
    this->surfaceConstruite_ = 0;
}

template<typename T>
ZN<T>::~ZN()
{
    parcelle_ = nullptr;
}

template<typename T>
T ZN<T>::surfaceConstructible()
{
    return (T)0;
}

template<typename T>
void ZN<T>::setSurfaceConstruite(const T& surfaceConstructible) const
{
    throw std::runtime_error("Tried to set a built surface on a ZN");
}

template<typename T>
void ZN<T>::setSurfaceConstruite(const T& surfaceConstructible) const {
}

template<typename T>
void ZN<T>::setType(const std::string& type)
{
    //Fleme
}
