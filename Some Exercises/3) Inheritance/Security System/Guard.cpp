#include <iostream>
#include <vector>
#include "Guard.h"
using namespace std;

void Guard::showinfo()
{
    cout<<"Guard on Duty : ";
    SecurityDevice::showinfo();
    cout<<"Patrol Hours : "<<patrolhours<<endl;
    cout<<"Reports Filed : "<<reportfiled<<endl;
}
int Guard::riskScore(int signals )
{
    if(patrolhours > 6 && reportfiled > 0 )
    {
        return (reportfiled*5);
    }
    else if(patrolhours < 3)
    {
        int risk = 20;
        return risk;
    }
    else
    {
        return (reportfiled *2);
    }
}
void Guard::assignData(int hours, int reports )
{
    if(hours >= 0)
    {
        patrolhours = hours;
    }
    if(reports >=0)
    {
        reportfiled = reports;
    }
}