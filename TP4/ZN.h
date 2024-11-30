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
     * @brief Returns the constructible surface area for the zone.
     *
     * @return The constructible surface area, which is always 0 for ZN.
     */
    virtual T surfaceConstructible() override;
    /**
     * @brief Sets the constructible surface area.
     *
     * @param surfaceConstructible New constructible surface area.
     */

    virtual void affiche(std::ostream& os) override {
        os << "Parcelle Numero: " << this->getNumero() << "\n";
        os << "Type: " << this->getType() << "\n";
        os << "Polygone: " << "\n";
        os << "Proprietaire: " << this->getProprietaire() << "\n";
        os << "Surface: " << this->getSurface() << " m²\n";
    }

protected:
    T surfaceConstruite_; ///< Constructible surface area.
};

template<typename T>
ZN<T>::ZN(int num, std::string prop, Polygone<T> forme) : Constructible<T>(num, prop, forme)
{
    this->setType("ZN");
}

template<typename T>
T ZN<T>::surfaceConstructible()
{
    return (T)0;
}
