#include <iostream>
#include <vector>
#include "AICamera.h"
using namespace std;

void AICamera::setCameraData(int events, int spots)
{
    if(events >=0)
    {
        motionevents = events;
    }
    if(spots >=0)
    {
        blindspots = spots;
    }
}
void AICamera::showinfo()
{
    cout<<"AI Camera : ";
    SecurityDevice::showinfo();
    cout<<"Motion Events : "<<motionevents<<endl;
    cout<<"Blind Spots : "<<blindspots<<endl;
}
int AICamera::riskScore(int signals)
{
    int risk = motionevents*2 + blindspots*10;
    if(blindspots > 3 )
    {
        risk +=25;
    }
    if (motionevents == 0)
    {
        risk = 0;
    }
    return risk;
}
