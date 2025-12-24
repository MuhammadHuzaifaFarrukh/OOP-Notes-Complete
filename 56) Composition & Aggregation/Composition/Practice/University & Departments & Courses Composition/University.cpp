#include <iostream>
#include "Department.h"
#include "University.h"

using namespace std;

University :: University()
{
    totalDepts = 5;
    departments = new Department[totalDepts];
    UniName = "";
    deptCount = 0;
}

University :: University(string name)
{
    totalDepts = 5;
    departments = new Department[totalDepts];
    UniName = name;
    deptCount = 0;
}

University :: ~University()
{
    delete[] departments;
}

void University :: addDepartment(const Department &d)
{
    if(deptCount == totalDepts)
    {
        totalDepts +=1;
        Department *temp = new Department[totalDepts];
        for(int i = 0; i < deptCount; i++)
        {
            temp[i] = departments[i];
        }
        delete[] departments;
        departments = temp;
    }
    departments[deptCount++] = d;
}
void University :: ShowUniversity()
{
    cout<<"University Name: "<<UniName<<endl;
    for(int i = 0; i < deptCount; i++)
    {
        departments[i].ShowDeparment();
    }
}