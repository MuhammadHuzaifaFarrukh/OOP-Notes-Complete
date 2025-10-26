#include <iostream>

using namespace std;

//Operator Overloading refers to define operators in such a way that they can do other functions besides their own task
//This is used in classes where we want to perform operations on class objects multiple times with their data members as well

//E.g for doing addition of all data members of a class , we want add operator to work like this : class a = a+b;

class A
{
    int a;
public :
    void setData()
    {
        cout<<"Enter a number : " ;
        cin>>a;
    }
    void getData()
    {
        cout<<"Value = "<<a<<endl;
    }
    A operator+(A &);


};

//Arithmetic operators while overloading should have return type as the class object 
//We may keep it void as well , but then we cannot return a copy of the object
//We can also return a reference to the object , but then we cannot return a copy of the object
A A::operator+(A &a2 )
{
    A a3;
    a3.a = a + a2.a;
    //a3.a = a+a2.a+a2.a; won't give any error .
    return a3;
}

int main()
{
    A a1,a2,a3;
    a1.setData();
    a2.setData();


    a3 = a1+a2; // a1 calls the a2 function and store the copy obtained from function in a3 , like a1.operator+(a2) and returning copy using copy constructor by compiler generated and then stores it in a3
    //a3 = a1+a2+a2 won't give any error as a2 is already specifier there


    a1.getData();
    a2.getData();
    a3.getData();


    return 0;
}












/*
//The Return types here can differ , for similicity , we keep it void
//However , you can return a copy of the object or a reference to the object as well

For Prefix like ++aa , --aa
void operator++()
{
    a=a+1;
}
*/





/*
//The Return types here can differ , for similicity , we keep it void
//However , you can return a copy of the object or a reference to the object as well

For Postfix like aa++ or aa--
void operator++(int)
{
    a=a+1;
}
*/




/*
//Here we should use a reference to object to get chaining of objects like a1=a2=a3 and so on
//Just because it is just like copy assignment operator.
//For simplicity , we keep it void

For =  , a1= a2
void operator=(A &a2 )
{
    a = a2.a;
    b = a2.b;
}
*/




/*
//The Return types here can differ , for similicity , we keep it void
//However , you can return a copy of the object or a reference to the object as well


For += , -=. *= , /=  , a1 += a2
void operator+=(A &a2 )
{
    a = a+a2.a;
}
*/



//Inside operator overloading , we can do more overloading on the basis of number of paramters and the data types used in the paramters.

//Return types : 
//For == , != , < , > , <= , >= , we can return a boolean value
//For + , - , * , /,% we can return a copy of the object or a reference to the object as well
//But for +,-,*,/,% only and storing in another object , we can return a copy of the object (not by reference)
//For using these temporarily , we return the copy of the object (not by reference)
//For chaining like (a+b).function_call() , we return a copy of the object (not by reference)
//For making change in the operand instead of another value , we return a reference to the object 


//For += , -=, *= , /= , we can return a reference to the object
//For = , we can return a reference to the object just for chaining like a=b=c (Like copy assignment operator)
//For prefix ++ , -- , we can return a reference to the object
//For postfix ++ , -- , we can return a copy of the object (not by reference) to get the old value before incrementing or decrementing
//For relational operators , we can return a boolean value
//For bitwise operators , we can return a copy of the object (not by reference) or a reference to the object or any other data type that we think suitable for the answer and this rule is applied on the normal +,-,/,%,* and += etc and ++ operators as well if we want to store only this calculation data in a variable not object , then we use int etc data types in return otherwise we use objects return type as specified above and here

//We can also overload () , called functors , and its return type can be anything like void, int, float, double, char, string, etc.
//For [] , we can return a reference to the object or reference to int , float etc otherwise it might create errors
//For * dereference operator , we return a reference to the object by & or reference to other data types
//For & address of operator , we return a pointer to the object by * , or other data types
//But when we overload & , it is no longer for seeing addresses of normal variables or data types
//So we can use std::address_of() to get the address of the object

//-> operator is also overloadable , we return a pointer to the object by * or other data types
//For comma operator , we can return a reference to the object or a copy of the object (not by reference) or any other data type that we think suitable for the answer
//For type casting operators , we can return a reference to the object or a copy of the object (not by reference) or any other data type that we think suitable for the answer
//For new  operator, we can return it void pointer or other
//For delete operator , we can return it void or any other data type that we think suitable for the answer
//For new[] operator, we can return it void pointer or any other data type that we think suitable for the answer
//For delete[] operator , we can return it void or any other data type that we think
