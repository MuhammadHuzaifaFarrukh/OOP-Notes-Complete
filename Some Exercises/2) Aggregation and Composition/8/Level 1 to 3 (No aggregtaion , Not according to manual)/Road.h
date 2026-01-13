#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Location.h"
using namespace std;

class Road
{
    Location start;
    Location end;
    double length;

public:
    Road(const Location &s, const Location &e) : start(s), end(e)
    {
        double dx = s.getX() - e.getX();
        double dy = s.getY() - e.getY();
        length = sqrt(dx * dx + dy * dy);
        cout << "Creating Road from " << s.getName() << " -> " << e.getName()
             << " (Length: " << fixed << setprecision(2) << length << " km)" << endl;
    }

    double getLength(const Location &L1, const Location &L2) const
    {
        return sqrt((L2.getX() - L1.getX()) * (L2.getX() - L1.getX()) + (L2.getY() - L1.getY()) * (L2.getY() - L1.getY()));
    }
    Location &getStart()  { return start; }
    Location &getEnd()  { return end; }

    // CONST versions — for reading only (this fixes your error!)
    const Location& getStart() const { return start; }
    const Location& getEnd()   const { return end; }
    void setLength(double length)
    {
        this->length = length;
    }

    ~Road()
    {
        cout << "Road from " << start.getName() << " -> " << end.getName() << " destroyed!" << endl;
    }

    friend ostream &operator<<(ostream &os, const Road &r)
    {
        os << "Road from " << r.start.getName() << " -> " << r.end.getName()
           << " (Length: " << fixed << setprecision(2) << r.length << " km)";
        return os;
    }
};