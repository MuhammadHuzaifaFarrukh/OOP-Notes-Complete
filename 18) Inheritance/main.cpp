#include<iostream>

using namespace std;

//We will not use member initialization list as we have created objects from both classes so constructors from both classes will initialize all objects created

//base class
class employee
{
private:

public:

    employee(int);
    employee() {} //Blank constructor is necessary here as the derived class automatically calls base class constructor
    //The Blank Constructor is necessary to put in base class if we use any other type of constructor in base class and then make a obj of either that derived class or of that base class
    ~employee();
    float salary;
    int id;

};



//Derived class syntax :
//class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
//{
//    class members/methods/etc...
//} //By default visibility mode is private
//Public Visibility Mode : The Public members of base class remain public in derived class
//Private Visibility Mode : The Public Members of base class become private in derived class

employee :: employee(int inp_id)
{
    id=inp_id;
    salary=34.0;
}



class programmer : public employee //Derived Public Class
{
private:


public :
    int language_code = 9 ;  //id,salary variable here are public
    programmer(int);
    programmer() {} // Necessary for the next derived class
    ~programmer(); // Destructor
    void getdata();
};


class banda : public programmer
{
public :
    banda()  //Derived class automatically calls base class constructor  to use work on the constructors
    {
        cout<<"I'm a banda object "<<endl;
    }

};




programmer::programmer(int inp_id)  //Derived class automatically calls base class constructor  to use work on the constructors
{
    id=inp_id;
}


void programmer::getdata()
{
    cout<<id<<endl;
}


//Destructors : Ensuring that object's data is destroyed before program ends . If programmer destructor runs, automatically the employee destructor will run as it is inherited with employee class
programmer::~programmer()
{
    //cout<<"Destructor for Programmer Class was Called " <<endl;
}

employee::~employee()
{
    //cout<<"Destructor for Employee Class was Called " <<endl;
}



int main()
{
    employee huz(1), wal(2);  //This can also be done using member functions instead of constructors .
    //Here employee class objects cannot set their language code
    cout<<huz.salary <<endl<<wal.salary <<endl;



    {
        programmer skillf(10);
        // cout<<endl<<skillf.id;  It will be error if it runs in private or no visibility mode of programmer derived class
        skillf.getdata();

    }

    banda b1;


    cout<<endl<<"The End of the Program " <<endl;
    //Always try to use the objects which are derived as they already have base class properties plus a few other . But in some cases we also use Base class objects. E.g if there is a person and a police man and a gangster , then all of them can walk so we will create person from base class and other two from derived classes .We should see according to our needs from which class do we have to create an object

    return 0;
}


/*

Inheritance has 5 types :
1) Single : A->B and so on i.e one father , one child
2) Multiple : A & B -> C etc i.e many father , one child
3) Hierarchical : A->B & A->C etc , one father , many child
4) Multi-level : A->B->C->D and so on (Combination of many single inheritances) i.e great-grand-father , grand-father , father , child , and so on
5) Hybrid : Combination of more than one type of inheritance
*/


//Single Inhertiance : (One father , one child)
/*
//Class A->B then single inheritance but if B->C then its multi-level not single
//Single only when Class A->B and then C->D etc
*/


//Multiple Inhertiance : (Many fathers , one child)
/*
//Class A & B->C then Multiple inheritance
*/

//Hierarchical Inhertiance : (One father , Many child)
/*
//Class A->B & A-> C then hierarchical
//It can be said as a sort of single inheritance but not in a chain like Multi-level
*/

//Multi-level Inhertiance : (One father , one child ; It goes in a Chain)
/*
//Class A->B->C->D and so on (Combination of many single inheritances but in a chain)
*/

//Hybrid Inhertiance : (Combination of more than one type of inheritance)
/*
E.g here we combine 2 inheritances :
Class A->B & A->C then B & C -> D so there is hierarchical and multiple inheritance
*/



//These are just names and the inheriting properties depend in which way you make derived class
//Also you don't need to remember which type of inheritance to take as you can make a derived class in any way you think your task will work out
