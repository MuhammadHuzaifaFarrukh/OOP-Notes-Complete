#include <iostream>
using namespace std;

// Define a Car class with a method to display its speed
class Car
{
public:
    void displaySpeed(int speed)
    {
        cout << "The car is moving at " << speed << " km/h." << endl;
    }
};

int main()
{
    // Create a Car object named myCar
    Car myCar;

    // Send a message to myCar to execute the displaySpeed method
    int currentSpeed = 100;

    // Obj_name.function_name(information);
    myCar.displaySpeed(currentSpeed);

    return 0;
}


/*
Objects communicate with one another by sending and receiving information.
A message for an object is a request for the execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results.
Message passing involves specifying the name of the object, the name of the function, and the information to be sent.
Calling any method is a specific form of message passing. As it can happen between two objects , multiple objects  , single object, polymorphism , function overloading etc ...
*/

