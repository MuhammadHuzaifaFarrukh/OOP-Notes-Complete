#include <iostream>
#include "Car.h"
#include "Engine.h"
#include "Car.cpp"
#include "Engine.cpp"
using namespace std;

int main()
{
    Car c("Toyota", 180, "Hybrid");
    c.ShowCar();
    return 0;
}