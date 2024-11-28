#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Parcelle.h"
#include "Polygone.h"
#include "Parcelle.h"
#include "utility.h"

template<typename T>
class Carte
{
public:
    Carte(const std::istringstream& input);
    std::istringstream getOutputFile();
private:
    std::vector<Parcelle<T>> listeParcelles;
    float surfaceTotale;
};

template<typename T>
Carte<T>::Carte(const std::istringstream& input) //considère un fichier bien formé 
{
    const int maxLenght = 4096; // une longueur maximale par ligne qui devrait être largement suffisante


    std::string line;

    input.getline(line, maxLenght);
    bool loop = !line.empty();

    while (loop == 1)
    {
        std::istringstream streamLine(line);
        std::string TypeParcelle;
        int numeroParcelle;
        std::string nomParcelle;
        T pConstructible;
        T surfaceConstruite;
        std::string typeCulture;

        streamLine >> TypeParcelle;
        streamLine >> numeroParcelle;
        streamLine >> proprio;


        switch (TypeParcelle) //récupération du type de parcelle 
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
        loop = !line.empty();
    }
}

template<typename T>
std::istringstream Carte<T>::getOutputFile()
{
    int nombreParcelles = this->listeParcelles.size();
    for (int i = 0; i < nombreParcelles; i++)
    {
        std::istringstream resultat;
        std::string TypeParcelle this->llisteParcelles[i].getType();
        int numeroParcelle = this->llisteParcelles[i].getNumero();
        sdt::string proprio = this->llisteParcelles[i].getProprietaire();

        resultat << TypeParcelle << " " << numeroParcelle << " " << proprio; // notes communes à chaque type de parcelles

        T pConstructible;
        T surfaceConstruite;
        std::string typeCulture;


        switch (TypeParcelle)
        {
        case "ZU":
            pConstructible = this->listeParcelles[i].surfaceConstructible;
            surfaceConstruite = 0;///rajouter surface construite
            resultat << " " << pConstructible << " " << surfaceConstruite;
            break;
        case "ZAU":
            pConstructible = this->listeParcelles[i].surfaceConstructible;
            resultat << " " << pConstructible;

            break;
        case "ZA":
            typeCulture = "truc"//rajouter  culture
                resultat << " " << typeCulture;
            break;
        case "ZN":
            break;
        default:
            //faire une erreur
        }
        resultat << "\n";
        std::vector<Point2D<int>> listePoints = this->listeParcelles[i].getForme().getSommets(); //dans forme, le type int est spécifié
        int nombrePoints = listePoints.size(); //nombre de point du polygone de la parcelle
        for (int j = 0; j < nombrePoints; j++)
        {
            resultat << "[";
            resultat << listePoints.getX();
            resultat << ";";
            resultat << listePoints.getY();
            resultat << "]" << " ";
        }
        resultat << "\n";

    }
    return resultat;
}