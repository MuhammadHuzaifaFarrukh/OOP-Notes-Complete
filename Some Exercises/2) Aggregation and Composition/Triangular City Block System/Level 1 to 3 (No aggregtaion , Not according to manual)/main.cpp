#include <iostream>
#include "Location.h"
#include "Road.h"
#include "CityBlock.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand((unsigned)time(nullptr));

    Location L1("Mall", 1, 2);
    Location L2("School", 20, 40);
    Location L3("Hospital", 100, 50);
    
    CityBlock city(L1, L2, L3);
    cout<<city;
    cout << endl;
    cout << "Perimeter: " << city.getPerimeter() << endl;
    cout << endl;

    city.renameLocation('A', "Super Mall");

    city.ScaleCoordinates(2.0);
    cout << endl;

    city.RoadLengths();
    cout << city << endl;
    cout << "Perimeter: " << city.getPerimeter() << endl;

    return 0;
}  
