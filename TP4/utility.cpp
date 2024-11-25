#include "utility.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 

float Calcul_surface(const Polygone<int>& form)
{
    std::vector<Point2D<int>> points;
    points = form.getSommets();
    unsigned int vector_size = points.size();
    int x_current = points[0].getX();                   
    int y_current = points[0].getY();
    int x_future = 0;
    int y_future = 0;
    float result = (-x_current*y_current)/2;                //premier point - seulement du négatif
    for(unsigned int i = 0; i < (vector_size-1); i++)       // -1 pour éviter un overflow
    {
        x_future = points[i+1].getX();                      //on récupère les points futurs
        y_future = points[i+1].getY();

        result += (x_current*y_future - x_future*y_current); //formule donnée 

        x_current = x_future;                               //on réassigne pour évitere de lire deux fois le même point
        y_current = y_future;
    }
    result = result/2;                                      //division finale par deux - donc uniquement X.0 ou X.5 - un float est-il vraiment utile? 

    return result;

}


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
