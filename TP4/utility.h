#pragma once
#include "Point2D.h"
#include "Parcelle.h"
float Calcul_surface(const Polygone<int>& form);
std::vector<std::pair<int, int>> extractCoordinates(const std::string& input);
