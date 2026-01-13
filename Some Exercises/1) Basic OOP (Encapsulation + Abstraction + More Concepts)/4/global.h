#pragma once
#include <string>

using namespace std;
//Include Global Variables , Arrays , Functions etc that are only global , related to class or not

extern const int ARRAY_SIZE;
extern string currency[];
extern double rates[];


//Global Functions :

unsigned int find_index(string);
double get_rate(unsigned int);
