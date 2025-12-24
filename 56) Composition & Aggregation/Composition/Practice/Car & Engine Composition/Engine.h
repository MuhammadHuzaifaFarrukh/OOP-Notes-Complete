#pragma once    
#include <string>
using namespace std;

class Engine
{
    int horsepower;
    string type;

    public:
    Engine();
    Engine(int , string);
    void ShowEngine();

};