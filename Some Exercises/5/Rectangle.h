#pragma once
#include <iostream>
#include <string>

using namespace std;

class Rect
{
private:
    double x,y, width, height;
    void copy_from(const Rect &);

public:
    Rect();
    Rect(double, double, double, double);
    void scale(double, double );
    void move(double, double);
    void display();

    bool operator==(const Rect &);
    bool operator>=(const Rect &);
    bool operator<=(const Rect &);
    bool operator<(const Rect &);
    bool operator>(const Rect &);
    bool operator&(const Rect &);

    Rect(const Rect &);
    Rect& operator=(const Rect &);

};
