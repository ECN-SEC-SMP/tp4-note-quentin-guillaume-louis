#include "Carte.h"
#include "Polygone.h"
#include "Parcelle.h"
#include 'utility.h'
Carte<T>::Carte(std::istringstream& input) //considère un fichier bien formé 
{
    const int maxLenght = 4096; // une longueur maximale par ligne qui devrait être largement suffisante


    std::string line ;

    input.getline(line, maxLenght);
    bool loop = ! line.empty();

    while(loop == 1)
    {
    std::istringstream streamLine(line);
    std::string TYpeParcelle;
    int numeroParcelle;
    std::string nomParcelle;
    T pConstructible;
    T surfaceConstruite;
    std::string typeCulture;

    streamLine >> TYpeParcelle;
    streamLine >> numeroParcelle;
    streamLine >> proprio;


    switch(TypeParcelle) //récupération du type de parcelle 
    {
        case "ZU":
            streamLine >> pConstructible;
            streamLine >> surfaceConstruite;
            //création ZU - en attente du reste des fichiers
        break;
        case "ZAU":
            streamLine >> pConstructible;
            //création ZAU - en attente du reste des fichiers
        break;
        case "ZA":
            streamLine >> typeCulture;
            //création ZA - en attente du reste des fichiers
        break;
        case "ZN": 
            //création ZN - en attente du reste des fichiers
        break;
        default:
        //faire une erreur
    }
    input.getline(line, maxLenght);
    std::vector<Point2D<T>> listePoints = extractCoordinates(line);
    Polygone polygoneParcelle(listePoints);
    //attribuer le bolygone à la parcelle


    input.getline(line, maxLenght); // nouvelle ligne de définition de parcelle
    loop = ! line.empty();
    }
    


}
