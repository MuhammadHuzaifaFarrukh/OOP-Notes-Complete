#include <iostream>

using namespace std;

//using keyword in C++ has multiple uses in inheritance:
//1) It can be used in the multilevel and multiple inheritance to solve ambiguity. (explained in the main.cpp of (26)  )
//2) It can be used in classes to make protected to public for the variables and functions
//However it cannot change the access of the constructor , i.e a constructor remains whatever it was in previous class in inheritance

class A
{
private:
    int y;
protected:
    int x;
    void fun()
    {
        cout<<"I'm fun from class A"<<endl;
    }
    A(){}
public:


};

class B : public A  //Doesn't matter if it is public or private or protected
{
public:
    //You may Resolve Ambiguity like this plus change the visibility as well
    //As the scope written is public , hence fun() and x are public now inside B class
    using A::fun;
    using A::x;
    //No need for the constructor as they are already called explicitly along the Derived class
};

int main()
{
    B b1;
    b1.fun();

    return 0;
}
