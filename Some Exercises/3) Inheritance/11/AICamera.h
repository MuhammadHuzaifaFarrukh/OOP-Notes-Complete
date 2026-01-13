#pragma once
#include <iostream>
#include <vector>
#include "SecurityDevice.h"
using namespace std;

class AICamera : public SecurityDevice
{
protected :
    int motionevents;
    int blindspots;
public:
    void setCameraData(int events = 0, int spots = 0);
    void showinfo();
    int riskScore(int signals = 1);
};
