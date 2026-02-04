#pragma once
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

// Default Constructor
// Incase Coordinates are not provided
Location::Location(string n ) : name(n)
{
    x = rand() % 101;
    y = rand() % 101;
    cout << endl;
}
// Parameterized Constructor
// Coordinates are provided
Location::Location(string n, double x_c, double y_c) : name(n)
{
    cout << endl;
    if (x_c >= 0 && x_c <= 100)
    {
        x = x_c;
    }
    else
    {
        x = rand() % 101;
    }
    if (y_c >= 0 && y_c <= 100)
    {
        y = y_c;
    }
    else
    {
        y = rand() % 101;
    }
}
// Not Required / Asked in the Question
Location::Location(double x_c, double y_c)
{
    name = "Unknown";
    if (x_c >= 0 && x_c <= 100)
    {
        x = x_c;
    }
    else
    {
        x = rand() % 101;
    }
}

double Location::getX() const { return x; }
double Location::getY() const { return y; }
string Location::getName() const { return name; }
void Location::SetX(double x_c)
{
    if (x_c >= 0)
    {
        x = x_c;
    }
}
void Location::SetY(double y_c)
{
    if (y_c >= 0)
    {
        y = y_c;
    }
}
void Location::setName(string n)
{
    name = n;
}
Location::~Location()
{
    cout << "Location " << name << "  Destroyed !" << endl;
}