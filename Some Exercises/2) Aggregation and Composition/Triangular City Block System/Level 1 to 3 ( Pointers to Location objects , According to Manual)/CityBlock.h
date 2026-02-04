#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Road.h"
using namespace std;

class CityBlock
{
    Location A, B, C;
    Road R1, R2, R3;

public:
    CityBlock(Location &L1, Location &L2, Location &L3);
    friend ostream &operator<<(ostream &out, const CityBlock &CB);

    double getPerimeter() const;
    ~CityBlock();

    void renameLocation(char loc, const string &newName);
    void ScaleCoordinates(double factor);
    void RoadLengths();
};
