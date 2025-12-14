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

//A Function can be made that returns a Base Class ptr or Derived Class ptr
//We can do this also in virtual functions or any other member functions instead of global functions
//We can also make a function that has the return type as Base class but returns a Derived class object
//Here  a Derived class ptr is returned

Car* make_car()
{
    Car *c1 =new Car("Honda" , "Civic");
    return c1;
    //or just return new Car("Honda" , "Civic");
}

int main()
{
    Car c("Toyota" , "Corolla");
    Vehicle *v;
    v = make_car();  //Derived class obj can be assigned to base class obj like this

    v->show();   //Contains Honda as name
    //This again achieves the Polymorphic Behavior

    return 0;
}
