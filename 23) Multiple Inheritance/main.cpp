#include <iostream>

using namespace std;

// Multiple Inheritance :
// A and B ->C
// One Child , many father
// Order of constructor and destructor matters when making the final class in it
// E.g C : A , B , then constructor order is A,B and destructor order is B,A
// Also if any virtual base class then its constructor is executed first before all classes

// Subobjects :
/*
[C object]
 ├─ A subobject  ← (from class A)
 ├─ B subobject  ← (from class B)
 └─ C-specific part  ← (its own members)
 */


class Base1
{
private:
protected:
    int base1_int;

public:
    void set_base1_int(int);
};

void Base1::set_base1_int(int a)
{
    base1_int = a;
}

class Base2
{
private:
protected:
    int base2_int;

public:
    void set_base2_int(int);
};

void Base2::set_base2_int(int a)
{
    base2_int = a;
}

class Base3
{
private:
protected:
    int base3_int;

public:
    void set_base3_int(int);
};

void Base3::set_base3_int(int a)
{
    base3_int = a;
}
// We have made 2 class here : Base1 and Base2 . Now we will do multiple inheritance here
// Syntax :
/*
class derived_class_name : {{Visibility Mode for 1st Class}}  {{1st Class_Name}}  {{Visibility Mode for 2nd Class}} , {{2nd Class_Name}} and so on if there are more base classes
{
    Body of Derived Class
};
     Here {{  }} means that it will get replaced by whatever there is to be
*/

// Now making a multiple inherited class in practical implementation :

//The Constructors of Base1, Base2 , Base3 will be called first and then Derived
class Derived : public Base1, public Base2, public Base3 // and so on // Multiple Inheritance completed
{
private:
protected:
    // base1_int , base3_int and base2_int are here

public:
    // set_base1 , set_base2 and set_base3 are already here
    void show_sum();
};

void Derived::show_sum()
{
    cout << "The value of base1 int is : " << base1_int << endl;
    cout << "The value of base2 int is : " << base2_int << endl;
    cout << "The value of base3 int is : " << base3_int << endl;
    cout << "The Sum of base 1 , 2 and 3 int is : " << base1_int + base2_int + base3_int << endl;
}

int main()
{
    Derived obj; // Always try to use the objects which are derived as they already have base class properties plus a few other . But in some cases we also use Base class objects. E.g if there is a person and a police man and a gangster , then all of them can walk so we will create person from base class and other two from derived classes .We should see according to our needs from which class do we have to create an object
    obj.set_base1_int(20);
    obj.set_base2_int(10);
    obj.set_base3_int(5);
    obj.show_sum();

    return 0;
}
