#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Location
{
    double x, y;
    string name;

public:
    Location(string n = "Unknown") : name(n)
    {
        x = rand() % 101;
        y = rand() % 101;
        cout << "Creating Location \"" << name << "\" at (" << x << ", " << y << ")" << endl;
    }

    Location(string n, double xx, double yy) : name(n)
    {
        x = (xx >= 0 && xx <= 100) ? xx : rand() % 101;
        y = (yy >= 0 && yy <= 100) ? yy : rand() % 101;
        cout << "Creating Location \"" << name << "\" at (" << x << ", " << y << ")" << endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    string getName() const { return name; }
    void SetX(double v)
    {
        if (v >= 0)
            x = v;
    }
    void SetY(double v)
    {
        if (v >= 0)
            y = v;
    }
    void setName(const string &n) { name = n; }

    ~Location()
    {
        cout << "Location \"" << name << "\" destroyed!" << endl;
    }

    friend ostream &operator<<(ostream &os, const Location &l)
    {
        os << l.name << " @ (" << l.x << ", " << l.y << ")";
        return os;
    }
};