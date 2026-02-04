#pragma once
#include <iostream>
#include <vector>
#include "CampusControl.h"
using namespace std;

void CampusControl::runStatus()
{
    //Guards :
    for(int i = 0 ; i<guards.size() ; i++)
    {
        guards[i]->showinfo();
        cout<<endl;
    }
    cout<<endl<<endl;

    // AI Camera :
    for(int i = 0 ; i<cameras.size() ; i++)
    {
        cameras[i]->showinfo();
        cout<<endl<<endl;
    }
    cout<<endl;

    // Scanners :
    for(int i = 0 ; i<scanners.size() ; i++)
    {
        scanners[i]->showinfo();
        cout<<endl<<endl;
    }
    cout<<endl;

    // Bots :
    for(int i = 0 ; i<bots.size() ; i++)
    {
        bots[i]->showinfo();
        cout<<endl;
    }
    cout<<endl<<endl;
}
void CampusControl::evaluateThreatLevel()
{
    int evaluate[4] = {0};
    for(int i = 0 ; i<guards.size() ; i++)
    {
        evaluate[0] += guards[i]->riskScore(0);
    }
    cout<<"Device Risk : "<<evaluate[0]<<endl;
    for(int i = 0 ; i<cameras.size() ; i++)
    {
        evaluate[1] += cameras[i]->riskScore(0);
    }
    cout<<"Device Risk : "<<evaluate[1]<<endl;
    for(int i = 0 ; i<scanners.size() ; i++)
    {
        evaluate[2] += scanners[i]->riskScore(0);
    }
    cout<<"Device Risk : "<<evaluate[2]<<endl;

    for(int i = 0 ; i<bots.size() ; i++)
    {
        evaluate[3] += bots[i]->riskScore(0);
    }
    cout<<"Device Risk : "<<evaluate[3]<<endl;


    for(int i = 0 ; i< 4 ; i++)
    {
        for(int j = i+1 ; j<4 ; j++)
        {
            if(evaluate[i] > 51 && evaluate[j] > 51 )
            {
                cout<<"Campus Threat : "<<"Lockdown Alert "<<endl;
                return ;
            }
        }
    }
    cout<<"Campus Threat : "<<"Campus Secure "<<endl;
    return;
}

