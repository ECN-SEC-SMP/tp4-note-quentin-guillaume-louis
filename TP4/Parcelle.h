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
    Parcelle(const Parcelle& parc);

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
    T _surface;                /**< The surface area of the parcel. */
    Polygone<T> _forme;          /**< The polygonal shape of the parcel. */
    int _pConstructible;           /**< Indicates constructibility status (e.g., 0 = not constructible). */

};



template<typename T>
Parcelle<T>::Parcelle(const Parcelle& parc)
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
    this->_surface = 0.0f;
    this->_forme = {};
    this->_pConstructible = 0;
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
    std::vector<Point2D<T>> points;
    points = form.getSommets();
    unsigned int vector_size = points.size();
    T x_current = points[0].getX();
    T y_current = points[0].getY();
    T x_future = 0;
    T y_future = 0;
    T result = 0.0;                //premier point - nul
    for (unsigned int i = 0; i < (vector_size - 1); i++)       // -1 pour éviter un overflow
    {
        x_future = points[i + 1].getX();                      //on récupère les points futurs
        y_future = points[i + 1].getY();

        result += (x_current * y_future - x_future * y_current); //formule donnée 

        x_current = x_future;                               //on réassigne pour évitere de lire deux fois le même point
        y_current = y_future;
    }
    this->_surface = result / 2;                                      //division finale par deux - donc uniquement X.0 ou X.5 - un float est-il vraiment utile? 

}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Parcelle<T>& parcelle) {
    os << "Parcelle Information:\n";
    os << "Type: " << parcelle.getType() << "\n";
    os << "Numero: " << parcelle.getNumero() << "\n";
    os << "Proprietaire: " << parcelle.getProprietaire() << "\n";
    os << "Surface: " << parcelle.getSurface() << " m²\n";
    //os << "Pourcentage Constructible: " << parcelle.getPConstructible() << "%\n";
    //os << "Forme: " << parcelle.getForme() << "\n"; // Assuming Polygone has operator<< overloaded
    return os;
}
