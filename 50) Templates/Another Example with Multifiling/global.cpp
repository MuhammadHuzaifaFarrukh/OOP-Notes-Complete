#include <iostream>
#include "global.h"
using namespace std;

ostream& operator << (ostream& out, const Point&p)
{
    out << p.x << '\t' << p.y << '\n';
    return out;
}
