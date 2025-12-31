#include <iostream>
#include <string>
#include "Department.h"

using namespace std;

Department :: Department()
{
    DeptName = "";
    courseCount = 0;
    totalCourses = 5;
    courses = new Course[totalCourses];
}

Department :: Department(string name)
{
    DeptName = name;
    courseCount = 0;
    totalCourses = 5;
    courses = new Course[totalCourses];
}

void Department :: addCourse(const Course &c)
{
    if(courseCount == totalCourses)
    {
        totalCourses *= 2;
        Course *newCourses = new Course[totalCourses];
        for(int i = 0; i < courseCount; i++)
        {
            newCourses[i] = courses[i];
        }
        delete [] courses;
        courses = newCourses;
    }
    courses[courseCount++] = c;
}

void Department :: ShowDeparment()
{
    cout << "Department : " << DeptName << endl;
    for(int i = 0; i < courseCount; i++)
    {
        courses[i].showCourse();
    }
}
Department :: ~Department()
{
    delete [] courses;
}