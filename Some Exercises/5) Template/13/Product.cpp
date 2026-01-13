#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

Product ::Product()
{
    name = "";
    quantity = 0;
}

Product ::Product(string n, int q)
{
    name = n;
    quantity = (q >= 0) ? q : 0;
}

// Overload < operator for quantity comparison
bool Product ::operator<(const Product &other) const
{
    return quantity < other.quantity;
}
