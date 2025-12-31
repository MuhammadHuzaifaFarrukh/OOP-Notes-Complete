#pragma once
#include <string>
#include <iostream>

using namespace std;

class Course
{
    string title;
    string code;
    public:
    Course();
    Course(string t , string c);
    void showCourse();
};