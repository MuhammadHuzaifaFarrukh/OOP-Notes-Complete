#pragma once
#include <string>
#include <iostream>

using namespace std;
class Component
{
    string name;
    string capacity;

public:
    Component();
    Component(string, string);
    void ShowComponent();
};