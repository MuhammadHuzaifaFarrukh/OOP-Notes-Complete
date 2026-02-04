#include <iostream>
#include <vector>
#include <string>
#include "Command.h"
#include "RewriteCommand.h"
#include "TimedRewrite.h"
#include "MirrorCommand.h"
#include "Command.cpp"
#include "RewriteCommand.cpp"
#include "TimedRewrite.cpp"
#include "MirrorCommand.cpp"
using namespace std;

int main()
{
    Command* c1 = new RewriteCommand("R1", nullptr);
    Command* c2 = new RewriteCommand("R2", nullptr);

    Command* t1 = new TimedRewrite("TR1", c1, 5);
    Command* t2 = new TimedRewrite("TR2", c2, 6);


    Command* m1 = new MirrorCommand("MC1", t1,t2);

    Command* r3 = new RewriteCommand("R3", m1);

    Command* t3 = new TimedRewrite("TR3", r3, 9);


    Command* arr[5] = {t1,t2,m1,r3,t3};

    for(int i = 0 ; i< 5 ; i++)
    {
        cout<<"----Running transform() result for arr["<<i<<"] ----"<<endl;
        Command* t = arr[i]->transform();
        if(t != nullptr)
        {
            t->execute();
            cout<<"Cost = "<<t->cost()<<endl<<endl;
        }
    }

    //Cleanup :
    delete c1;
    delete c2;
    delete t3;
    delete t1;
    delete t2;
    delete m1;
    delete r3;

    return 0;
}
