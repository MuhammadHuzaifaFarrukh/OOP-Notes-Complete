#include <string>
#include <iostream>
#include "Computer.h"
#include "Component.h"

using namespace std;

Computer :: Computer()
{
    brand = "";
    componentCount = 0;
    totalComponents = 10;
    components = new Component[totalComponents];
}

Computer :: Computer(string b)
{
    brand = b;
    componentCount = 0;
    totalComponents = 10;
    components = new Component[totalComponents];
}

Computer :: ~Computer()
{
    delete[] components;
}

void Computer :: addComponent(const Component& comp)
{
    //Resize the total Components if needed
    if(componentCount ==  totalComponents)
    {
        totalComponents = totalComponents * 2;
        Component* newComponents = new Component[totalComponents];
        for(int i = 0; i < componentCount; i++)
        {
            newComponents[i] = components[i];
        }
        delete[] components;
        components = newComponents;
    }
    components[componentCount++] = comp;
}

void Computer :: ShowComputer()
{
    cout<<"Computer Brand : "<<brand<<endl;
    for(int i = 0; i < componentCount; i++)
    {
        cout<<"Component "<<" : ";
        components[i].ShowComponent();
        cout<<endl;
    }
}