
#include <iostream>
#include "Car.h"
#include "Engine.h"

using namespace std;

Car ::Car(string brand, int hp, string tp)
{
    this->brand = brand;
    Engine temp(hp , tp);
    E = temp;   //Won't work if there is some dynamic allocation , and no custom copy assignment operator
}
/*
Car::Car(string b, int hp, string t) : brand(b), E(hp, t) //This also works instead of above , by using member initialization list
{
}
*/
void Car::ShowCar()
{
    cout<<"Car Brand : "<<brand<<endl;
    E.ShowEngine();
}