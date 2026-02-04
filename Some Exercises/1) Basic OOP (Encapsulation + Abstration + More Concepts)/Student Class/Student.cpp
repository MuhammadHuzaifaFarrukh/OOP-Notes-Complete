#include <string> 
#include <iostream>
#include "Student.h"

//In implementation file , we include header files that are necessary
using namespace std;

// 1) Parameterized Constructor
Student::Student(string name, int code)
{
    studentName = name;
    courseCount = code;
    courseCode = new string[code];
    credithours = new int[code];
    preReqCode = new string[code];
}

// 2) Initialization : (Set all values to default , empty or zero)
void Student ::Init()
{
    for (int i = 0; i < courseCount; i++)
    {
        courseCode[i] = "";
        credithours[i] = 0;
        preReqCode[i] = "";
    }
}

// 3) Copy Constructor Helper :
void Student::copy_from(const Student &s) // We can use either void or Student & return type , but don't do return type Student only as it will call copy constructor when returning object and cause recursion as it keeps calling copy constructor again and again
{
    // Above it should be a const in paramter as our object coming from outside is also const
    studentName = s.studentName;
    courseCount = s.courseCount;

    courseCode = new string[courseCount];
    credithours = new int[courseCount];
    preReqCode = new string[courseCount];
    actual_Course = s.actual_Course;

    for (int i = 0; i < courseCount; i++)
    {
        courseCode[i] = s.courseCode[i];
        credithours[i] = s.credithours[i];
        preReqCode[i] = s.preReqCode[i];
    }
}

// 3) Copy Constructor
Student::Student(const Student &s)
{
    copy_from(s);
}

// 4) Copy Assignment Operator (Operator Overloading)

Student &Student::operator=(const Student &s)
{
    cleanup();
    if (this != &s)
    {
        copy_from(s);
    }
    return (*this);
}

// 5) Destructor Helper :
void Student::cleanup()
{
    delete[] courseCode;
    delete[] credithours;
    delete[] preReqCode;
}

// 5) Destructor
Student ::~Student()
{
    cleanup();
}

// 6,7,8) Add Course Helper :
void Student::course_add_helper(string code, int crhrs, string prereq, int index)
{
    if (index >= 0 && index < courseCount)
    {
        courseCode[index] = code;
        credithours[index] = crhrs;
        preReqCode[index] = prereq;
        actual_Course++;
        cout << "Course added successfully " << endl;
    }
    else
    {
        cout << "Invalid Index , Cannot add course " << endl;
    }
}

// 6) Add Course Overloading Functions : (2 Parameters)
void Student::add_course(string code, int index)
{
    course_add_helper(code, 3, "NIL", index);
}

// 7) Add Course Overloading Functions : (3 Parameters)
void Student::add_course(string code, int crhrs, int index)
{
    add_course(code, crhrs, "NIL", index);
}

// 8) Add Course Overloading Functions : (4 Parameters)

void Student::add_course(string code, int crhrs, string prereq, int index)
{
    course_add_helper(code, crhrs, prereq, index);
}

// 9) Remove Course
void Student::remove_course(int index)
{
    if ((index >= 0 && index < courseCount))
    {
        courseCode[index] = "NIL";
        credithours[index] = 0;
        preReqCode[index] = "NIL";
        actual_Course--;
        cout << "Course removed successfully " << endl;
    }
    else
    {
        cout << "Invalid Index , Cannot remove course " << endl;
    }
}

// 10) Total Credit Hours

int Student::total_credit_hours()
{
    int count = 0;
    for (int i = 0; i < courseCount; i++)
    {
        if (credithours[i] != 0)
        {
            count += credithours[i];
        }
    }
    return count;
}

// 11) Show Details
void Student::show()
{
    cout << "Student Name : " << studentName << endl;
    cout << "Total Courses Enrolled : " << actual_Course << endl;

    for (int i = 0; i < courseCount; i++)
    {
        cout << endl
             << endl;

        if (courseCode[i] != "" && courseCode[i] != "NIL")
        {
            cout << "Course Details : " << endl;
            cout << "Course Code : " << courseCode[i] << endl;
            cout << "Credit Hours : " << credithours[i] << endl;
            cout << "Prerequisite : " << preReqCode[i] << endl;
        }
    }
    cout << endl
         << endl;
}

// 12) Compare Students with their Courses
bool Student::compare(Student &s)
{

    if (actual_Course != s.actual_Course)
    {
        return false;
    }

    int match = 0;
    for (int i = 0; i < courseCount; i++)
    {
        for (int j = 0; j < s.courseCount; j++)
        {
            if (courseCode[i] == s.courseCode[j] && courseCode[i] != "" && courseCode[i] != "NIL")
            {
                match++;
            }
        }
    }

    return (match == actual_Course);
}
