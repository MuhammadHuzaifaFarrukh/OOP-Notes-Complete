#pragma once
#include <iostream>
#include <string>
#include "global.h"
#include "Finance.h"

using namespace std;

class Finance;

class Student
{
private:
    string name;
    int rollNo;
    int numCourses;
    double GPA;
    double **marks;


public:
    Student();
    Student(string, int, int);
    void inputMarks();
    void CalculateGPA();
    void updateMarks(int, int, double);
    void displayStudent()const;
    int getrollNo();

    friend void processcholarship(Student &, Finance &);
    friend void Summary(Student &, Finance &);

    friend ostream& operator <<(ostream&, const Student &);
    friend istream& operator >> (istream&, Student &);
    friend void LoadFromFile();
    bool operator>(const Student&);

    ~Student();
};

