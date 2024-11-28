#pragma once
#include "Point2D.h"
#include "Parcelle.h"
float Calcul_surface(const Polygone<int>& form);

template<typename T>
std::vector<Point2D<T>> extractCoordinates(const std::string& input);
