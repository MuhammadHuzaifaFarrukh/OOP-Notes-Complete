#pragma once
#include <iostream>
#include <string>
#include "class.h"
#include "Finance.h"
#include "fstream"

using namespace std;

class Finance;
class Student;

void processcholarship(Student & s, Finance &f);
void Summary(Student & s, Finance &f);

ostream& operator <<(ostream&out, const Student &s);
istream& operator >> (istream&in,  Student &s);

void LoadFromFile();
