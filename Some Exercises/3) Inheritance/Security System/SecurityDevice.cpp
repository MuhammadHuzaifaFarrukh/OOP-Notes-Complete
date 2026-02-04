#include <iostream>
#include <vector>
#include "SecurityDevice.h"
using namespace std;

void SecurityDevice::setDetails(string n, string id, string st)
{
    deviceName = n;
    deviceID = id;
    status = st;
}
void SecurityDevice::showinfo()
{
    cout<<deviceName
        <<" ("<<deviceID<<") Status : "<<status <<endl;
}
int SecurityDevice::riskScore(int signals)
{
    return signals*1;   //basic risk
}
