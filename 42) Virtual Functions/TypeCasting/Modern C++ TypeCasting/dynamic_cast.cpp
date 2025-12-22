#include <iostream>

using namespace std;


class Printer
{
public:
    virtual void print()
    {
        cout << "Print\n";
    }
};
class Inkjet : public Printer
{
public:
    void print()
    {
        cout << "Inkjet Print\n";
    }
};
class Bubblejet : public Printer
{
public:
    //int x = 20;
    void print()
    {
        cout << "BubbleJet Print\n";
        Printer::print();
    }
    void test()
    {
        cout << "Test of BubbleJet\n";
        //x= x*2;
    }
};

int main()
{
    //While static_cast relies on compile-time logic, dynamic_cast is the only cast that works at runtime.
    //It is specifically designed to handle polymorphism
    //dynamic_cast cannot be used with normal data types like int, float, char, or even simple
    //structs that don't have virtual functions.
    //For Dynamic Cast to work , your class must atleast have one virtual function
    //If you try to use dynamic_cast on a non-polymorphic class, the compiler will throw an error.

    //The "magic" of dynamic_cast is that it checks the Run-Time Type Information (RTTI).
    //Inside the Vtable is a structure called RTTI (Run-Time Type Information).
    //dynamic_cast checks this RTTI to verify if the object is truly the type you are asking for.

    //This is the safest way to Downcast (move from Parent to Child).
    //Success: It returns the valid address of the derived object.
    //Failure: It returns nullptr (if casting pointers) or throws an exception (if casting references).

    //1) Down Casting
    Printer *p = new Bubblejet;
    Bubblejet *b = dynamic_cast<Bubblejet *>(p);

    if (b)
    {
        cout << "Success! p is actually a Child." << endl;
        b->print();
    }
    else
    {
        cout << "Failure! p is NOT a Child." << endl;
    }
    //Here it works.


    cout<<"\n\n\n";
    //2) Down Casting but dangerous one (Totally a type mismatch which static cast couldn't detect)
    Printer *p1 = new Printer;
    Bubblejet *b1 = dynamic_cast<Bubblejet *>(p1);
    //Here b1 wants a Bubblejet object , not any other object

    if (b1)
    {
        cout << "Success! p1 is actually a Child." << endl;
        b1->print();
    }
    else
    {
        cout << "Failure! p1 is NOT a Child." << endl;
    }


    return 0;
}
