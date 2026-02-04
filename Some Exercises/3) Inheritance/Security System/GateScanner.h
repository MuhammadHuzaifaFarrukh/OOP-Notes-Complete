#pragma once
#include <iostream>
#include <vector>
#include "SecurityDevice.h"
using namespace std;

class GateScanner : public SecurityDevice
{
protected:
    int failedattempts;
    int deviceage;

public:
    void setScannerData(int failed = 0, int age = 0);
    void showinfo();
    int riskScore(int signals = 1);

};
