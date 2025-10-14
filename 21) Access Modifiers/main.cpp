#include <iostream>

using namespace std;

// There are 3 Access Modifier  - Public - Private - Protected .
//  Public and Private are already discussed.
// Private Members are never inherited (still exist in derived obj) and can't be accessed directly except inherited member functions of base class in derived obj
// Public Members are inherited and they can be private , public , protected in the same way as visibility mode changes
//--------------------------------------------------------------------------------------------------------------------
// Protected Visibility Mode
// Private Members of Base Class are not inherited (still exist in derived obj)
// Protected and Public Members of Base Class are Protected in Derived Class. They can be used for further inheritance but private access
// Public Members become protected members meaning that they can be inherited if any further inheritance is used unlike private members and can also be accessed using the derived member functions , not by their base functions

class Base
{
private:
    int a; // Never ever inherited (still exists)

protected:
    int b; // It is private (not direct access) but now can be inherited  so it is protected
    // Meaning that when we need to access 'b' of Base , we can do it using Derived class methods , not by using inherited Base Class methods
public:
    int c = 4; // Here it is accessible meaning that objects of Base can access it directly
};
/*
class Derived : protected Base
{
  private:

  public:

  protected:
       //Here , our inherited public members 'c'  and 'b' will become protected and inaccessible. Here Derived objects cannot access b or c directly. But they are available for further inheritance. They can be accessed using this class' public member function

};*/

// Private Access Modifier :
// Private remains private (not inherited , still exists)
// Public becomes private
// Protected becomes private

/*
class Derived : private Base
{
  private:

  public:

  protected:
       //Here , our inherited public members 'c'  and 'b' will become private and inaccessible. Here Derived objects cannot access b or c directly and not available for further inheritance.
       //Still derived's public methods can access these inherited members

};*/

// Public Access Modifier :
// Private remains private (not inherited , still exists)
// Public remains public
// Protected remains protected 
class Derived : public Base
{
private:
public:
    // Here , our inherited public member 'c' is still accessible.
protected:
    // Here , our inherited public member 'b' will become protected and inaccessible.We need to access it through public methods .
};

int main()
{
    Base obj1;
    Derived obj2;

    //  cout<<obj1.a<<endl; You can't access private members directly
    // cout<<obj1.b<<endl; You can't access protected members directly as well but through public methods (functions)
    // cout<<obj1.c<<endl ; Accessible as it is a public member of Base class
    // cout<<obj2.a<<endl; Private Members are never inherited (access using base object's inherited methods)
    // cout<<obj2.b<<endl;  Use any public methods of derived class to access it (not directly)
    // cout<<obj2.c<<endl; Accessible if it is Public mode and not if it other mode

    return 0;
}
