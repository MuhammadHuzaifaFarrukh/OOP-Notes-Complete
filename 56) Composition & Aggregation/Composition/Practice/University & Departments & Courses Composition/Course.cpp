#include <string>
#include <iostream>
#include "Course.h"

using namespace std;
Course::Course()
{
    title = "";
    code = "";
}

Course::Course(string t, string c)
{
    title = t;
    code = c;
}
void Course::showCourse()
{
    cout << title <<" Course "<< " , Code : "<< code << endl;
}