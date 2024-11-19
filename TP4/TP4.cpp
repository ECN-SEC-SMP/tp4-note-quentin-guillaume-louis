// TP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point2D.h"
#include "Polygone.h"
int main()
{
    Point2D<float> TestPoint = Point2D<float>(5,6);
    Point2D<float> TestPoint2 = Point2D<float>(7, 9);
    Point2D<float> TestPoint3 = Point2D<float>(10,11);
    std::vector<Point2D<float>> liste = { TestPoint, TestPoint2 };
    Polygone<float> PolyTest = Polygone<float>(liste);
    Polygone<float> PolyTest2 = Polygone<float>(PolyTest);
    PolyTest2.addPoint(TestPoint3);
    PolyTest2.translate(10, 10);
    std::cout << "Hello World!\n";
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
