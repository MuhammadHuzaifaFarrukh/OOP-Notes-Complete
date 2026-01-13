#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Road.h"
#include "Location.h"
using namespace std;

class CityBlock
{
    Road road1, road2, road3;

public:
    CityBlock(Location &L1, Location &L2, Location &L3)
        : road1(L1, L2), road2(L2, L3), road3(L3, L1)
    {
        cout << endl;
    }

    ~CityBlock()
    {
        cout << endl
             << "City Block Destroyed !" << endl;
    }

    void renameLocation(char loc, const string &newName)
    {
        if (loc == 'A')
        {
            road1.getStart().setName(newName);
            road3.getEnd().setName(newName);
        }
        else if (loc == 'B')
        {
            road1.getEnd().setName(newName);
            road2.getStart().setName(newName);
        }
        else if (loc == 'C')
        {
            road2.getEnd().setName(newName);
            road3.getStart().setName(newName);
        }
        else
        {
            cout << "Invalid Location" << endl;
        }
    }

    void ScaleCoordinates(double factor)
    {
        
        road1.getStart().SetX(road1.getStart().getX() * factor);
        road1.getStart().SetY(road1.getStart().getY() * factor);
        road1.getEnd().SetX(road1.getEnd().getX() * factor);
        road1.getEnd().SetY(road1.getEnd().getY() * factor);

        road2.getStart().SetX(road2.getStart().getX() * factor);
        road2.getStart().SetY(road2.getStart().getY() * factor);
        road2.getEnd().SetX(road2.getEnd().getX() * factor);
        road2.getEnd().SetY(road2.getEnd().getY() * factor);

        road3.getStart().SetX(road3.getStart().getX() * factor);
        road3.getStart().SetY(road3.getStart().getY() * factor);
        road3.getEnd().SetX(road3.getEnd().getX() * factor);
        road3.getEnd().SetY(road3.getEnd().getY() * factor);

        // Update road lengths after scaling
        road1.setLength(road1.getLength(road1.getStart(), road1.getEnd()));
        road2.setLength(road2.getLength(road2.getStart(), road2.getEnd()));
        road3.setLength(road3.getLength(road3.getStart(), road3.getEnd()));
    }

    void RoadLengths() const
    {
        cout << fixed << setprecision(2);
        cout << "R1: " << road1.getLength(road1.getStart() ,road1.getEnd()) << " km" << endl;
        cout << "R2: " << road2.getLength(road2.getStart() ,road2.getEnd()) << " km" << endl;
        cout << "R3: " << road3.getLength(road3.getStart() ,road3.getEnd()) << " km" << endl;
    }

    double getPerimeter() const
    {
        return road1.getLength(road1.getStart() ,road1.getEnd()) + 
        road2.getLength(road2.getStart() ,road2.getEnd())+
        road3.getLength(road3.getStart() ,road3.getEnd() );
    }

    friend ostream &operator<<(ostream &os, const CityBlock &cb)
    {
        os << "City Block Details:\n";
        os << "Road 1: " << cb.road1 << endl;
        os << "Road 2: " << cb.road2 << endl;
        os << "Road 3: " << cb.road3 << endl;
        return os;
    }
};