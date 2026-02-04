#pragma once
#include <iostream>
#include <string>
using namespace std;

class Entry
{
    string title, description;

public:
    Entry();
    Entry(string t, string d);
    void showproject();
    void showeducation();
    string gettitle();
    string getdescription();
};