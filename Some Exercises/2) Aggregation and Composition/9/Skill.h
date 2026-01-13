#pragma once
#include <iostream>

using namespace std;

class Skill
{
    string name;
    int rating;

public:
    Skill();
    Skill(string n, int r);
    void show();
    string getname();
    int getrating();
};
