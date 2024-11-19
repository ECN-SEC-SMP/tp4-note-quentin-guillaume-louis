#pragma once

#include <vector>
#include "Point2D.h"

/**
 * @class Polygone
 * @brief A template class for representing a polygon in 2D space.
 *
 * This class provides functionalities to manage and manipulate a polygon composed of 2D points.
 * The template parameter `T` specifies the data type of the coordinates.
 *
 * @tparam T The type of the coordinates of the polygon's vertices.
 */
template<typename T>
class Polygone
{
public:
    /**
     * @brief Default constructor.
     *
     * Constructs an empty polygon.
     */
    Polygone();

    /**
     * @brief Constructor with a list of vertices.
     *
     * Constructs a polygon with the given list of vertices.
     *
     * @param listeSommets A vector of Point2D objects representing the vertices of the polygon.
     */
    Polygone(std::vector<Point2D<T>> listeSommets);

    /**
     * @brief Copy constructor.
     *
     * Constructs a polygon as a copy of another polygon.
     *
     * @param poly The polygon to copy.
     */
    Polygone(const Polygone<T>& poly);

    /**
     * @brief Gets the vertices of the polygon.
     *
     * @return A vector of Point2D objects representing the vertices of the polygon.
     */
    std::vector<Point2D<T>> getSommets() const;

    /**
     * @brief Sets the vertices of the polygon.
     *
     * Replaces the current vertices with the provided list of vertices.
     *
     * @param listeSommets A vector of Point2D objects representing the new vertices of the polygon.
     */
    void setSommets(std::vector<Point2D<T>> listeSommets);

    /**
     * @brief Adds a point to the polygon.
     *
     * Adds a new vertex to the polygon.
     *
     * @param point A Point2D object representing the new vertex to add.
     */
    void addPoint(Point2D<T> point);

    /**
     * @brief Translates the polygon by the specified offsets.
     *
     * Moves all vertices of the polygon by the given x and y offsets.
     *
     * @param x The offset to add to the x-coordinate of each vertex.
     * @param y The offset to add to the y-coordinate of each vertex.
     */
    void translate(T x, T y);

private:
    /**
     * @brief The vertices of the polygon.
     *
     * A vector of Point2D objects representing the vertices of the polygon.
     */
    std::vector<Point2D<T>> sommets;
};

template<typename T>
Polygone<T>::Polygone()
{
    this->sommets = {};
}

template<typename T>
Polygone<T>::Polygone(std::vector<Point2D<T>> listeSommets)
{
    this->sommets = listeSommets;
}

template<typename T>
Polygone<T>::Polygone(const Polygone<T>& poly)
{
    this->sommets = poly.getSommets();
}

template<typename T>
std::vector<Point2D<T>> Polygone<T>::getSommets() const
{
    return this->sommets;
}

template<typename T>
void Polygone<T>::setSommets(std::vector<Point2D<T>> listeSommets)
{
    this->sommets = listeSommets;
}

template<typename T>
void Polygone<T>::addPoint(Point2D<T> point)
{
    this->sommets.push_back(point);
}

template<typename T>
void Polygone<T>::translate(T x, T y)
{
    for (Point2D<T>& sommet : sommets)
    {
        sommet.translate(x, y);
    }
}
