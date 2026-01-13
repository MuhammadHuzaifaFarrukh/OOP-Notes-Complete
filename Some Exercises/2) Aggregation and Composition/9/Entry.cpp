#include <iostream>
#include <utility>
#include <vector>
#include "Entry.h"
using namespace std;

Entry::Entry() {}
Entry::Entry(string t, string d) : title(t), description(d) {}
void Entry::showproject()
{
    cout << "Project Details : " << endl;
    cout << "\tTitle : " << title << endl;
    cout << "\tDescription : " << description << endl;
}
void Entry::showeducation()
{
    cout << "Education Details : " << endl;
    cout << "\tTitle : " << title << endl;
    cout << "\tDescription : " << description << endl;
}
string Entry::gettitle() { return title; }
string Entry::getdescription() { return description; }
