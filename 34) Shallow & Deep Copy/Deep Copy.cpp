#include <iostream>

using namespace std;

//Shallow copy does not work when we need to allocate dynamically with normal variables in our class. In this , we may use our own or compiler generated copy constructor.
//Deep copy does what Shallow copy can't. For this , we need to create the copy constructor by ourself and create a pointer pointing to a heap memory

class student
{
public :
    string name;
    double *cgpaptr;

    student(string name , double cgpa)
    {
        (*this).name = name; //or this->name
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }


    student(const student &s) //Customized Copy Constructor
    {
        name = s.name;
        cgpaptr = new double; //cgpaptr = s.cgpaptr will fail the deep copy and work like a shallow copy again
        *cgpaptr = *s.cgpaptr;
    }


    void getData()
    {
        std::cout<<"Name :  "<<  name<<endl;
        std::cout<<"CGPA :  "<< *cgpaptr<<endl;
    }



};

int main()
{
    student s1("Usama" , 5.13);

    student s2(s1); //Makes Deep copy using copy constructor if we have a copy constructor otherwise shallow.
    //student s2 = s1; Makes Deep copy using copy constructor if we have a copy constructor otherwise shallow copy
    //s2 = s1;  //Makes Shallow copy using copy assignment operator if we have a copy constructor otherwise shallow
    s1.getData();
    s2.name = "Asad";
    *(s2.cgpaptr) = 6.2;
    s2.getData();

    delete s1.cgpaptr;
    delete s2.cgpaptr;

    return 0;
}


//No need to specify whether it is a shallow or deep copy.
//In C++, whether a copy is shallow or deep depends on how you implement the copy operations in your class.




//Need of Deep Copy : (In case of Dynamic Memory Allocation)
/*

The pointer itself (the memory address) is copied from the source object (obj1) to the new object
(obj2)
Both obj 1 and obj 2 now have pointers pointing to the exact same block of memory on the heap.
​If you use obj 2 to change the data at that shared memory location, obj 1
will also appear to have changed, and vice-versa.
*/

//Point of Serious Error : (In case of Dynamic Memory Allocation)
/*
When the first object (obj1) goes out of scope, its destructor runs and calls delete
 on the shared heap memory address.

When the second object (obj1) goes out of scope, its destructor runs and calls delete
on the same memory address.
*/

//We either use copy assignment operator or copy constructor as done above for deep copy
//Because in both cases shallow copy is made
//Copy assignment is the same as copy constructor , with difference that we copy from existing object so first we clear our destination object and fill it with new data from copying object
