#pragma once
#include <iostream>

using namespace std;

class Product
{
    public:
    string name;
    int quantity;

    Product();

    Product(string n , int q);
    bool operator<(const Product &other) const;
};