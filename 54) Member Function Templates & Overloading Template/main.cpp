#include <iostream>

using namespace std;

//Overloading Template Functions :
//It can be either done by non-templates or template functions or combination of these.

//In the below example , we have 1 normal function and 2 template functions.
//So if we put float arguments , then it will run the first function
//If we put any other arguments except float but 2 or 3 then the below functions will execute.
//If the no of arg and data type of arg of non-template and template function is same then non-template function will execute.
//THe Non-Template functions are given priority in case of no of arg and data type becomes same


//Sometimes while overloading data types of float and int are interchangeable when we write a float as integer value , this happens for more data types like double and int etc


void func(int a, float f2) //If both are float , then (2.5f , 2.5f) will call this one instead of the below one as stated in above points
{
    cout<<"Normal function with two arguments : "<<a<<" and " <<f2<<endl;
}

template <typename T>
void func(T x, T y)
{
    cout<<"Template function with two  arguments : "<<x<<" and " <<y<<endl;
}

template <typename T >
void func(T x, T y, T z)
{
    cout<<"Template function with three  arguments : "<<x<<" , " <<y<<" and " <<z<<endl;
}

int main()
{
    func(2,2);  //Invokes second function
    func(2,2.5f); //Invokes first function
    func('c', 'j');  //Invokes second function
    //func('c', 3);  //Invokes first function with 'c' as ASCII Code
    func("Hello", "Guys", "Welcome");   //Invokes the third function

    return 0;
}
