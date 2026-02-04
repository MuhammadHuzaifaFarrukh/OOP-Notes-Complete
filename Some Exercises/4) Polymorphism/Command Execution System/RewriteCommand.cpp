#include <iostream>
#include <vector>
#include <string>
#include "RewriteCommand.h"
using namespace std;

RewriteCommand::RewriteCommand(string n, Command* ptr ) : Command(n), next(ptr) {}

Command* RewriteCommand::transform()
{
    if(next != nullptr)
    {
        return next->transform();   //Recursion occurs
    }
    return this;
}
void RewriteCommand::execute()
{
    //First calls next execute
    if(next !=nullptr)
    {
        next->execute();    //Recursion occurs
    }
    Command::printname();   //or simply printname() as there's only one printname() function
}
int RewriteCommand::cost()
{
    if(next != nullptr)
    {
        return (next->cost())*2 ;   //Recursion occurs
    }
    return 2;
}

Command* RewriteCommand::getnext()
{
    return next;
}
