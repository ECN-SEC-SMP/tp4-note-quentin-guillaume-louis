#pragma once

#include <string>
#include <iostream>
#include "Parcelle.h"  // Assurez-vous d'inclure Parcelle.h

/**
 * @class Constructible
 * @brief Abstract base class for defining constructible zones.
 *
 * This class provides an interface for determining the surface area of
 * a constructible zone and retrieving its type. It is meant to be
 * derived by classes that specify concrete zone types.
 *
 * @tparam T The type used to represent the surface area (e.g., int, float).
 */
template<typename T>
class Constructible : public Parcelle<T>
{
public:
    /**
     * @brief Default constructor.
     *
     * Allows the creation of derived class objects.
     */
    Constructible() = default;

    Constructible(int num, std::string prop, Polygone<T> forme);

    /**
     * @brief Pure virtual method to compute the constructible surface area.
     *
     * Derived classes must implement this method to provide the surface
     * area of the constructible zone.
     *
     * @return The surface area of the constructible zone as type T.
     */
    virtual T surfaceConstructible() = 0;  // Méthode virtuelle pure

};

// Définition du constructeur dans le fichier source (si nécessaire)
template<typename T>
Constructible<T>::Constructible(int num, std::string prop, Polygone<T> forme) {    
    this->Parcelle<T>(num, prop, forme);
}
