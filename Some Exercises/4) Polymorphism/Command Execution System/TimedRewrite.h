#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "RewriteCommand.h"
using namespace std;

class TimedRewrite : public RewriteCommand
{
    int delay;
protected:

public:
    TimedRewrite(string n, Command* ptr, int y);
    Command* transform() override;
    void execute() override;
    int cost() override;
};
