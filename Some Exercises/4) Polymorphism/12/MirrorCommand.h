#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Command.h"
using namespace std;

class MirrorCommand : public Command
{
    //Keep them in private or protected (Basic OOP)
    Command* a ;
    Command* b;
public:

    MirrorCommand( string n, Command *ptr1,Command * ptr2);
    Command* transform() override;
    void execute() override;
    int cost() override;
};
