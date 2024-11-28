#pragma once
#include "Constructible.h"

/**
 * @class ZAU
 * @brief Represents a constructible zone classified as "Zone A Urbaniser".
 *
 * This class derives from the template class Constructible<T> and provides
 * specific implementations for constructible zone calculations and type identification.
 *
 * @tparam T The type used to represent the surface of the constructible area (e.g., int, float).
 */
template<typename T>
class ZAU : public Constructible<T> {
public:
    /**
     * @brief Default constructor is deleted.
     */
    ZAU() = delete;

    /**
     * @brief Constructs a ZAU object with a given parcelle.
     * @param p A reference to a Parcelle object.
     */
    ZAU(const Parcelle& p);

    /**
     * @brief Calculates the constructible surface of the zone.
     * @return The surface area of the zone as type T.
     */
    T surfaceConstructible() override;

    /**
     * @brief Retrieves the type of the zone.
     * @return A string representing the type of zone ("Zone A Urbaniser").
     */
    static std::string typeZone() override;

protected:
    Parcelle* parcelle_; /**< Pointer to a Parcelle object representing the zone's parcel. */
};

/**
 * @brief Constructs a ZAU object and associates it with a Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @param p A reference to a Parcelle object.
 */
template<typename T>
ZAU<T>::ZAU(const Parcelle<T>& p)
{
    parcelle_ = &p;
}

/**
 * @brief Computes the constructible surface based on the associated Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @return The surface area of the associated Parcelle.
 */
template<typename T>
T ZAU<T>::surfaceConstructible() {
    return parcelle_->getSurface();
}

/**
 * @brief Retrieves the type of the zone as a static string.
 * @tparam T The type used to represent the surface of the constructible area.
 * @return A string representing the type of zone ("Zone A Urbaniser").
 */
template<typename T>
std::string ZAU<T>::typeZone() {
    return std::string("Zone A Urbaniser");
}
