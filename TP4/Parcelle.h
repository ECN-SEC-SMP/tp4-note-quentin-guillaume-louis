#pragma once
#include <string>
#include "Polygone.h"
#include <iostream>
#include "utility.h"

/**
 * @class Parcelle
 * @brief Represents a land parcel with specific properties and a polygonal shape.
 */
template<typename T>
class Parcelle
{
public:
    /**
     * @brief Copy constructor for Parcelle.
     * @param parc The Parcelle object to copy.
     */
    Parcelle(const Parcelle<T>& parc);

    /**
     * @brief Constructs a Parcelle with specified properties.
     * @param num The unique identifier for the parcel.
     * @param prop The owner of the parcel.
     * @param forme The polygon representing the shape of the parcel.
     */
    Parcelle(int num, std::string prop, Polygone<T> forme);

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
    void setForme(const Polygone<T>& form);

    /**
     * @brief Sets the type of the parcel. This is a pure virtual function.
     * @param type The new type of the parcel.
     */
    void setType(const std::string& type);

    /**
     * @brief Outputs the Parcelle object to the provided output stream.
     * @param os The output stream.
     * @param parcelle The Parcelle object to output.
     * @return A reference to the output stream.
     */
    virtual void affiche(std::ostream& os) {
        os << "classe Parcelle";
    };

protected:
    std::string _type;             /**< The type of the parcel. */
    int _numero;                   /**< The unique identifier of the parcel. */
    std::string _proprietaire;     /**< The owner of the parcel. */
    T _surface;                /**< The surface area of the parcel. */
    Polygone<T> _forme;          /**< The polygonal shape of the parcel. */
    int _pConstructible;           /**< Indicates constructibility status (e.g., 0 = not constructible). */
};



template<typename T>
Parcelle<T>::Parcelle(const Parcelle<T>& parc)
{
    this->_surface = parc.getSurface();
    this->_type = parc.getType();
    this->_numero = parc.getNumero();
    this->_forme = parc.getForme();
    this->_proprietaire = parc.getProprietaire();
    this->_pConstructible = 0;
}

template<typename T>
Parcelle<T>::Parcelle(int num, std::string prop, Polygone<T> forme) : _forme(forme), _proprietaire(prop), _numero(num)
{
    this->_pConstructible = 0;
    setForme(_forme);
}

template<typename T>
int Parcelle<T>::getNumero() const
{
    return this->_numero;
}

template<typename T>
std::string Parcelle<T>::getProprietaire() const
{
    return this->_proprietaire;
}

template<typename T>
std::string Parcelle<T>::getType() const
{
    return this->_type;
}

template<typename T>
float Parcelle<T>::getSurface() const
{
    return this->_surface;
}

template<typename T>
Polygone<int> Parcelle<T>::getForme() const
{
    return this->_forme;
}

template<typename T>
void Parcelle<T>::setNumero(int n)
{
    this->_numero = n;
}

template<typename T>
void Parcelle<T>::setProprietaire(const std::string& prop)
{
    this->_proprietaire = prop;
}

template<typename T>
void Parcelle<T>::setForme(const Polygone<T>& form)
{
    this->_forme = form;
    std::vector<Point2D<T>> points = form.getSommets();
    unsigned int vector_size = points.size();

    T result = 0;

    // On boucle sur les sommets, en fermant le polygone (relier dernier au premier)
    for (unsigned int i = 0; i < vector_size; ++i) {
        // Les coordonnées du point courant
        T x_current = points[i].getX();
        T y_current = points[i].getY();

        // Le prochain point (en fermant le polygone)
        T x_next = points[(i + 1) % vector_size].getX();
        T y_next = points[(i + 1) % vector_size].getY();

        // Ajout de la contribution de ce segment à l'aire
        result += x_current * y_next - x_next * y_current;
    }

    this->_surface = std::abs(result) / 2;  // Aire positive
    
}

template<typename T>
void Parcelle<T>::setType(const std::string& type) {
    this->_type = type;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Parcelle<T>& parcelle) {
    parcelle->affiche(os);

    return os;
}
