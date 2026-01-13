#include <iostream>
#include <string>
#include "Road.h"
#include "Location.h"
using namespace std;

Road::Road(Location *L1, Location *L2) : start(L1), end(L2)
{
    cout << endl;
    length = sqrt((L2->getX() - L1->getX()) * (L2->getX() - L1->getX()) + (L2->getY() - L1->getY()) * (L2->getY() - L1->getY()));
}

double Road::getLength(const Location &L1, const Location &L2) const
{
    return sqrt((L2.getX() - L1.getX()) * (L2.getX() - L1.getX()) + (L2.getY() - L1.getY()) * (L2.getY() - L1.getY()));
}

/*
// The Below functions are not required as we are using pointers to location objects in Road
// If we used normal objects then this function would be required
// And we would also need to update the start and end locations in the cityblock class also whenever the length is changed
// As we made Locations A,B,C in Cityblock as normal objects so they were different than the ones in Road Class
// When we changed the Location A,B,C names in Cityblock or scaled their coordinates , the changes were not reflected in Road class Locations
Location &getStartLocation() { return start; }
Location &getEndLocation() { return end; }
*/
void Road::setLength(double length)
{
    this->length = length;
}
Road::~Road()
{
    cout << "Road" << "  from " << start->getName() << " -> " << end->getName() << " destroyed !";
    cout << endl;
}