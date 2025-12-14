#include <iostream>

using namespace std;

class Shape
{
public:
    //Either this virtual ~Shape() = default; or the below with definition also
    virtual ~Shape() = 0;   //Must be defined outside else the child classes objects will not be made and throw errors on creation

};

Shape::~Shape()
{
    cout<<"Shape's Virtual Destructor Called "<<endl;
}
//If you don't define it here , the other classes will become abstract base classes , and even if you define the destructors
//in further child classes , that won't solve the problem
// Derived Class 1
class Circle : public Shape
{
public:
    //Virtual Destructor is inherited here so optional to make here

};

// Derived Class 2
class Rectangle : public Shape
{
public:
    //Virtual Destructor is inherited here so optional to make here

};

int main()
{
    Rectangle r1;

    return 0;
}
