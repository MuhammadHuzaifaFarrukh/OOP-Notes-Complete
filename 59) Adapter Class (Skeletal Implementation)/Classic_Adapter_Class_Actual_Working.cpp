#include <iostream>
using namespace std;

/*
What the Classic Adapter Pattern Actually Is ?
The true GoF Adapter Pattern bridges two incompatible, existing interfaces without changing their source code.
It wraps an existing class (the Adaptee) inside a new class (the Adapter) to translate requests from a target interface.
Uses Inheritance or Composition unlike Container Adapter that use C++ Templates (Compile time).
Connects two pre-existing, incompatible interfaces unlike the STL Container Adapters that creates a brand-new, minimal interface for a container e.g stack (adapter) can be made to use vector/list/deque (adaptees) etc.


Adapter Pattern (Structural LLD Pattern)
LLD Focus: Used when integrating third-party APIs or legacy modules or library into a new class design (e.g., adapting a legacy PaymentGateway interface to work with a unified IPaymentProcessor interface).
Goal: Interface compatibility without modifying existing source code.
Relies on Dynamic Polymorphism (Not for the STL Container Adapter).
*/
// Interface => Adaptee (Full Implemented / Incompatible System) => Adapter (Translator)

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
