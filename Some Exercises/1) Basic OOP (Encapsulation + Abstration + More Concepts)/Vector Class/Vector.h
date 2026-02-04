#pragma once
#include <iostream>

using namespace std;

class Vector
{
    int *arr;
    int size, capacity;

public:
    Vector();
    ~Vector();
    void PUSH_BACK(int x);
    void POP_BACK();
    int get(int ind);
    void set(int i, int x);
    int SIZE();
    bool isEmpty();
    int minElement();
    int maxElement();
    void display();
    void expand();
};