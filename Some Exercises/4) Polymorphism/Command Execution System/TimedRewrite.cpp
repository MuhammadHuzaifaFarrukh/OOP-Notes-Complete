#include <iostream>
#include <vector>
#include <string>
#include "TimedRewrite.h"
using namespace std;

TimedRewrite ::TimedRewrite(string n, Command* ptr, int y) : RewriteCommand( n, ptr)
{
    if(y<0)
    {
        y = 1;
    }
    delay = y;
}
Command* TimedRewrite ::transform()
{
    if(next == nullptr)
    {
        return this;
    }
    Command* n = RewriteCommand::transform();
    if(delay%2 == 0)
    {
        return n;
    }
    return this;
}
void TimedRewrite ::execute()
{
    cout<<"Delay : "<<delay<<endl;
    RewriteCommand::execute();
}
int TimedRewrite ::cost()
{
    int x = RewriteCommand::cost();
    x = x+(delay%3);
    int n = next->cost();
    //int n = getnext()->cost();
    if(n== 2 || n== 3 || n== 5 || n== 7 )
    {
        return (x+5);
    }
    return x;
}


