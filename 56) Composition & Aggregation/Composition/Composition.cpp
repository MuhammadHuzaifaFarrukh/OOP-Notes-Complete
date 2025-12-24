#include <iostream>
#include <string>
#include <memory> // For shared_ptr in a real-world scenario

using namespace std;

//Composition : (Strong Ownership, Dependent Lifetime)

//In Composition, the "part" object is created inside the "whole" object (usually as a value member). When the
//whole object is destroyed, the part object is automatically destroyed with it.

// The "Part" Class
class Engine
{
    string type;
public:
    Engine(string type)
    {
        cout << "\tEngine (" << type << ") constructed." << endl;
        this->type = type;
    }
    ~Engine()
    {
        cout << "\tEngine destroyed." << endl;
    }
    friend ostream &operator<<(ostream &out, const Engine &E)
    {
        cout << E.type <<endl;
        return out;
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
    Car() : myEngine("V8") // Constructor Invoked for Engine Class
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
    friend ostream &operator<<(ostream &out, const Car &C)
    {
        cout << "Car Engine is : "<<C.myEngine<<endl;    //Now here myEngine's operator << is must
        return out;
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
    cout << raceCar<<endl; // Using friend overloaded operator
    return 0;
}

//The output clearly shows that the Engine's lifetime is tied to the Car's lifetime.
