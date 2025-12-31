#include <iostream>
#include <string>

using namespace std;

// Forward declaration so Driver knows Car exists
class Car;

// ================= ASSOCIATION ================
// The "Outer" Class - ASSOCIATION: Driver uses a Car
class Driver
{
private:
    string m_name;

public:
    Driver(string name) : m_name(name)
    {
        cout << "Driver (" << m_name << ") created." << endl;
    }

    // ASSOCIATION: The object is passed as a parameter
    // The Driver "Uses" the Car to drive, but does not own it.
    void drive(Car &c);

    ~Driver()
    {
        cout << "Driver (" << m_name << ") destroyed." << endl;
    }
};

// The "Inner" Class (Associated Class)
class Car
{
private:
    string m_model;
    // Granting friendship so Driver can access private data
    friend class Driver;

public:
    Car(string model) : m_model(model)
    {
        cout << "Car (" << m_model << ") created." << endl;
    }

    void start()
    {
        cout << "The " << m_model << " engine roars to life!" << endl;
    }

    ~Car()
    {
        cout << "Car (" << m_model << ") destroyed." << endl;
    }
};

// Implementation of the Association function
void Driver::drive(Car &c)
{
    // The Driver uses the Car's public function
    c.start();
    // Accessing private m_model because Driver is a 'friend'
    cout << m_name << " is now driving the " << c.m_model << "." << endl;
}

int main()
{
    cout << "** --- Starting Association Test --- **" << endl;

    // 1. Objects are created independently (Unbounded Lifetimes)
    Driver myDriver("Alex");
    Car myCar("F1-Racer");

    cout << "\n** --- Performing Action --- **" << endl;

    // 2. Invoking the function for the associated object
    // The driver uses the car, but they remain separate entities.
    myDriver.drive(myCar);

    cout << "\n** --- Exiting Scope: Independent Destruction --- **" << endl;
    // 3. Objects are destroyed in the reverse order of creation.
    // Their lifetimes are not tied together like Composition
    return 0;
}
