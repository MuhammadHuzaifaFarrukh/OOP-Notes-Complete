#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Location.h"

using namespace std;
 
class Road
{
    Location *start;
    Location *end;
    double length;

public:
    Road(Location *L1, Location *L2);

    // If R is const then .getName() should also be const too
    friend ostream &operator<<(ostream &out, const Road &R);
    

    double getLength(const Location &L1, const Location &L2) const;

    /*
    // The Below functions are not required as we are using pointers to location objects in Road
    // If we used normal objects then this function would be required
    // And we would also need to update the start and end locations in the cityblock class also whenever the length is changed
    // As we made Locations A,B,C in Cityblock as normal objects so they were different than the ones in Road Class
    // When we changed the Location A,B,C names in Cityblock or scaled their coordinates , the changes were not reflected in Road class Locations
    Location &getStartLocation() { return start; }
    Location &getEndLocation() { return end; }
    */
    void setLength(double length);
    ~Road();
};
