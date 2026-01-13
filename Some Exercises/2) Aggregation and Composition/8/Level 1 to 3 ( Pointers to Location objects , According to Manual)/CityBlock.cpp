#include <iostream>
#include <string>
#include "CityBlock.h"
using namespace std;

CityBlock::CityBlock(Location &L1, Location &L2, Location &L3) : A(L1), B(L2), C(L3), R1(&A, &B), R2(&B, &C), R3(&C, &A)
{
    cout << endl;
}

double CityBlock::getPerimeter() const
{
    return (R1.getLength(A, B) + R2.getLength(B, C) + R3.getLength(C, A));
}
CityBlock::~CityBlock()
{
    cout << endl
         << endl;
    cout << "City Block Destroyed !" << endl;
}

void CityBlock::renameLocation(char loc, const string &newName)
{
    if (loc == 'A')
    {
        A.setName(newName);
        // R1.getStartLocation().setName(newName); // If we had used normal objects instead of pointers in Road class
        // R1.getEndLocation().setName(newName);   // If we had used normal objects instead of pointers in Road class
    }
    else if (loc == 'B')
    {
        B.setName(newName);
        // R2.getStartLocation().setName(newName); // If we had used normal objects instead of pointers in Road class
        // R2.getEndLocation().setName(newName);   // If we had used normal objects instead of pointers in Road class3
    }
    else if (loc == 'C')
    {
        C.setName(newName);
        // R3.getStartLocation().setName(newName); // If we had used normal objects instead of pointers in Road class
        // R3.getEndLocation().setName(newName);   // If we had used normal objects instead of pointers in Road class
    }
    else
    {
        cout << "Invalid Location " << endl;
    }
}

void CityBlock::ScaleCoordinates(double factor)
{
    A.SetX(A.getX() * factor);
    B.SetX(B.getX() * factor);
    C.SetX(C.getX() * factor);
    A.SetY(A.getY() * factor);
    B.SetY(B.getY() * factor);
    C.SetY(C.getY() * factor);

    /*
    R1.getStartLocation().SetX(A.getX());
    R1.getStartLocation().SetY(A.getY());
    R1.getEndLocation().SetX(B.getX());
    R1.getEndLocation().SetY(B.getY());
    R2.getStartLocation().SetX(B.getX());
    R2.getStartLocation().SetY(B.getY());
    R2.getEndLocation().SetX(C.getX());
    R2.getEndLocation().SetY(C.getY());
    R3.getStartLocation().SetX(C.getX());
    R3.getStartLocation().SetY(C.getY());
    R3.getEndLocation().SetX(A.getX());
    R3.getEndLocation().SetY(A.getY());*/

    R1.setLength(R1.getLength(A, B));
    R2.setLength(R2.getLength(B, C));
    R3.setLength(R3.getLength(C, A));
}

void CityBlock::RoadLengths()
{
    cout << "R1 : " << R1.getLength(A, B) << " km " << endl;
    cout << "R2 : " << R2.getLength(B, C) << " km " << endl;
    cout << "R3 : " << R3.getLength(C, A) << " km " << endl;
}