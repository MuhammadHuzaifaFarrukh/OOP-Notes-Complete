#include <iostream>
#include <vector>
#include "PatrolBot.h"
using namespace std;

void PatrolBot::setBotData(int events, int spots, int battery, bool night )
{
    if(events >= 0)
    {
        motionevents = events;
    }
    if(spots >=0 )
    {
        blindspots = spots;
    }
    if(battery >= 0)
    {
        batterylevel = battery;
    }
    if(night)
    {
        nightmode = night;
    }
}

void PatrolBot::showinfo()
{
    cout<<"Patrol Bot : ";
    SecurityDevice::showinfo();
    cout<<"Battery Level : "<<batterylevel<<" % "<<endl;
    cout<<"Night Mode Status (ON/OFF) : "<<nightmode<<endl;
    cout<<"Events : "<<motionevents<<" BlindSpots : "<<blindspots<<endl;
}
int PatrolBot::riskScore(int signals )
{
    int risk = AICamera::riskScore(motionevents);
    if(batterylevel < 20)
    {
        risk += 30;
    }
    if(nightmode)
    {
        risk = risk *1.5;
    }
    return risk;
}
