#pragma once
#include <iostream>
#include "Employee.h"
#include <string>
using namespace std;

Employee ::Employee()
{
    name = "";
    salary = 0;
}

Employee ::Employee(string n, int s)
{
    name = n;
    salary = (s >= 0) ? s : 0;
}

bool Employee ::operator<(const Employee &other) const
{
    return salary < other.salary;
}
