#pragma once
#include <iostream>
#include <vector>
#include "AICamera.h"
using namespace std;

class PatrolBot : public AICamera
{
protected:
    int batterylevel;
    bool nightmode;
public:
    void setBotData(int events = 0, int spots = 0, int battery = 0, bool night = 0);
    void showinfo();
    int riskScore(int signals = 1);
};
