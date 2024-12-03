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
class ZA : public Constructible<T> 
{
public:
    /**
     * @brief Default constructor is deleted.
     */
    ZA() = delete;

    /**
     * @brief Constructs a ZA object with a given parcelle.
     * @param p A reference to a Parcelle object.
     */
    ZA(int num, std::string prop, Polygone<T> forme, const std::string typeCulture = "champs vide");

    /**
     * @brief Calculates the constructible surface of the zone.
     * @return The surface area of the zone as type T.
     */
    virtual T surfaceConstructible() override;
    void setSurfaceConstruite(const T& surfaceConstructible);

    /**
     * @brief Retrieves the type of the zone.
     * @return A string representing the type of zone ("Zone A Urbaniser").
     */
    std::string getTypeCulture() const;

    virtual void affiche(std::ostream& os) override {
        os << "Parcelle Numero: " << this->getNumero() << "\n";
        os << "Type: " << this->getType() << "\n";
        os << "Polygone: " << "\n";
        os << "Proprietaire: " << this->getProprietaire() << "\n";
        os << "Surface: " << (int)this->getSurface() << " m²\n";
        os << "Type Culture: " << this->typeDeCulture_ << "\n";
    }

protected:
    
    std::string typeDeCulture_;
    T surfaceConstruite_;
};

/**
 * @brief Constructs a ZA object and associates it with a Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @param p A reference to a Parcelle object.
 */
template<typename T>
ZA<T>::ZA(int num, std::string prop, Polygone<T> forme, const std::string typeCulture) : Constructible<T>(num, prop, forme)
{
    typeDeCulture_ = typeCulture;
    this->setType("ZA");
}

/**
 * @brief Computes the constructible surface based on the associated Parcelle.
 * @tparam T The type used to represent the surface of the constructible area.
 * @return The surface area of the associated Parcelle.
 */
template<typename T>
T ZA<T>::surfaceConstructible() {

    // 10% of the ZA est constructible
    T zaConstructible = this->getSurface() * (10/100);

    // If the result is higher than 200m², return 0
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
std::string ZA<T>::getTypeCulture() const {
    return this->typeDeCulture_;
}


template<typename T>
void ZA<T>::setSurfaceConstruite(const T& surfaceConstructible) {
    surfaceConstruite_ = surfaceConstructible;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, ZA<T>& obj) {
    obj.affiche(os);

    return os;
}
