#include <string>
#include "Engine.h"
#include <iostream>
using namespace std;

Engine :: Engine()
{
    horsepower = 0;
    type = "";
}
Engine :: Engine(int hp , string tp)
{
    horsepower = hp;
    type = tp;
}

void Engine::ShowEngine()
{
    cout<<"Horsepower: "<<horsepower<< " , ";
    cout<<"Type: "<<type<<endl;
}