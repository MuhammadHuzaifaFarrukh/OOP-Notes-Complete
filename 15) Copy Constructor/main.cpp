#include <iostream>

using namespace std;



class number
{
private:
    int a;
public:

    //number(){} is just a blank constructor if below one is not used. It will only initialize random values for all member variables if they are not initialized for the object
    number()  // This one will initialize the member variable a for all objects if they have not initialized it yet.
    {
        a=3;
    }

    number(int );
    number(number &); //Copy Constructor , You need to delete this and definition if you want to generate the compiler copy constructor.But if we only write a copy constructor , then compiler will generate an error
    //Using const is generally good as without it :
    void display();

};



number::number(int num)
{
    a=num;
}

//When no copy constructor is found then compiler supplies its own copy constructor , but without any message that would have been in your own one . You must provide class name in the formal parameter of the constructor for this and address as well
//Also compiler generated copy constructor leads to problems when we have dynamically allocated member variables , so its better to create your own in these cases

number::number(number &obj )  //We pass object reference here , it is necessary and writing const with it makes a good practice. Pass by value involves copying object and this invokes the copy constructor for that dummy object but again , copy constructor is called for that dummy object's dummy object and it becomes a recursion so pass by reference avoids this recursion.
{ //Pass obj by value and in case we don't have our own copy constructor , compiler's generated  one will work perfectly when passing value in other functions
  //but if we have our own copy constructor , then this one is used to copy the pass by valued object so it will still work for other functions but not when using own copy constructor and doing pass by value inside it

    cout<<"Copy Constructor has been Called Successfully ! "<<endl;
    a=obj.a;  // We need obj.a as obj.a is int and a is also int , whereas obj itself is a refernce to the object n3. This point will be the recursive point if you don't write & sign in formal parameters.
}

void number::display()
{
    cout<<"The Number for this Object is  : "<<a<<endl;
}

int main()
{
    number n1,n2,n3(45), n5(60);
    n3.display();
    n2.display();
    n1.display();


    number n4(n3);  //n4 becomes just like n3
    n4.display();
    n5=n3;   //Copy Constructor Not Invoked , Copy Assignment Operator used which is discussed in deep vs shallow copy
    //The Above line will give no errors and still assign values but not by using copy constructor
    //Copy Constructor is only used to assign values to a brand new object from a previously made object

    number n6 = n3; //Copy Constructor Invoked
    n6.display();

    return 0;
}


/*
If in a situation where you have no constructor and no copy constructor then compiler will first use default constructor
of its own to give random values to member variables and then use copy constructor from its default constructor to
give same random values when any syntax of copy constructor is used .

If you have only copy constructor then compiler will create error for normal objects initialization as it will try to use this constructor for the normal
objects also.

//It is not suitable for situations where there is no copy constructor and we pass by value and we have calculations like dynamic allocations and arrays etc so if pass by value then make your own copy constructor or use pass by reference
//There may be some cases or more where there is no copy constructor and pass by value also does not throw any error and works fine . But be careful while doing this for large objects

*/





//Copy Assignment Operator : (Used in Shallow Copy)
/*
This is a call to the Copy Assignment Operator (or overloaded assignment operator).
Signature: Number& operator=(const Number& obj)

This is called when an object that already exists is assigned the value of another existing object.
e.g above : Number n1 , n2 ; n1 = n2;
*/











