#pragma once
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
class Experience
{
    pair<string, string> job;

public:
    Experience();
    Experience(string jt, string jd);
    void show();
    string getjobtitle();
    string getjobdescription();
};