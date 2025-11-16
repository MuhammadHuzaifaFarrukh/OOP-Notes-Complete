#pragma once
#include <iostream>

class Point
{
    int x, y;
public:
    Point(int x = 0, int y = 0);
    friend ostream& operator << (ostream& out, const Point&p);
};






