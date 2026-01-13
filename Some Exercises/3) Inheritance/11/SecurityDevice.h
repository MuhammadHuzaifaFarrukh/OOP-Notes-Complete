#pragma once
#include <iostream>
#include <vector>
using namespace std;

class SecurityDevice
{
protected:
    string deviceName, deviceID, status;

public:
    //SecurityDevcice(){}
    void setDetails(string n, string id, string st);
    void showinfo();
    int riskScore(int signals = 1);
};
