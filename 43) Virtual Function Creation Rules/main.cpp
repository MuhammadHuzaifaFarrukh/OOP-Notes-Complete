#include <iostream>
#include<string>

using namespace std;

//When virtual function is called via a pointer or reference, do not decide which version to run until runtime

//Virtual Function Good Example Program :

class StGamer
{
protected :
    string title;
    float rating;

public :
    //   StGamer(){} //Required if not initialized object in first line (Blank Constructor)
    StGamer(string, float);
    virtual void display() {} //Here virtual function will be inherited in both classes and removing it will cause errors in the ones which are accessing this function through pointers as they will point to the base class function at runtime


};
StGamer::StGamer(string t, float r)
{
    title = t;
    rating = r;
}


class StGamerVids : public StGamer
{
public :
    int vid_length;
    StGamerVids(int, string, float ) ;
    // StGamerVids(){}            //Required for blank constructor
    void display();
};

StGamerVids::StGamerVids(int vL, string t, float r ) : StGamer(t,r)    //Defining Constructor outside of class with initialization list and declare without initialization list in class
{
    vid_length=vL;
}


void StGamerVids::display()
{
    cout<<"The Title of the Video is  : "<<title<<endl;
    cout<<"The Length of the Video is  : "<<vid_length<<" minutes "<<endl;
    cout<<"The Rating of the Video is  : "<<rating<<endl<<endl;
}

class StGamerWeb : public StGamer
{
public :
    int words;
    StGamerWeb(int txt, string t, float r) : StGamer(t,r)
    {
        words = txt;
    }
    // StGamerWeb(){}            //Required for blank constructor
    void display();
};

void StGamerWeb::display()
{
    cout<<"The Title of the Video is  : "<<title<<endl;
    cout<<"The Words of the Text Tutorial is  : "<<words<<" words "<<endl;
    cout<<"The Rating of the Video is  : "<<rating<<endl<<endl;
}

int main()
{
    string title;
    float rating;
    int vL;
    int words;

    //For Video
    title = "Sonic.exe";
    rating = 4;    //Considering it to be out of 5 star
    vL = 7;
    StGamerVids gamer1(vL,title,rating);

    gamer1.display();

    //For Text :
    title = "Sonic.exe";
    rating = 2.5f;    //Considering it to be out of 5 star
    words = 500;
    StGamerWeb gamer2(words, title, rating);
    gamer2.display();
    //Till here , there will be no problem even without virtual function

    //Now using pointers to check our virtual function .
    StGamer *tuts[2] ;   // Making 2 "pointers" of type StGamer , that store only addresses , can be like : tuts[i]->display()
    //StGamer *tuts = new StGamer[2] allocates two objects of type StGamer , here i can't use tuts[i]->diaplay();


    tuts[0] = &gamer1;  //This pointer points to first object. You cannot write it like normal array of objects being pointed like tut = &gamer1. but here there are pointers in the array so writing tut[0] gives us first pointer and *tut[0] will give the value pointed by it
    tuts[1] = &gamer2;  //This pointer points to 2nd object


    //Magic of Virtual Functions :

    (*tuts[0]).display(); //This line is equivalent to tuts[0]->display();
    (*tuts[1]).display(); //This line is equivalent to tuts[1]->display();



    return 0;
}


/*
Rules :

They cannot be static member functions
They are accessed by object pointers
Virtual functions can be a friend function of another class
A virtual function in base class might not be used but be useful for derived class
If a virtual function is defined in a base class , then there is no necessity of redefining it in derived class again. You can use the same virtual function of base class.


//If we have a lot of derived classes in any type of inheritance then we only need to use virtual with the first one or the function which you want to become virtual so that the rest of the below of that will be affected only leaving the upper as normal.
//The virtual function overwritten also depends on the class of the pointer . If the pointer is of first base class pointing to last derived class and there are many derived classes in between and the last derived has 2 base classes , then the first base class pointer can only use its own function and the function overwritten by last derived class.
//The First Base Class can still not access the Derived Class other member functions unless they are virtual in Base (or by using dynamic and static_cast)


*/








/*
// It shows that only one virtual function is needed even if there are many derived classes.
class A
{

/*
    This will work fine for pointer b to object of c as private members are inherited so virtual will allow the say() to invoke derived say() CAT.
private :
    virtual void say()
    {
        cout<<"I am an Animal"<<endl;
    }


public :
    virtual void say()
    {
        cout<<"I am an Animal"<<endl;
    }
};

class B : public A
{
    public :
     void say()
    {
        cout<<"I'm a Bat"<<endl;
    }

};

class C : public B
{
    public :
    void say()
    {
        cout<<"I am a Cat"<<endl;
    }

};

int main()
{
    A *ptr_a;
    C c1;
    B b1;
    A a1;
    ptr_a = &c1;
    (*ptr_a).say();

    B * ptr_b;
    ptr_b=&c1;
    (*ptr_b).say();

    return 0;
}
*/

//Another Example Explained :

/*
Suppose : Base→Derived_1→Derived_2→Derived_3
Let print() be a virtual function defined in Base and overridden in all derived classes.
When you write :

// 1. Create an object of the last derived class
Derived3 d3_obj;

// 2. Create a pointer of the base class type
Base* ptr_base = &d3_obj; // Base pointer points to Derived3 object


    Then:

When you call ptr_base->print():

The compiler sees that print() is a virtual function.

It looks at the memory of the object being pointed to (the Derived3 object).

It reads the address of the object's vtable.

The Derived3 vtable contains the function pointers for all virtual functions, including the address of Derived3::print().

The call is dispatched directly to Derived3::print().

*/

//All this happens at runtime







//Can skip if you want :
//Remember Reference Variables like : int &x = y , now x and y are same variables or aliases of each other
//Virtual functions can also be used by using reference variables without pointers (in the same way as pointers )
// E.g : A a ; B b; &a = b;
//Demonstration :
/*
//This shows how to use virtual functions but without pointers of base or derived class objects for runtime polymorphism.
#include <iostream>
using namespace std;

class Base
{
public:
    // Virtual function
    virtual void show()
    {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base
{
public:
    // Override virtual function
    void show()
    {
        cout << "Derived class show()" << endl;
    }
};

void display( Base& obj) // Base &obj = object given as argument from function call
{
    obj.show(); // Virtual function call
}

int main()
{
    Base b;
    Derived d;

    display(b); // Calls Base::show()
    display(d); // Calls Derived::show(), resolved at runtime

    return 0;
}
*/


//Another Example further explaining this :
/*
class Base
{
public:
    virtual void greet() const
    {
        std::cout << "Base greeting!\n";
    }
    // Note: The destructor should also be virtual in a polymorphic base class
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void greet() const override
    {
        std::cout << "Derived special greeting!\n";
    }
};

void call_greeting(Base& obj)
{
    // Because 'obj' is a reference to Base, and 'greet' is virtual,
    // the call is dynamically dispatched based on the actual object type.
    obj.greet();
}

int main()
{
    Derived d;

    // Create a reference to the Base class, referencing the Derived object
    Base& ref_to_derived = d;

    // 1. Direct call via the reference
    ref_to_derived.greet(); // Output: Derived special greeting!

    // 2. Call via a function that accepts a Base reference
    call_greeting(d);       // Output: Derived special greeting!

    return 0;
}

*/





//Use of Const and Override :
//Normally using const after functions ensure that object's data will not be changed , constant
/*
void draw() const
{
    std::cout << "Drawing a generic shape.\n";
}
*/

//But when we want that the function that replaces the virtual one in base class , we use override although without override it works , we still ensure if there were any mistakes writing the function signature in the other functions replacing virtual one
//Function to be replaced :
/*
virtual void draw() const
{
    std::cout << "Drawing a generic shape.\n";
}

Function that replaces :
void draw() const override
{
    std::cout << "Drawing a Circle with radius " << radius << ".\n";
}
*/
//Using const with override was only done because base class function had const otherwise simple override was enough


