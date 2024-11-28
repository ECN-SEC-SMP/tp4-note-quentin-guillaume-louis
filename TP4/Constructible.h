#pragma once

#include <string.h>
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
    /**
     * @brief Default constructor.
     *
     * Allows the creation of derived class objects.
     */
    Constructible() = default;


    Constructible(int num, std::string prop, Polygone<T> forme) : Parcelle<T>(num, prop, forme) {};

    /**
     * @brief Pure virtual method to compute the constructible surface area.
     *
     * Derived classes must implement this method to provide the surface
     * area of the constructible zone.
     *
     * @return The surface area of the constructible zone as type T.
     */
    virtual T surfaceConstructible() = 0;

    /**
     * @brief Pure virtual method to retrieve the type of the zone.
     *
     * Derived classes must implement this method to specify the type
     * of zone as a string.
     *
     * @return A string representing the type of the zone.
     */
    virtual std::string typeZone() const = 0;
};
