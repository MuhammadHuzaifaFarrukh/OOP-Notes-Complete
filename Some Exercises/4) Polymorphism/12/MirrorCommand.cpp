#include <iostream>
#include <vector>
#include <string>
#include "MirrorCommand.h"
using namespace std;

MirrorCommand :: MirrorCommand( string n, Command *ptr1,Command * ptr2) : Command(n), a(ptr1), b(ptr2) {}
Command* MirrorCommand::transform()
{
    return new RewriteCommand(b->getname(), a);
}
void MirrorCommand ::execute()
{
    if(b!=nullptr)
    {
        b->execute();
    }
    if(a!=nullptr)
    {
        a->execute();
    }
}
int MirrorCommand ::cost()
{
    int n1 =0, n2 =0 ;
    if(a!=nullptr)
    {
        n1=a->cost();
    }
    if(b!=nullptr)
    {
        n2=b->cost();
    }
    return (n1- n2+ basecosthelper());
}

