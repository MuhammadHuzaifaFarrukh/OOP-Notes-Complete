#include <iostream>
#include <vector>
#include "Guard.h"
#include "SecurityDevice.h"
#include "AICamera.h"
#include "GateScanner.h"
#include "PatrolBot.h"
#include "CampusControl.h"

#include "Guard.cpp"
#include "SecurityDevice.cpp"
#include "AICamera.cpp"
#include "GateScanner.cpp"
#include "PatrolBot.cpp"
#include "CampusControl.cpp"
using namespace std;

int main()
{
    CampusControl control;
    //Create Devices :
    Guard *g = new Guard();
    AICamera *cam = new AICamera();
    GateScanner *gate = new GateScanner();
    PatrolBot *bot = new PatrolBot();

    //Set Details :
    g->setDetails("Main Gate Guard", "G01", "Active");
    cam->setDetails("North Wing Camera", "C11", "Active");
    gate->setDetails("East Entrance Scanner", "GS22", "Active");
    bot->setDetails("Patrol Bot Alpha", "PB99", "Charging");

    //Assign Attributes :
    g->assignData(7,3);
    cam->setCameraData(7,2);
    gate->setScannerData(5,36);
    bot->setBotData(10,4,15,true);

    //Register :
    control.guards.push_back(g);
    control.cameras.push_back(cam);
    control.scanners.push_back(gate);
    control.bots.push_back(bot);

    //Run Tests :

    control.runStatus();
    cout<<"=== THREAT LEVELS ===\n";
    control.evaluateThreatLevel();

    return 0;
}
