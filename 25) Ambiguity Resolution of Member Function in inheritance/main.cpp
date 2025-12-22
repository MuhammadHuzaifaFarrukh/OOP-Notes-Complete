#include <iostream>

using namespace std;

//============== Member Name Hiding in MULTIPLE INHERITANCE ============
//Only Member Functions having same name in 2 classes irrespective of parameters ,creates ambiguity when used in inheritance.
//Same variables used in 2 different classes is allowed as well and do not create ambiguity . They are simply overwritten
//or previous one can be used using scope resolution operator in some inheritances or by using keyword etc


//Ambiguity in Multiple Inheritance :
//Here we observe Triangular conflict that is , same named member functions / variables when inherited in multiple
//inheritance then this creates ambiguity to choose which one in the instantiated class
//The Name of the function/variable is same but their purpose / implementation might be different in the classes that define them
//When inherited in the lower hierarchy , compiler doesn't know which one to use as it sees two different functions/variables with same names

//This can be solved by either scope resolution operator (::) or writing another member function / variable
//that hides the other one , or by specifying the member function in another class by "using" keyword
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
    //We can also solve this by writing :
    //using base1::greet;
    //However if you are doing "using" and still redefining the function/variable then this new redefined function/variable
    //will hide the member that was specified by "using"

    //Below function can be avoided or not written if user has specified like in the main in this example
    void greet()
    {
        base2::greet();   //Executes Base1 greet() function , also okay
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

    //You can also write it like :
    // obj3.greet() when you have specified the function by "using" keyword

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
