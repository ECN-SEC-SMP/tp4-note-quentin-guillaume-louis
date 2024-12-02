// TP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Polygone.h"
#include "ZA.h"
#include "ZN.h"
#include "ZU.h"
#include "ZAU.h"



int main(void)
{
  // TEST DES CLASSES
	std::vector<Point2D<int>> tab[] = {
		{ Point2D<int>(0, 1)},   // Premier vecteur
		{ Point2D<int>(1, 2)},   // Deuxième vecteur
		{ Point2D<int>(2, 3)}
	};

	Polygone<int> pol(*tab);
	ZN<int> ZoneA(0, "Jean Yves", pol);
	ZA<int> ZoneB(0, "Jean Bernard", pol, "Courgettes");
	ZU<int> ZoneC(0, "Jean Pierre", pol);
	ZAU<int> ZoneD(0, "Jean Luc", pol);
	
	std::cout << ZoneA;
	std::cout << "\n----------------\n";
	std::cout << ZoneB;
	std::cout << "\n----------------\n";
	std::cout << ZoneC;
	std::cout << "\n----------------\n";
	std::cout << ZoneD;
	
	//ZA ZoneA<int>(0, "Jean-louis", pol, "champs vide");

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
