#include <iostream>

using namespace std;

//Only Member Functions having same name in 2 classes irrespective of parameters ,creates ambiguity when used in inheritance.
//Same variables used in 2 different classes is allowed as well and do not create ambiguity . They are simply overwritten
//or previous one can be used using scope resolution operator in some inheritances or by using keyword etc

//Ambiguity in Multiple Inheritance

class base1
{
public:
    //For Functions in Function Hiding / Overwriting / Redefinition , only same name , no & types of parameters can be different
    void greet()   //Creates Ambiguity when inherited
    {
        cout<<"How are you ? "<<endl;
    }
};

class base2
{
public:
    void greet()   //Creates Ambiguity when inherited
    {
        cout<<"Ki Haal Chaal ha , theek ho naa ? "<<endl;
    }
};

class Derived : public base1, public base2
{
private:
    int a;

protected:

public:

    //Below function can be avoided or not written if user has specified like in the main in this example
    void greet()
    {
        base1::greet();   //Executes Base1 greet() function , also okay
    }
};

int main()
{
    base1 obj1;
    base2 obj2;
    obj1.greet(); //English Message  (No Error)
    obj2.greet(); // Punjabi Message  (No Error)

    Derived obj3;
    obj3.base1::greet();   //Error if there is no ambiguity resolution in inherited class

    //Either above syntax or do resolution in the function like use only
    // obj3.greet() and write base2::greet() in the greet() function of obj3

    return 0;
}

/*
//Ambiguity  is resolved automatically in Single or Multilevel Inheritance as previous one is overwritten by new one
class B
{
public:
    void say()
    {
        cout<<"Hello World"<<endl;
    }
};
class D : public B
{
public:
    void say()  //This will overwrite the say() method inherited from B to D class
    {

        cout<<"Hello World , my beautiful people !"<<endl;
    }
};


int main()
{
    B b;
    D d;
    b.say();   //This executes B class method
    d.say();    //This executes D class' overwritten method


    return 0;
}
*/


//When derived class uses same name for its variable and functions as that in base class then it is called name hiding or function hiding
//Functions might get hidden due to this (Function Hiding or Name Hiding)
//Member variables also get hidden due to this (Name Hiding)
