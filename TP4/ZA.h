#pragma once

#include "Constructible.h"

/**
 * @class ZA
 * @brief Represents a constructible zone classified as "Zone A Urbaniser".
 *
 * This class derives from the template class Constructible<T> and provides
 * specific implementations for constructible zone calculations and type identification.
 *
 * @tparam T The type used to represent the surface of the constructible area (e.g., int, float).
 */
template<typename T>
class ZA : public Constructible<T> {
public:
    /**
     * @brief Default constructor is deleted.
     */
    ZA() = delete;

    /**
     * @brief Constructs a ZA object with a given parcelle.
     * @param p A reference to a Parcelle object.
     */
    ZA(const Parcelle& p, const std::string typeCulture = "champs vide");

    /**
     * @brief Calculates the constructible surface of the zone.
     * @return The surface area of the zone as type T.
     */
    T surfaceConstructible() override;
    void setSurfaceConstruite(const T& surfaceConstructible);

    /**
     * @brief Retrieves the type of the zone.
     * @return A string representing the type of zone ("Zone A Urbaniser").
     */
    static std::string typeZone() override;
    std::string getTypeCulture() const;

protected:
    Parcelle* parcelle_; /**< Pointer to a Parcelle object representing the zone's parcel. */
    std::string typeDeCulture_;
    T surfaceConstruite_;
};

/**
 * @brief Constructs a ZA object and associates it with a Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @param p A reference to a Parcelle object.
 */
template<typename T>
ZA<T>::ZA(const Parcelle<T>& p, const std::string typeCulture)
{
    parcelle_ = &p;
    typeDeCulture_ = typeCulture;
}

/**
 * @brief Computes the constructible surface based on the associated Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @return The surface area of the associated Parcelle.
 */
template<typename T>
T ZA<T>::surfaceConstructible() {

    // 10% of the ZA est constructible
    T zaConstructible = parcelle_->getSurface() * (10/100);

    // If the result is higher than 200m�, return 0
    if(zaConstructible > 200)
    {
        return (T)0;
    }

    return zaConstructible;
}

/**
 * @brief Retrieves the type of the zone as a static string.
 * @tparam T The type used to represent the surface of the constructible area.
 * @return A string representing the type of zone ("Zone A Urbaniser").
 */
template<typename T>
std::string ZA<T>::typeZone() {
    return std::string("Zones Agricoles");
}

template<typename T>
std::string ZA<T>::getTypeCulture() const {
    return this->typeDeCulture_;
}


template<typename T>
void ZA<T>::setSurfaceConstruite(const T& surfaceConstructible) {
    surfaceConstruite_ = surfaceConstructible;
}