#include <iostream>
using namespace std;

// Class A
class Scanner
{
public:
    virtual void scan()
    {
        cout << "Scanning..." << endl;
    }
    virtual ~Scanner() {} // Must be virtual for dynamic_cast
};

// Class B
class Printer
{
public:
    virtual void print()
    {
        cout << "Printing..." << endl;
    }
    virtual ~Printer() {}
};

// Class C
class SmartDevice : public Scanner, public Printer
{
public:
    void scan() override
    {
        cout << "Smart Scan" << endl;
    }
    void print() override
    {
        cout << "Smart Print" << endl;
    }
};

int main()
{
    // We create a SmartDevice but store it in a Scanner pointer
    Scanner* scannerPtr = new SmartDevice();

    // SIDE-CAST: Move from Scanner* to Printer*
    // These are sibling classes, not parent/child to each other!
    Printer* printerPtr = dynamic_cast<Printer*>(scannerPtr);

    if (printerPtr)
    {
        cout << "Side-cast successful!" << endl;
        printerPtr->print();
    }
    else
    {
        cout << "This device cannot print." << endl;
    }
    //This also works the other way as well i.e from Printer* to Scanner*
    //This wouldn't be possible with static cast as static cast will throw error on completely separate / different types
    //Dynamic Cast here doesn't and allows Side-Casting

    delete scannerPtr;
    return 0;
}
