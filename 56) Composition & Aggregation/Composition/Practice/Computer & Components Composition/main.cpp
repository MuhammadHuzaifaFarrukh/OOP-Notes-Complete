#include <iostream>
#include "Computer.h"
#include "Component.h"
#include "Computer.cpp"
#include "Component.cpp"
#include <string>

using namespace std;
int main()
{
    Computer pc("Dell");
    pc.addComponent(Component("CPU", "Intel i7 3.4 GHz"));
    pc.addComponent(Component("RAM", "16 GB"));
    pc.addComponent(Component("Storage", "512 GB SSD"));
    pc.ShowComputer();
    return 0;
}