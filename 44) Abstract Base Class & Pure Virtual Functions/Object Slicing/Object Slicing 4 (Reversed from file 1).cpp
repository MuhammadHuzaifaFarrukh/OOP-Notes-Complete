#include <iostream>

using namespace std;

//In Inheritance , the derived class constructor tries to call the constructor from the base class to make the object of base class

class Car;

class Vehicle
{
protected:
    string name;
public:
    //Vehicle(){}
    Vehicle(string n) : name(n) {}
    virtual void show()
    {
        cout<<"Name : "<<name<<endl;
    }

public:
    string get_name() const
    {
        return name;
    }

};
class Car : public Vehicle
{
    string model;
public:
    Car(string n, string m) : Vehicle(n), model(m) {}
    void show()
    {
        cout<<"Car Details\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Model : "<<model<<endl;
    }
    Car& operator=(const Vehicle& obj)
    {
        if(this != &obj)
        {
            this->name = obj.get_name();
        }
    }
    Car(const Vehicle& obj) : Vehicle("Nothing")    //If you don't write this constructor init member list for Vehicle then compiler throws error as in inheritance , whether constructor or copy one , it needs base constructor to make object of the base class inside derived object
    {
        this->name = obj.get_name();
    }

};
int main()
{
    Car c("Toyota", "Corolla");
    Vehicle v("ABC");
    c = v;      //Here error is thrown if we don't write customized Copy Assignment Operator
    c.show();

    Car c2 = v; //Here error is thrown if we don't write customized Copy Constructor
    c2.show();
    //We can make the copy constructors / copy assignment operators and many more in inheritance or in unrelated classes to compare these objects of different / similar classes

    return 0;
}

