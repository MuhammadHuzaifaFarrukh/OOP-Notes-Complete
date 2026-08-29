#include <iostream>
#include <string>
#include <vector>

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
The Car class creates its own V8Engine directly inside its constructor using new.
If you want to change to an ElectricEngine, you have to modify the Car class code.
*/

// class V8Engine
// {
// public:
//     void start()
//     {
//         cout << "V8 roaring!" << endl;
//     }
// };

// class Car
// {
// private:
//     V8Engine *engine; // Directly tied to V8Engine
// public:
//     Car()
//     {
//         engine = new V8Engine(); // Tight coupling via 'new'
//     }
//     void drive()
//     {
//         engine->start();
//     }
// };

/*
2. Decoupled Code (Good Practice)
The Car class depends on an abstract IEngine interface.
The engine is passed in from the outside (Dependency Injection).
Now Car works with any engine without modifying Car code.
*/
// Abstract Interface
class IEngine
{
public:
    virtual ~IEngine() = default;
    virtual void start() = 0;
};

// Concrete implementations
class V8Engine : public IEngine
{
public:
    void start() override
    {
        cout << "V8 roaring!" << endl;
    }
};

class ElectricEngine : public IEngine
{
public:
    void start() override
    {
        cout << "Silent electric boost!" << endl;
    }
};

// Decoupled Car Class
class Car
{
private:
    IEngine *engine; // Depends on abstraction, not concrete class
public:
    Car(IEngine *eng) : engine(eng) {} // Injected dependency

    void drive()
    {
        engine->start();
    }
};

int main()
{
    return 0;
}