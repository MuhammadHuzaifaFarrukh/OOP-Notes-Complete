#include <iostream>
#include "Department.h"
#include "University.h"
#include "Course.h"
#include "Department.cpp"
#include "University.cpp"
#include "Course.cpp"
#include <string>
using namespace std;

int main()
{
    University uni("National University");
    Department cs("Computer Science");
    cs.addCourse(Course("Data Structures", "CS201"));
    cs.addCourse(Course("Operating Systems", "CS301"));
    Department ee("Electrical Engineering");
    ee.addCourse(Course("Circuits", "EE101"));
    ee.addCourse(Course("Electromagnetics", "EE202"));
    uni.addDepartment(cs);
    uni.addDepartment(ee);
    uni.ShowUniversity();
    return 0;
}