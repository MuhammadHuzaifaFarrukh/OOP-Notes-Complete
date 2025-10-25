#include <iostream>

using namespace std;

//Constructor has the same name as the class name . It is a special member function
//It is used to initialize the objects of its class
//Automatically invoked whenever object is created
//It has no return type and cannot return a value
//It should be put in the public access
//If we don't create a constructor then compiler provides us a default constructor of the form :

//Complex() {} // This is what the compiler implicitly creates if we don't create one
//If we create a constructor , of any arguments or type then compiler doesn't provide us with this default constructor above
//The type of constructor which compiler usually makes for us is a blank constructor but we call it default as it initalizes all values to default / garbage
//Compiler defined default/blank constructor sets the values to their default , but if we make non-parameterized constructor and do nothing in it , then the values are not init to default although this one is also a blank constructor but by user this time
class Complex
{
private :
    int a,b;
public :
    Complex();
    void printdata()
    {
        //We can put objects inside member functions or constructors
        cout<<"Your number is : " <<a<< " + i"<<b<<endl;
    }
};

//A constructor has 2 types :
//1) Default Constructor which takes no paramters (Can be of compiler or ours)
//2) Parameterized Constructor which takes paramters
//3) Copy Constructor
//4) Move Constructor


Complex :: Complex()//Default Constructor : No Formal Parameters
{
    //If it was a compiler generated then it would have done nothing inside the constructor as we did
    a=0;
    b=0;
    //We can put objects inside member functions or constructors
}

int main()
{
    Complex c1,c2,c3; //For many objects , default constructor runs for object c1,c2,c3 , and Destructor runs as c3,c2,c1 (Later discussed)
    c1.printdata();
    c2.printdata();
    c3.printdata();


    //Default Constructor by user takes no arguments but can perform some operations in that function
    //Default Constructor by compiler is blank constructor that takes no arguments and does nothing except initializing the values of class members to zero (in most cases though not guaranteed) or randomly (garbage)
    //If user makes his own default constructor (non-paramterized) then blank constructor is not required
    //If user makes both default constructor that does something and a blank constructor then it gives errors




    //Parameterized constructors are simply the constructors that use parameters like any other function
    //If we use paramterized or design any other type of constructor then compiler doesn't make the blank (default) constructor for us
    //For this purpose , you should make a default or blank constructor by yourself whenever using the parameterized one

    //Also it is not mandatory that the blank (default) constructor by compiler or a default / blank by user with no operations in it will set the values of class member variables to zero as it sets them random (garbage) as well
    //Though in most cases , the compiler's blank constructor sets values to their default values , if user makes his own with nothing in it , then it will surely give random values
    return 0;
}
