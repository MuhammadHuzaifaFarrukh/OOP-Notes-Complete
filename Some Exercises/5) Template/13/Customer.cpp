#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

Customer ::Customer()
{
    name = "";
    purchaseAmount = 0;
}

Customer ::Customer(string n, int a)
{
    name = n; // assign properly
    purchaseAmount = (a >= 0) ? a : 0;
}

bool Customer ::operator==(const Customer &other) const
{
    return name == other.name;
}
