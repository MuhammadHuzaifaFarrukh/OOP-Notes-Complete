#include <iostream>
#include <string>
#include "class.h"
#include "Finance.h"
#include "global.h"
#include <fstream>

using namespace std;

void processcholarship(Student & s, Finance &f)
{
    if(s.GPA >=3.5 && f.paidfee >=(0.8*f.totalfee ))
    {
        f.scholarshipstatus = true;
        cout<<"Scholarship Status Set"<<endl;
        Finance::count_ss++;
    }
    else
    {
        f.scholarshipstatus = false;
        cout<<"Scholarship Status Not Set"<<endl;
    }

    if(f.scholarshipstatus == 1 )
    {
        f.remainingfee = 0;
    }
    else
    {
        cout<<"Remaining Balance : "<<f.remainingfee<<endl;
    }
    ofstream out("records.txt", ios::app);
    out<<"[Student: "<<s.name<<" | GPA: "<<s.GPA<< " | Scholarship: ";
    if(f.scholarshipstatus == 1)
    {
        out<<" YES ";
    }
    else
    {
        out<<" NO ";
    }
    out<<" | Remaining Fee : "<<f.remainingfee<<"]"<<endl;
    out.close();
}

void Summary(Student & s, Finance &f)
{
    s.displayStudent();
    cout<<endl;
    f.displayfinance();
    cout<<endl;
}


ostream& operator <<(ostream&out, const Student &s)
{
    out<<"Student : " << s.name<< " | RollNo : "<<s.rollNo << " | Courses : "<<s.numCourses << " | GPA : "<<s.GPA <<endl;
    return out;
}

istream& operator >> (istream& in,  Student &s)
{
    cout<<"Enter student name : ";
    in>>s.name;
    cout<<"Enter Roll No : ";
    in>>s.rollNo;
    cout<<"Enter Number of Courses : ";
    in>>s.numCourses;

    int cols;
    if(s.numCourses>0)
    {
        s.marks = new double*[s.numCourses];

        for(int i = 0 ; i<s.numCourses ; i++)
        {
            cout<<"Enter the number of assignments for Row " <<i<<" : ";
            cin>>cols;
            s.marks[i] = new double[cols+1];
            s.marks[i][0] = cols;
        }
    }
    s.inputMarks();
//    cout<<"Enter Marks : ";
//
//    for(int i = 0 ; i<s.numCourses ; i++)
//    {
//        int cols = s.marks[i][0]+1;
//        for(int j = 1 ; j<cols; j++ )
//        {
//            int m;
//            cout<<"Enter marks : ";
//            in>>s.marks[i][j];
//            while(s.marks[i][j]<0)
//            {
//                cout<<"Invalid Marks , enter again "<<endl;
//                in>>s.marks[i][j];
//            }
//        }
//    }
    return in;
}


void LoadFromFile()
{
    string n;
    ifstream in("records.txt");
    if(!in)
    {
        cout<<"File doesnt exist "<<endl;
        return;
    }

    //int n1;

    string line;
    while(getline(in, line))
    {
        cout<<line<<endl;

    }
    in.close();
}
