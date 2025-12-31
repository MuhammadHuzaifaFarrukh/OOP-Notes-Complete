#pragma once
#include "Course.h"
#include <string>
#include <iostream>

using namespace std;
class Department
{
    Course *courses;
    int courseCount = 0;
    string DeptName;
    int totalCourses = 0 ;

    public:
    Department();
    Department(string);
    void addCourse(const Course &c);
    void ShowDeparment();
    ~Department();
};