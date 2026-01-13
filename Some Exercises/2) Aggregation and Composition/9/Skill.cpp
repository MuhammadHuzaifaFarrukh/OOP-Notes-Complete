#include <iostream>
#include <string>
#include "Skill.h"
using namespace std;
Skill::Skill() {}
Skill::Skill(string n, int r)
{
    name = n;
    rating = r;
}
void Skill::show()
{
    cout << "Skill Details : " << endl;
    cout << "\tName : " << name << endl;
    cout << "\tRating : " << rating << endl;
}
string Skill::getname() { return name; }
int Skill::getrating() { return rating; }