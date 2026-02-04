#include <iostream>
#include <vector>
#include "GateScanner.h"
using namespace std;

void GateScanner::setScannerData(int failed, int age)
{
    if(failed >=0)
    {
        failedattempts = failed;
    }
    if(age >=0 )
    {
        deviceage = age;
    }
}
void GateScanner::showinfo()
{
    cout<<"Gate Scanner : ";
    SecurityDevice::showinfo();
    cout<<"Failed Attempts : "<<failedattempts<<endl;
    cout<<"Device Age : "<<deviceage<<" Months "<<endl;
}
int GateScanner::riskScore(int signals)
{
    int risk = 0;
    if(failedattempts == 0)
    {
        risk = 1;
    }
    else
    {
        risk = failedattempts*8;
    }
    if(deviceage > 24)
    {
        risk +=15;
    }
    return risk;
}
