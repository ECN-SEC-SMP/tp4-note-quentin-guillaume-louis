#pragma once
#include <string>
#include "Polygone.h"
#include <iostream>
/**
 * @class Parcelle
 * @brief Represents a land parcel with specific properties and a polygonal shape.
 */
class Parcelle
{
public:
    /**
     * @brief Copy constructor for Parcelle.
     * @param parc The Parcelle object to copy.
     */
    Parcelle(const Parcelle& parc);

    /**
     * @brief Constructs a Parcelle with specified properties.
     * @param num The unique identifier for the parcel.
     * @param prop The owner of the parcel.
     * @param forme The polygon representing the shape of the parcel.
     */
    Parcelle(int num, std::string prop, Polygone<int> forme);

    /**
     * @brief Gets the unique identifier of the parcel.
     * @return The parcel number.
     */
    int getNumero() const;

    /**
     * @brief Gets the owner of the parcel.
     * @return The name of the owner.
     */
    std::string getProprietaire() const;

    /**
     * @brief Gets the type of the parcel.
     * @return The type as a string.
     */
    std::string getType() const;

    /**
     * @brief Gets the surface area of the parcel.
     * @return The surface area as a float.
     */
    float getSurface() const;

    /**
     * @brief Gets the polygonal shape of the parcel.
     * @return The Polygone object representing the shape.
     */
    Polygone<int> getForme() const;

    /**
     * @brief Sets the unique identifier of the parcel.
     * @param n The new parcel number.
     */
    void setNumero(int n);

    /**
     * @brief Sets the owner of the parcel.
     * @param prop The new owner name.
     */
    void setProprietaire(const std::string& prop);

    /**
     * @brief Sets the polygonal shape of the parcel.
     * @param form The new polygon representing the shape.
     */
    void setForme(const Polygone<int>& form);

    /**
     * @brief Sets the type of the parcel. This is a pure virtual function.
     * @param type The new type of the parcel.
     */
    virtual void setType(const std::string& type) = 0;

    /**
     * @brief Outputs the Parcelle object to the provided output stream.
     * @param os The output stream.
     * @param parcelle The Parcelle object to output.
     * @return A reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Parcelle& parcelle);

private:
    std::string _type;             /**< The type of the parcel. */
    int _numero;                   /**< The unique identifier of the parcel. */
    std::string _proprietaire;     /**< The owner of the parcel. */
    float _surface;                /**< The surface area of the parcel. */
    Polygone<int> _forme;          /**< The polygonal shape of the parcel. */
    int _pConstructible;           /**< Indicates constructibility status (e.g., 0 = not constructible). */
};
