#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
//#include "Student.h" //Not allowed , to prevent this even if accidentally included multiple times a header , you should use #pragma once in that  header file

//Compile by command with both files , 3.cpp and Student.cpp
//If not then , include Student.cpp in this file and then run only this file    
using namespace std;

int main()
{
    // Create Student Object
    Student s1("Alice", 5);
    s1.Init();

    // Add Courses
    s1.add_course("CS101", 4, "NIL", 0);
    s1.add_course("MA101", 3, 1);
    s1.add_course("PH101", 3, "NIL", 2);

    // Show Student Details
    s1.show();

    // Total Credit Hours
    cout << "Total Credit Hours: " << s1.total_credit_hours() << endl;

    // Create another Student Object
    Student s2 = s1; // Using Copy Constructor
    s2.show();

    // Compare Students
    if (s1.compare(s2))
    {
        cout << "Students have the same courses." << endl;
    }
    else
    {
        cout << "Students have different courses." << endl;
    }

    return 0;
}