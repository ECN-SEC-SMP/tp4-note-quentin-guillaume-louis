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
    explicit ZAU(int num, std::string prop, Polygone<T> forme);

    T constructible() const;
    /**
     * @brief Calculates the constructible surface of the zone.
     * @return The surface area of the zone as type T.
     */
    T surfaceConstructible() override;
    void setSurfaceConstruite(const T& surfaceConstructible);
    virtual void affiche(std::ostream& os) override {
        os << "Parcelle Numero: " << this->getNumero() << "\n";
        os << "Type: " << this->getType() << "\n";
        os << "Polygone: " << "\n";
        os << "Proprietaire: " << this->getProprietaire() << "\n";
        os << "Surface: " << this->getSurface() << " m²\n";
        os << "% constructible: " << this->constructible() << " m²\n";
    }

protected:
    T surfaceConstruite_;
};

template<typename T>
ZAU<T>::ZAU(int num, std::string prop, Polygone<T> forme) : Constructible<T>(num, prop, forme)
{
    surfaceConstruite_ = 0;
    this->setType("ZAU");
}

template<typename T>
T ZAU<T>::surfaceConstructible() {
    return this->getSurface();
}

template<typename T>
void ZAU<T>::setSurfaceConstruite(const T& surfaceConstructible) {
    surfaceConstruite_ = surfaceConstructible;
}

template<typename T>
T ZAU<T>::constructible() const {
    return (1 - (surfaceConstruite_ / this->getSurface()));
}

template<typename T>
std::ostream& operator<<(std::ostream& os, ZAU<T>& obj) {
    obj.affiche(os);

    return os;
}
