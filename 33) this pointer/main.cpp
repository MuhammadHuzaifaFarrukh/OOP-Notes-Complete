#include <iostream>

using namespace std;

//Every non-static member function of a class or struct has an implicit, constant this pointer
//that points to the specific object on which the function was called.

/*
"this" pointer exists in every member function only when called

When you call a non-static member function on an object (e.g., myObject.doSomething();), the compiler translates
this into a function call where the address of myObject is secretly passed as a hidden first argument.

Inside the doSomething() function, this hidden argument (the address of myObject) becomes the special
local variable named "this". This argument is what the method sees as the this pointer.

*/

//The this pointer exists only for the duration and scope of the non-static member function call.

//this pointer is usually passed implicitly if we don't specify it :
/*
void Car::setSpeed(int newSpeed)
{
    speed = newSpeed; // No 'this' used explicitly
}
*/

//Explicit call involves writing "this" keyword.
// "this" stores the object address
// (*this) or (this->) derefernces the address i.e it gives the object
// Can be used to distinguish the objects member variables from the local ones with same names (local shadows member variables)
// Can be used to make / call long chains of functions for any object (return type must be a reference object)
// If we use normal object as return type then first function in the chain will work but others will give leave the original object untouched making our answer as the first function



class A
{
private :

public :
    int a,b;
    A& setdata(int a, int b) // Here & is must as we are returning a refernce of the object (original object) , otherwise a modified copy of the object will be returned which will change nothing in the further long chain in our original object
    {
        //this pointer here distinguishes between the member variables and the local ones
        this->a = a;
        this->b=b; // or         (*this).b=b; We can also write A::b which can resolve ambiguity


        // return this; //Will cause error as this is a pointer storing address. We need the value at "this" so we use " * ".
        return *this ;
    }


    void getdata()
    {
        cout<<"The Value of a is : " << a<<endl;


    }

    /*
    //We can further make more functions and return objects and call more functions with a dot making it chaining method calls
    A& getdata() // Here a function that returns reference (var) of A type
    {
        cout<<"The Value of a is : " << a<<endl;
        return *this;
    }

    void say()
    {
        cout<<"SAY"<<endl;
    }
    */

};

int main()
{
    A obj1, b;
    obj1.setdata(5,6).getdata();//This will replace obj1.setdata(5) by the object returned by "this"
    //obj1.getdata();

    //obj1.setdata(5).setdata(50) ; Still fine , changes are made in the original obj but not stored in any other object
    //obj1.setdata(5).getdata().say(); //This will replace obj1.setdata(5) by the object returned by "this" . And another function will run with this as well.

    //b=obj1.setdata(5);  //obj1.setdata(5) will get replaced by the object returned by "this". Now this value is given to object 'b' making it a copy of obj1 but at another memory location.

    //b.getdata();

    return 0;
}









//RETURNING OBJECT WITH OBJECT RETURN TYPE :
//When doing this , then remember that if you place & sign with return type object then it will only return reference
//This will be dangerous if you return a local object from there
//Return using "this" , as doing this will only return the object for which it was being called


//RETURNING OBJECT WITH OBJECT RETURN TYPE WITHOUT & : (Can be Member Function or Not)
//This is safe if we use any local objects inside our function and return it as it returns the copy of the object by using copy constructor there
//Can also use return (*this) (MEMBER FUNCTION)


//Each time the changes made will be made , make sure to store them in the object as the original one might not be affected if we wanted
