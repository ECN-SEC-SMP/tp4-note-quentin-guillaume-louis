#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Parcelle.h"

template<typename T>
class Carte
{
public:
    Carte(const std::istringstream& input);
private:
    std::vector<Parcelle<T>> listeParcelles;
    float surfaceTotale;
};

