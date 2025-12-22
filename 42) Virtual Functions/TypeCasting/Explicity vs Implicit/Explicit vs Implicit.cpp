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
    //Implicit Type Casting :
    //Normal type casting that we usually do :
    Printer *p = new Bubblejet();       //This is done Implicitly
    p->Printer::print();


    //Explicit Type Casting (Here done in C-Styled Way) :
    Bubblejet *b = new Bubblejet();
    delete b;
    //b = p;    //Throws Error as we cannot assign base pointer to a derived pointer
    b = (Bubblejet *)p;
    b->test();

    delete p;
    cout<<endl<<endl;

    //Dangerous in this case :
    Printer *p1 = new Printer;
    Bubblejet *b1 = (Bubblejet *)p1;
    b1->test();     //C-Styled Type casting doesn't point out these type of errors , like we assigned a Parent Object to a Child Pointer which is wrong but here allowed due to C-Styled Type-Casting

    delete p1;

    return 0;
}
