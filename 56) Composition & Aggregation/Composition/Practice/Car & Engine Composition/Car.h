#pragma once
#include <string>
#include "Engine.h"
using namespace std;

class Car
{
    Engine E;
    string brand;

public:
    Car(string, int, string);
    void ShowCar();
    
};