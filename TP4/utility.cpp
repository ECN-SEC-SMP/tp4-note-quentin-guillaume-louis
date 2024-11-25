#include "utility.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

std::vector<std::pair<int, int>> extractCoordinates(const std::string& input) {
    std::vector<std::pair<int, int>> coordinates;
    size_t start = 0, end;
    while ((start = input.find('[', start)) != std::string::npos) {
    
        end = input.find(']', start);
        
        if (end == std::string::npos) break;  //entrée foirée - pas de fermeture
        
        
        std::string pairStr = input.substr(start + 1, end - start - 1); //supprime les []

        std::istringstream pairStream(pairStr);//version du string avec plus de fonctions - dont la conversion vers des entiers directement
        int x, y;
        char semicolon;  // sert à supprimer le ;
        if (pairStream >> x >> semicolon >> y) { //utilisation du istringstream - conversion en entier
            coordinates.push_back({x, y});	//coordonées 
        }

        start = end + 1;	//décale le prochain démarrage
    }
    return coordinates;
}
