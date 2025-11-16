#pragma once
#include <iostream>
/*
#include "Point.h"  //You may also use it like this if you want to instantiate
*/

using namespace std;

template <class T>
class Stack
{
    int size, p;
    T *x;
public:
    Stack(int s = 10);
    void push(T element);
    T top() const;
    void pop();
    ~Stack();
};
