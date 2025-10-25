#include <iostream>

using namespace std;

class Base
{

public :
    int var_base;
    void display()
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
    Base *ptr_base;
    Base obj_base;
    Derived obj_derived;

    ptr_base = &obj_derived;  //Pointing base class pointer to derived class object . When this pointer tries to run display() function , the one in Base class will run as it is a pointer of base class. This is valid because derived object is also a base object.It will only use those features which are inherited from base class into derived class
    /*
    The Base* pointer only "sees" the part of the memory that corresponds to the Base class (the Base Class Members section).
    The compiler knows that whatever is at that address must contain the full Base structure because the object being pointed to is a Derived object, which is guaranteed to contain a complete Base part.
    Even if the pointer can't see the Derived parts, what it can see is safe and valid.
    This implicit conversion is called Upcasting, and it is always safe and automatic.
    */
    ptr_base->var_base=34;
    ptr_base->display();   //Using base class function using base class pointer. It will use the display() from base class but inherited one
    // ptr_base->var_derived=50;  // Not valid



    //This uses Derived class functions as the pointer is of derived class and will also be able to use the Base class objects which are public or protected.
    Derived *ptr_derived;
    ptr_derived = &obj_derived ;
    ptr_derived->var_derived=98;
    ptr_derived->var_base = 9000;
    ptr_derived->display();
    //ptr_derived->Base::display(); //Can also run this one as there are 2 display() functions in derived class .

    /*
        Derived *ptr ;
        ptr = &obj_base;  // Base object is not a derived one and doesn't have features of a derived class.
        ptr->display();

        Logically : A base class object is NOT necessarily a derived class object. (e.g., An Animal is not necessarily a Dog; it could be a Cat, a Bird, or just a generic Animal).
        Memory Violation :

        The Derived* pointer promises the compiler that the memory it points to contains the full structure of a Derived object (including both Base and Derived parts).
        However, the object at that address (new Base()) is too small! It only contains the Base Class Members.
        If you try to access a member unique to the derived class using ptr->derived_member;, the pointer will try to read memory past the end of the actual Base object. which leads to undefined be

    */


    /*
    //You can also use dynamic allocation here
    Base *ptr_base;

        ptr_base = new Base;
        ptr_base->var_base=30;
        ptr_base->display();

    */



    return 0;
}



