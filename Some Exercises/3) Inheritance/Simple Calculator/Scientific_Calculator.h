#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Scientific_Calculator
{

private:
    float result, rad;
    float si, co, ta;

protected:
public:
    void exponent(float, float);
    void trig(int);
    void logarithm(float);
    void mod(int, int);
};
