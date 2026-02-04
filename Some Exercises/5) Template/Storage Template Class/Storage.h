#pragma once
#include <iostream>
#include <string>
/*
#include "Product.h"
#include "Customer.h"
#include "Employee.h"
The user defined data types which we want to instantiate in the Storage class should be in Storage.h , though it will still work without being in
Storage.h as these are alread in main.cpp
*/
using namespace std;

template <class T, class S>
class Storage
{
    T a1[1000];
    S a2[1000];
    int i;

public:
    Storage();

    void add(T a, S b);

    void update(T a, S b);

    S &get(T a);
    bool exists(T a);

    void remove(T a);

    T &minkey();

    void printall();
};