#pragma once
#include <iostream>
#include <string>
#include "CityBlock.h"
#include "Road.h"
#include "Location.h"

using namespace std;
// If L, R , CB is const then .getName() should also be const too
ostream &operator<<(ostream &out, const CityBlock &CB);
ostream &operator<<(ostream &out, const Location &L);
ostream &operator<<(ostream &out, const Road &R);