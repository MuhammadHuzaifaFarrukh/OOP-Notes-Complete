#pragma once
#include <string>
#include <iostream>
#include "Department.h"

using namespace std;

class University 
{
    string UniName;
    Department *departments;
    int deptCount = 0;
    int totalDepts = 0 ;
    public:
    University();
    University(string);
    void addDepartment(const Department &d);
    void ShowUniversity();
    ~University();
};