
#pragma once
#include <iostream>

using namespace std;

class Date
{
    int day, month, year;

public:
    Date();
    void SetDay(int d);
    void SetMonth(int m);
    void SetYear(int y);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void displayDate();
    void addDays(int days);
    void subtractDays(int days);
};
