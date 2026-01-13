#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer
{
    public:
    string name;
    int purchaseAmount;

    Customer();

    Customer(string n , int a);
    
    bool operator==(const Customer &other) const;
};
