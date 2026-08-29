#include <iostream>
using namespace std;

/*
What the Classic Adapter Pattern Actually Is ?
The true GoF Adapter Pattern bridges two incompatible, existing interfaces without changing their source code. 
It wraps an existing class (the Adaptee) inside a new class (the Adapter) to translate requests from a target interface.
*/

// 1. Target Interface (What your system expects)
class TargetPrinter
{
public:
    virtual void printDocument() = 0;
};

// 2. Adaptee (An existing/legacy class with an incompatible interface)
class LegacyPrinter
{
public:
    void printInOldFormat()
    {
        cout << "Printing via legacy driver..." << endl;
    }
};

// 3. Adapter Class (Translates Target interface -> Adaptee method)
class PrinterAdapter : public TargetPrinter
{
private:
    LegacyPrinter *legacyPrinter; // Holds a reference/pointer to the Adaptee

public:
    PrinterAdapter(LegacyPrinter *lp) : legacyPrinter(lp) {}

    void printDocument() override
    {
        // Translates the call to the legacy method
        legacyPrinter->printInOldFormat();
    }
};

int main()
{
    LegacyPrinter oldPrinter;
    TargetPrinter *printer = new PrinterAdapter(&oldPrinter);

    // Client calls standard interface, Adapter translates it behind the scenes
    printer->printDocument();

    delete printer;
    return 0;
}