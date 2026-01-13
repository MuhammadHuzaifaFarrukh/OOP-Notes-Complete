#pragma once
#include <iostream>
#include <string>
#include "class.h"
#include "global.h"

using namespace std;

class Student;  //Forward Declaration

class Finance
{
private:
    static int count_ss;

    int StudentID;
    double totalfee;
    double paidfee;
    double remainingfee;
    bool scholarshipstatus;

public:
    //Finance();

    Finance(int, double, double);
    void displayfinance() const;

    friend void processcholarship(Student &, Finance &);
    friend void Summary(Student &, Finance &);
    friend void LoadFromFile();
    static int get_sc_count();
    ~Finance();
};



