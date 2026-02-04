#include <iostream>
#include <vector>
#include <string>
#include "Command.h"
using namespace std;

Command::Command(string n)
{
    name = n;
}

void Command::printname()
{
    cout<<"["<<name<<"]"<<endl;
}
string Command::getname() const
{
    return name;
}
Command::~Command() {}

int Command::basecosthelper()
{
    return 1;
}
