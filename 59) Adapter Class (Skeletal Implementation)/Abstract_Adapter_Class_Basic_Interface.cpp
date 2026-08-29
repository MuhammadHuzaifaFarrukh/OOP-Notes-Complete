#include <iostream>

using namespace std;

/*
Skeletal Implementation (OOP Architectural Idiom in LLD)
LLD Focus: Used when designing class hierarchies and custom libraries (e.g., defining an AbstractList base class that implements standard search/iteration methods, allowing derived classes like ArrayList or LinkedList to only implement core storage functions).
Goal: Code reusability and minimizing boilerplate across concrete class implementations.
*/

class A // This one will be Abstract Class (Interface Level)
{
public:
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
};
class B : public A // This one will be an Abstract Adapter Class
{
public:
    // Contains all functions empty implementation so that it is Abstract no more
    void f1() override {}
    void f2() override {}
    void f3() override {}
    void f4() override {}
    void f5() override {}
    void f6() override {}
};
// Now write the class you want to use inherited from adapter class and implement any of the functions from above you want to and leave the rest as it is

/*
Class B provides default empty implementations for an interface (Class A) so that derived classes only need to override the specific methods they care about.
Intent: Reduce boilerplate code when inheriting from a large interface.
Classic Example: Java's MouseAdapter or WindowAdapter.
In GUI frameworks, the MouseListener interface has 5 methods (mouseClicked, mousePressed, mouseReleased, mouseEntered, mouseExited).
Instead of implementing all 5 every time, you inherit from MouseAdapter (which has empty bodies for all 5) and only override mouseClicked.
*/

int main()
{
    return 0;
}
