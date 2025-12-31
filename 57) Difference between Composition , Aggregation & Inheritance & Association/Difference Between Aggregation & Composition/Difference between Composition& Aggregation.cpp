#include <iostream>
#include <string>
#include <memory> // For shared_ptr in a real-world scenario

using namespace std;

//Aggregtaion : (Weak Ownership, Independent Lifetime)
//In Aggregation, the "part" object is created externally and the "whole" object only holds a pointer or
//reference to it. The "whole" is not responsible for the "part's" destruction.

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
    // Even though it is aggregation but it is being created and destroyed when obj is created / destroyed so here composition = aggregation
    // It is more visible when we use pointers with new keyword to allocate or vectors of 
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
//The Car was destroyed, but the Engine object's destruction was managed outside the Car class, making this an Aggregation relationship.





//Composition : (Strong Ownership, Dependent Lifetime)

//In Composition, the "part" object is created inside the "whole" object (usually as a value member). When the
//whole object is destroyed, the part object is automatically destroyed with it.

/*
// The "Part" Class
class Engine
{
public:
    Engine(string type)
    {
        cout << "\tEngine (" << type << ") constructed." << endl;
    }
    ~Engine()
    {
        cout << "\tEngine destroyed." << endl;
    }
};

// The "Whole" Class - COMPOSITION: Engine is a value member
class Car
{
private:
    // The Engine object is part of the Car object itself.
    // The Car's constructor creates the Engine.
    Engine myEngine;

public:
    Car() : myEngine("V8")
    {
        cout << "Car constructed." << endl;
    }
    ~Car()
    {
        cout << "Car destroyed." << endl;
        // The compiler automatically calls the Engine's destructor here.
    }
    void start()
    {
        cout << "Car started using its engine." << endl;
    }
};

int main()
{
    std::cout << "** --- Starting Composition Test --- **" << std::endl;

    // 1. Car is created. This forces the creation of its Engine.
    Car raceCar;
    raceCar.start();

    cout << "** --- Exiting Scope: Destruction Order --- **" << endl;
    // 2. When 'raceCar' goes out of scope, the Car's destructor is called,
    //    and then the Engine's destructor is called automatically.

    return 0;
}
*/
//The output clearly shows that the Engine's lifetime is tied to the Car's lifetime.
