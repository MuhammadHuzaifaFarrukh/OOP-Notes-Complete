#pragma once
#include <iostream>
#include <vector>

using namespace std;
// You can include complete headers but we use forward declarations
// Use forward declarations to reduce compilation dependencies
// Use forward declarations when not a complete object but just a pointer or reference to it
class Guard;
class AICamera;
class GateScanner;
class PatrolBot;

class CampusControl
{
public:
    vector <Guard*> guards;
    vector <AICamera*> cameras;
    vector <GateScanner*> scanners;
    vector <PatrolBot*> bots;

    void runStatus();

    void evaluateThreatLevel();
};
