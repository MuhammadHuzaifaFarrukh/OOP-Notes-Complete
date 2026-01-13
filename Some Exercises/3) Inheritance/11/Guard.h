#pragma once
#include <iostream>
#include <vector>
#include "SecurityDevice.h"
using namespace std;

class Guard : public SecurityDevice
{
protected:
    int patrolhours;
    int reportfiled;
public:

    void showinfo();
    int riskScore(int signals = 1);
    void assignData(int hours = 0, int reports = 0);
};
