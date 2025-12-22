#include <iostream>

using namespace std;

class Vehicle
{
protected:
    string name;
public:

    Vehicle(string n = "") : name(n){}
    virtual void show()
    {
        cout<<"Name : "<<name<<endl;
    }

public:

};
class Car : public Vehicle
{
    string model;
public:
    Car(string n = "", string m = "") : Vehicle(n) , model(m){}
    void show()
    {
        cout<<"Car Details\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Model : "<<model<<endl;
    }

};

// Function that uses base class & return type but returns a derived class object &
//We can do this also in virtual functions or any other member functions instead of global functions
Car& make_car()
{
    // Object must be created dynamically (on the heap) or be global/static
    Car *c1 = new Car("Honda", "Civic");

    // Returning the dynamically allocated Car object by reference
    // Note: The caller is now responsible for deleting the object!
    return *c1;
}

int main()
{
    Car c("Toyota" , "Corolla");
    Vehicle& v = make_car();


    v.show();   //Contains Honda as name
    //This achieves polymorphic behavior
    delete &v;
    return 0;
}
