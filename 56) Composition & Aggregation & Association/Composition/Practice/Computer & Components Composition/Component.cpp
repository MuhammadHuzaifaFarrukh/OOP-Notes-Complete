#include <iostream>
#include "Component.h"
#include <string>
using namespace std;

Component :: Component()
{
    name = "";
    capacity = "";
}
Component :: Component(string n, string c)
{
    name = n;
    capacity = c;
}

void Component::ShowComponent()
{
    cout << name << endl;
    cout <<" , "  << capacity << endl;
}