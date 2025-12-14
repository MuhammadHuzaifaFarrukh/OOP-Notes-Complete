#include <iostream>

using namespace std;

//Single Inheritance :
//A->B or C->D etc
//One Father , One Child


// PUBLIC VISIBILITY MODE:
// Private Members of Base Class are not inherited
// Public Members of Base Class are Public in Derived Class
// Protected Members of Base Class are Protected in Derived Class

//Derived Class can access the Base Class Private / Protected / Public Data via inheritance or getter / setters that are public / protected or by marking as friend function / class or nesting member functions
//Base class if wants to use  Derived Class Private Data then it needs to make friend function / class for that

//Static data members are also inherited and become one per two class if there are two classes in inheritance
/*
IMP NOTE:
Private members of the base class are not accessible directly in the derived class,
but they still exist inside the derived object as part of the Base subobject.
When we use inherited public methods to modify or display them,
those methods operate on the Base portion of the same derived object —
so they do affect and set the private data that belongs to that derived object’s Base part.
*/

class Base
{
private:
    int data1; // Not inheritable

public:
    int data2;
    void setdata();
    int getdata1();
    int getdata2();
};

void Base::setdata()
{
    data1 = 10;
    data2 = 20;
}

int Base::getdata1()
{
    return data1;
}
int Base::getdata2()
{
    return data2;
}

class Derived : public Base // Derived is being derived publicly
{

private:
    int data3;

public:
    // Only data1 is not inherited here
    // Here data2 , data3 , getdata1() and setdata() are already here as this is public visibility mode
    void process();
    void display();
};

void Derived::process()
{
    data3 = data2 * getdata1();
}

void Derived::display()
{
    cout << "The value of data 1 is : " << getdata1() << endl; // Data1 is private and not inheritable even though present in the derived object so that's why we access it through this inherited public function.
    cout << "The value of data 2 is : " << data2 << endl;      // Data2 and Data3 are public so they are easily accessible
    cout << "The value of data 3 is : " << data3 << endl;      // Data3 even private can be accessed using class methods
}

int main()
{                // We can also create Base class objects but then we won't be able to process or display our data
    Derived obj; // Always try to use the objects which are derived as they already have base class properties plus a few other . But in some cases we also use Base class objects. E.g if there is a person and a police man and a gangster , then all of them can walk so we will create person from base class and other two from derived classes .We should see according to our needs from which class do we have to create an object
    // |
    //\ /
    // It actually contains two parts internally:
    // 1) A Base subobject (with its own data1 and data2).
    // 2) The Derived-specific part (with data3).

    obj.setdata();
    obj.process();
    obj.display();
    // cout << obj.data1;
    // Here obj.data1 will cause error as data1 is not inherited in derived object and not accessible but still present in the Base subobject

    return 0;
}

/*
//PRIVATE VISIBILITY MODE
//Private Members of Base Class are not inherited
//Public and Protected Members of Base Class are private in Derived Class

class Base
{
private:
    int data1; //Not inheritable

public:

    int data2;
    void setdata();
    int getdata1();
    int getdata2();

};

void Base::setdata()
{
    data1=10;
    data2=20;
}

int Base::getdata1()
{
    return data1;
}
int Base::getdata2()
{
    return data2;
}

class Derived : private Base //Derived is being derived publicly
{

private :
    int data3;

public:
    //Only data1 is not inherited here
    //Here data2 , data3 , getdata1() , getdata2() and setdata() are already here but they are private now. So call them through nesting member function
    void process();
    void display();

};

void Derived::process()
{
    setdata();
    data3 = data2 * getdata1();
}

void Derived::display()
{
    cout<<"The value of data 1 is : "<<getdata1()<<endl;  //Data1 is private so we access it through this public function. They are not accessed directly
    cout<<"The value of data 2 is : "<<data2<<endl;      // Data2 and Data3 are public so they are easily accessible
    cout<<"The value of data 3 is : "<<data3<<endl;

}

int main()
{
   Derived obj;

   //obj.setdata(); This line will create error as now setdata() is also private so we can use nested member function.

   // We used nested member functions to use private functions using the public methods
   obj.process();
   obj.display();

   //We either use nested member functions or use public functions that work upon the private data of the class
    return 0;
}
*/
