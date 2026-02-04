#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Base Class :
class Command
{
private:
    string name;    //(Inherited but accessed through getname)

public:
    Command(string n);
    //Virtual Functions :
    virtual Command* transform() = 0;
    virtual void execute() = 0;
    virtual int cost() = 0;

    //Non-Pure Function
    void printname();
    string getname() const;
    //Non-Pure Virtual Function (Destructor)
    virtual ~Command();

protected:
    int basecosthelper();
};
