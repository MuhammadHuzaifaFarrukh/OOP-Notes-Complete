#include <iostream>

using namespace std;

class Vehicle
{
protected:
    string name;
public:

    Vehicle(string n) : name(n){}
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
    Car(string n , string m) : Vehicle(n) , model(m){}
    void show()
    {
        cout<<"Car Details\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Model : "<<model<<endl;
    }

};
int main()
{
    Car c("Toyota" , "Corolla");
    Vehicle v("ABC");
    v.show();   //Contains ABC as name
    v = c;  //Derived class obj can be assigned to base class obj like this

    v.show();   //Contains Toyota as name
    //This is called Object Slicing
    //Here object v only contains the Car's name
    //This loses Polymorphic behavior

    //c = v;  //Error , just like derived class ptr cannot point to a base class ptr

    return 0;
}
