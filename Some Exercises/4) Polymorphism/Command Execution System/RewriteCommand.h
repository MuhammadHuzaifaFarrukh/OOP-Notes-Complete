#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Command.h"
using namespace std;

//Derived Class
class RewriteCommand : public Command
{
protected:
    Command* next;  //(Keep it in protected otherwise for private you must provide a public / protected getter for it)
public:
    RewriteCommand(string n, Command* ptr );
    Command* transform() override;
    void execute() override;
    int cost() override;
    Command* getnext();     //Use this as a getter for next if next is private
};

