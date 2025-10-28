#include <iostream>

using namespace std;

class Base
{
public :
    int var_base;
    virtual void display()  // Virtual function tells compiler that this function can be override by its derived class function. Virtual functions are used in inheritance to achieve runtime polymorphism where compiler checks the actual object's data type. When a class has atleast one virtual function , compiler creates a virtual table for that class during compilation. This table stores pointers to the virtual function in code segment defined in base and derived classes. When you create an object of a derived class, memory allocated for the object includes a hidden pointer to vtable of its class.This pointer is established during object creation.
    {
        cout<<"Displaying Base Class variable var_base : "<<var_base<<endl;
    }
};
class Derived : public Base
{

public :
    int var_derived;
    void display()
    {
        cout<<"Displaying Base Class variable var_base : "<<var_base<<endl;
        cout<<"Displaying Derived Class variable var_derived : "<<var_derived<<endl;
    }

};

int main()
{

    //Object of Derived class , Pointer of Base class -> Usually gives the Base Class Function
    //By using virtual function , we can now get the Derived Class Function

    Base *ptr_base ;
    Derived obj_derived;
    ptr_base = &obj_derived;
    ptr_base->display(); //display() in base is overwritten

    //After doing virtual functions , if you want Base display back use :
    //ptr_base->Base::display();


    //Without virtual function , you can't access Derived class function using Base Pointer  nor by using Scope Resolution Operator
    //E.g you can't do ptr_base->obj_derived

    //When virtual function is called via a pointer or reference, do not decide which version to run until runtime


    return 0;
}



