#pragma once

#include <string>
#include <iostream>
#include "Parcelle.h"

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
    
    Constructible() = default;

    Constructible(int num, std::string prop, Polygone<T> forme);

    
    virtual T surfaceConstructible() = 0;

    virtual void affiche(std::ostream& os) override {
        os << "classe Construction";
    };
};

// D�finition du constructeur dans le fichier source (si n�cessaire)
template<typename T>
Constructible<T>::Constructible(int num, std::string prop, Polygone<T> forme) : Parcelle<T>(num, prop, forme) {}
