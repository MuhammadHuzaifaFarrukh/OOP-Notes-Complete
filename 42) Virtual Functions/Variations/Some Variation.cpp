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
    void print()
    {
        cout << "BubbleJet Print\n";
        Printer::print();
    }
    void test()
    {
        cout << "Test of BubbleJet\n";
    }
};

int main()
{
    Printer *p = new Inkjet;
//    p -> print();
    p = new Bubblejet;
//    p -> print();
    Bubblejet *b = (Bubblejet*)p;       //b now points to where p points ,
    //Here 'b' is down-casted , two pointers pointing to same location
    //Here we must specify the type else it will give errors
    b->print();
    b -> test();
    b -> Printer::print();
    return 0;
}
