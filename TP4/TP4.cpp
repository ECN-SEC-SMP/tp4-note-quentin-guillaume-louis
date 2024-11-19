#include <iostream>
#include <cassert>
#include <vector>
#include "Point2D.h"
#include "Polygone.h"

int main()
{
    // Step 1: Create test points
    Point2D<float> TestPoint = Point2D<float>(5, 6);
    Point2D<float> TestPoint2 = Point2D<float>(7, 9);
    Point2D<float> TestPoint3 = Point2D<float>(10, 11);

    // Assertions for point initialization
    assert(TestPoint.getX() == 5.0f && TestPoint.getY() == 6.0f);
    assert(TestPoint2.getX() == 7.0f && TestPoint2.getY() == 9.0f);

    // Step 2: Create a list of points
    std::vector<Point2D<float>> liste = { TestPoint, TestPoint2 };

    // Step 3: Initialize a polygon with the list of points
    Polygone<float> PolyTest = Polygone<float>(liste);

    // Assertions for polygon initialization
    assert(PolyTest.getSommets().size() == 2);
    assert(PolyTest.getSommets()[0].getX() == 5.0f && PolyTest.getSommets()[0].getY() == 6.0f);
    assert(PolyTest.getSommets()[1].getX() == 7.0f && PolyTest.getSommets()[1].getY() == 9.0f);

    // Step 4: Copy the polygon
    Polygone<float> PolyTest2 = Polygone<float>(PolyTest);

    // Assertions for polygon copy
    assert(PolyTest2.getSommets().size() == 2);
    assert(PolyTest2.getSommets()[0].getX() == 5.0f && PolyTest2.getSommets()[0].getY() == 6.0f);
    assert(PolyTest2.getSommets()[1].getX() == 7.0f && PolyTest2.getSommets()[1].getY() == 9.0f);

    // Step 5: Add a new point to the copied polygon
    PolyTest2.addPoint(TestPoint3);

    // Assertions for adding a point
    assert(PolyTest2.getSommets().size() == 3);
    assert(PolyTest2.getSommets()[2].getX() == 10.0f && PolyTest2.getSommets()[2].getY() == 11.0f);

    // Step 6: Translate the copied polygon
    PolyTest2.translate(10, 10);

    // Assertions for translation
    assert(PolyTest2.getSommets()[0].getX() == 15.0f && PolyTest2.getSommets()[0].getY() == 16.0f);
    assert(PolyTest2.getSommets()[1].getX() == 17.0f && PolyTest2.getSommets()[1].getY() == 19.0f);
    assert(PolyTest2.getSommets()[2].getX() == 20.0f && PolyTest2.getSommets()[2].getY() == 21.0f);

    // Step 7: Print a success message
    std::cout << "All tests passed successfully!\n";

    return 0;
}
