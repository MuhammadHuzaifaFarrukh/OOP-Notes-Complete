#include <iostream>
#include <string>
#include "global.h"
#include "CityBlock.h"
#include "Road.h"
#include "Location.h"
using namespace std;

// If CB is const then .getName() should also be const too
ostream &operator<<(ostream &out, const CityBlock &CB)
{
    out << "City Block Details : \n";
    out << "Location A : " << " From " << CB.A.getName() << " to " << CB.B.getName() << endl;
    out << "Road Length 1" << CB.R1 << endl;
    out << "Location B : " << " From " << CB.B.getName() << " to " << CB.C.getName() << endl;
    out << "Road Length 2" << CB.R2 << endl;
    out << "Location C : " << " From " << CB.C.getName() << " to " << CB.A.getName() << endl;
    out << "Road Length 3" << CB.R3 << endl;
    return out;
}
// If L is const then .getName() should also be const too
ostream &operator<<(ostream &out, const Location &L)
{
    out << "Location : " << L.name << endl;
    return out;
}

// If R is const then .getName() should also be const too
ostream &operator<<(ostream &out, const Road &R)
{
    out << "\n";
    out << "Road" << "  from " << R.start->getName() << " -> " << R.end->getName() << " Length :  " << R.length << " km";
    return out;
}