#include <iostream>
#include <string>
#include <memory> // For shared_ptr in a real-world scenario

using namespace std;

// The Part Class
class Engine
{
private:
    string type;
public:
    Engine(string t) : type(t)
    {
        cout << "--> Engine " << type << " constructed (on a shelf)." << endl;
    }
    ~Engine()
    {
        cout << "--> Engine " << type << " destroyed." << endl;
    }
    void start()
    {
        cout << "Engine " << type << " roars to life!" << endl;
    }
};

// The Whole Class (Aggregator)
class Car
{
private:
    // Holds a raw pointer (or std::shared_ptr for modern C++) to an existing Engine.
    Engine* aggregatedEngine;

public:
    // The Car takes an existing Engine object. It does not create it.
    Car(Engine* engine) : aggregatedEngine(engine)
    {
        cout << "Car body completed, linking existing Engine." << endl;
    }

    // The Car's destructor DOES NOT delete the Engine object.
    // This is the key to Aggregation.
    ~Car()
    {
        cout << "Car body scrapped." << endl;
    }

    void run()
    {
        aggregatedEngine->start();
    }
};

int main()
{
    // 1. Create the Engine object independently (it exists on the shop floor)
    Engine* v6Engine = new Engine("V6");

    cout << "--- Start Car 1 Scope ---" << endl;
    {
        // 2. A Car is built and linked to the existing Engine (Aggregation)
        Car blueCar(v6Engine);
        blueCar.run();
    } // The Car object is destroyed here (goes out of scope).
    cout << "--- End Car 1 Scope ---" << endl;

    // OUTPUT: The Car is destroyed, but the V6 Engine still exists in memory!
    // It could now be linked to another Car object.

    cout << "--- V6 Engine is still available for a new Car ---" << endl;

    // 3. The original Engine object must be destroyed manually by the code
    //    that created it (the shop/factory management).
    delete v6Engine;

    return 0;
}




//Inheritance :
/*
// Base Class (Superclass)

class Vehicle
{

public:

void startEngine()
     {

            cout << "Vehicle engine started." << endl;

     }

};


// Derived Class (Subclass) - IS-A relationship

class Car : public Vehicle
{

public:


void drive()
   {

        std::cout << "Car is driving." << std::endl;


   }


};
*/
