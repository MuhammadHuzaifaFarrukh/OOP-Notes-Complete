#pragma once
#include <string>

using namespace std;

//#pragma once to avoid multiple inclusions of the same header file
//No Need for header files other than necessary ones
//Only Function Declarations and Class Declaration
class Student
{
private:
    string studentName;
    int courseCount;
    string *courseCode;
    int *credithours;
    string *preReqCode;
    int actual_Course = 0;

public:
    // 1) Parameterized Constructor
    Student(string name, int code);

    // 2) Initialization : (Set all values to default , empty or zero)
    void Init();

    // 3) Copy Constructor Helper :
    void copy_from(const Student &s);

    // 3) Copy Constructor
    Student(const Student &s);

    // 4) Copy Assignment Operator (Operator Overloading)

    Student &operator=(const Student &s);

    // 5) Destructor Helper :
    void cleanup();
    // 5) Destructor
    ~Student();

    // 6,7,8) Add Course Helper :
    void course_add_helper(string code, int crhrs, string prereq, int index);

    // 6) Add Course Overloading Functions : (2 Parameters)
    void add_course(string code, int index);

    // 7) Add Course Overloading Functions : (3 Parameters)
    void add_course(string code, int crhrs, int index);

    // 8) Add Course Overloading Functions : (4 Parameters)

    void add_course(string code, int crhrs, string prereq, int index);

    // 9) Remove Course
    void remove_course(int index);

    // 10) Total Credit Hours

    int total_credit_hours();

    // 11) Show Details
    void show();

    // 12) Compare Students with their Courses
    bool compare(Student &s);
};