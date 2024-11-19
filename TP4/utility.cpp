#include <vector>
#include "utility.h"

float Calcul_surface(const Parcelle &surface)
{
    std::vector<Point2D<float>> points;
    points = surface.getForme().getSommets();
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