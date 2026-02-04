#include <iostream>
#include <string>
#include "class.h"
#include "Finance.h"
#include "global.h"

using namespace std;

Student::Student()
{
    name = "";
    rollNo = 0;
    numCourses = 0;
    GPA = 0.0; // CRITICAL: Initialize GPA
    marks = nullptr; // CRITICAL: Initialize marks pointer
}

Student::Student(string n, int r, int num)
{
    name = n;
    if(r>=0)
    {
        rollNo = r;
    }

    int cols;
    if(num>0)
    {
        numCourses = num;
        marks = new double*[numCourses];

        for(int i = 0 ; i<numCourses ; i++)
        {
            cout<<"Enter the number of assignments for Row " <<i<<" : ";
            cin>>cols;
            marks[i] = new double[cols+1];
            marks[i][0] = cols;
        }
    }
    inputMarks();


}

void Student::inputMarks()
{
    for(int i = 0 ; i<numCourses ; i++)
    {
        int cols = marks[i][0]+1;
        for(int j = 1 ; j<cols; j++ )
        {
            int m;
            cout<<"Enter marks : ";
            cin>>marks[i][j];
            while(marks[i][j]<0)
            {
                cout<<"Invalid Marks , enter again "<<endl;
                cin>>marks[i][j];
            }
        }
    }

}

void Student::CalculateGPA()
{
    double sum = 0;
    int count_no = 0;
    for(int i = 0 ; i<numCourses ; i++)
    {
        int cols = marks[i][0]+1;
        for(int j = 1 ; j<cols ; j++)
        {
            sum += marks[i][j];
            count_no++;
        }
    }
    GPA = (double)( (double) sum / (double) count_no) /(20.0);
}

void Student::updateMarks(int courseind, int AssignInd, double newMarks)
{
    if(courseind>=0 && courseind <numCourses)
    {
        if(AssignInd > 0 && AssignInd<marks[courseind][0])
        {
            marks[courseind][AssignInd] = newMarks;
            cout<<"Marks update Successfully"<<endl;
            CalculateGPA();
        }
    }
    //CalculateGPA();
}

void Student::displayStudent()const
{
    cout<<"Student DATA : \n";
    cout<<"Name : "<<name<<endl;
    cout<<"Roll No : "<<rollNo<<endl;
    cout<<"Number of Courses : "<<numCourses<<endl;
    cout<<"Marks : "<<endl;
    for(int i = 0 ; i<numCourses ; i++)
    {
        for(int j = 1 ; j<marks[i][0]+1 ; j++)
        {
            cout<<"Marks of Row "<<i<<" Column : "<<j-1<<" :  "<<marks[i][j]<<endl;
        }
    }

    cout<<"GPA : "<<GPA<<endl;
    cout<<endl<<endl<<endl;

}

int Student::getrollNo()
{
    return rollNo;
}

//Will be called when dynamically allocated object is deleted
Student::~Student()
{
    for(int i = 0 ; i<numCourses ; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;
    marks = nullptr;
}


bool Student::operator>(const Student&other)
{
    if(GPA > other.GPA)
    {
        return 1;
    }
    return 0;
}
