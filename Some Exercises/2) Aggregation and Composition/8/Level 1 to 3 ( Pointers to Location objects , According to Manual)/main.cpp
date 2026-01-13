#include <iostream>
#include <string>
#include "Road.h"
#include "Location.h"
#include "CityBlock.h"
#include "Road.cpp"
#include "Location.cpp"
#include "CityBlock.cpp"
#include "global.cpp"
#include "global.h"
#include <ctime>
#include <cstdlib>
   
using namespace std;

int main()
{
    srand((unsigned)time(0));   // Seed for random number generation
    Location L1("Mall" , 1,2) ; 
    Location L2("School" , 20,40) ;
    Location L3("Hospital" , 100,50);
    CityBlock city(L1,L2,L3);
    cout<<endl; 
    cout<<"Perimeter : "<<city.getPerimeter();
    cout<<endl;
    city.renameLocation('A' , "Super Mall");
    
    city.ScaleCoordinates(2.0);
    cout<<endl;
    
    city.RoadLengths();
    cout<<city<<endl;
    cout<<"Perimeter : "<<city.getPerimeter();

    return 0;
}