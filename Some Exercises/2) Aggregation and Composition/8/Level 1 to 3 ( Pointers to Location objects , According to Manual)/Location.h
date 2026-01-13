#pragma once
#include <iostream>
#include <string>

using namespace std;

class Location
{
    double x, y;
    string name;

public:
    // Default Constructor
    // Incase Coordinates are not provided
    Location(string n = "Unknown");
    // Parameterized Constructor
    // Coordinates are provided
    Location(string n, double x_c, double y_c);
    
    // Not Required / Asked in the Question
    Location(double x_c, double y_c);

    double getX() const;
    double getY() const ;
    string getName() const;
    void SetX(double x_c);
    void SetY(double y_c);
    void setName(string n);
    friend ostream &operator<<(ostream &out, const Location &L);

    ~Location();
};
