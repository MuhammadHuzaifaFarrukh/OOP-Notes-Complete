#pragma once
#include <string>
#include <iostream>
#include "Component.h"

using namespace std;
class Computer
{
    string brand;
    Component *components;
    int componentCount = 0;
    int totalComponents = 0;
    public:
    Computer();
    Computer(string);
    ~Computer();
    void addComponent(const Component& comp);
    void ShowComputer();    
};