#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
Coupling measures how dependent software modules (classes, functions, or components) are on each other.

Coupling: The degree of interdependence between two modules. High coupling means a change in one class forces changes in others.
Low coupling means modules operate independently (Low coupling is better than high/tight coupling).

Tight Coupling: Components are directly dependent on concrete implementations.
Changing one component breaks or requires rewriting another.

Decoupling (Loose Coupling): Structuring code so components interact through interfaces, abstract base classes, or events rather than concrete classes.
Changes to internal implementation details do not impact other parts of the system.
*/

/*
1. Tight Coupling (Bad Practice)
Imagine a desk lamp where the power cord is soldered directly into the house wall wiring.
The Problem:
Want to move the lamp to another room? You can't.
Want to plug it into a Portable Battery / Power Bank? You have to rip open the lamp and rewire it.
If the wall wiring changes, the lamp breaks.

*/

// Wall Wiring
// class HouseWiring
// {
// public:
//     void supply220V() { /* supplies power */ }
// };

// // High Coupling: Lamp is hardwired directly to the HouseWiring
// class Lamp
// {
// private:
//     HouseWiring wall; // Directly embedded dependency!
// public:
//     void turnOn()
//     {
//         wall.supply220V();
//     }
// };

/*
2. Decoupled Code (Good Practice)
Now, imagine introducing a standard Wall Socket (Interface). The lamp doesn't care where the electricity comes from, as long as it fits the plug.
Standardized plug & socket and Flexible - plug into generator, battery, or wall.
Lamp class never changes when adding new power sources.
*/

// 1. The Interface (The Wall Socket standard)
class IPowerSource
{
public:
    virtual ~IPowerSource() = default;
    virtual void providePower() = 0;
};

// 2. Concrete Sources implementing the Socket interface
class WallSocket : public IPowerSource
{
public:
    void providePower() override
    {
        cout << "Powering from House Grid 220V\n";
    }
};

class PowerBank : public IPowerSource
{
public:
    void providePower() override
    {
        cout << "Powering from Portable Battery\n";
    }
};

// 3. Low Coupling: Lamp depends ONLY on the socket interface
class Lamp
{
private:
    IPowerSource *powerSource; // Injected dependency
public:
    Lamp(IPowerSource *source) : powerSource(source) {}

    void turnOn()
    {
        powerSource->providePower();
    }
};

int main()
{
    WallSocket wall;
    PowerBank battery;

    // Use with Wall Socket
    Lamp deskLamp(&wall);
    deskLamp.turnOn();

    // Swap to Power Bank without changing ONE line of Lamp code!
    Lamp portableLamp(&battery);
    portableLamp.turnOn();

    return 0;
}