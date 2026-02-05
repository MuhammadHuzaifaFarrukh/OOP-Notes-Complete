#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Scientific_Calculator.h"
#include "Simple_Calculator.h"

using namespace std;

class Full_Calculator : public Simple_Calculator, public Scientific_Calculator
{
private:
protected:
public:
};

