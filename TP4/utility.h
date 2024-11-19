#pragma once
#include "Point2D.h"
#include "Parcelle.h"
float Calcul_surface(const Parcelle &surface);
std::vector<std::pair<int, int>> extractCoordinates(const std::string& input);
