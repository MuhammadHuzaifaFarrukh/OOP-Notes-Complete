#include <iostream>
#include <string>
using namespace std;

//Shallow copy initializes the object from another existing object. This initialization is member by member variables from each object
//Shallow copy does not work when we need to allocate dynamically with normal variables in our class. In this , we may use our own or compiler generated copy constructor.

class student
{
public :
    string name;
    double cgpaptr;
    student(string nname , double ncgpaptr)
    {
        name = nname;
        cgpaptr = ncgpaptr;
    }
};

int main()
{

    student s1("Usama", 5.13);

    //student s2(s1); //Makes shallow copy using copy constructor , works without a blank or default constructor in this syntax
    //Student s2= s1 //Makes shallow copy using copy constructor , works without a blank or default constructor in this syntax
    s2 = s1;  //Makes Shallow copy using copy assignment operator ,  works without a blank or default constructor in this syntax

    return 0;
}

//The default versions of BOTH the Copy Constructor and the Copy Assignment Operator perform a shallow copy.
