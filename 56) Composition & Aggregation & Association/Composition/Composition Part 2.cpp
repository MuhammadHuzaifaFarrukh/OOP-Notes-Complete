#include <iostream>
using namespace std;

class B
{
private:
    int value;
public:
    B(int val) : value(val)
    {
        cout << "B Constructor: " << value << endl;
    }

    ~B()
    {
        cout << "B Destructor: " << value << endl;
    }

    void display() const
    {
        cout << "B value: " << value << endl;
    }

    void setValue(int val)
    {
        value = val;
    }

    int getValue() const
    {
        return value;
    }
};

class A
{
private:
    B b_obj;  // COMPOSITION - B object as direct member
    string name;

public:
    // ✅ SAFE: Direct initialization in member initializer list
    A(string n, int val) : b_obj(val), name(n)
    {
        cout << "A Constructor: " << name << endl;
    }

    // ✅ SAFE: Copy constructor (automatic B copy)
    A(const A& other) : b_obj(other.b_obj.getValue()), name(other.name + "_copy")
    {
        cout << "A Copy Constructor: " << name << endl;
    }

    ~A()
    {
        cout << "A Destructor: " << name << endl;
        // ✅ Automatic: b_obj destructor called automatically after this
    }

    void display() const
    {
        cout << "A name: " << name << " | ";
        b_obj.display();
    }

    void modifyB(int newVal)
    {
        cout << "Modifying B value from " << b_obj.getValue() << " to " << newVal << endl;
        b_obj.setValue(newVal);
    }

    // Access B's functionality through A
    void useB() const
    {
        cout << "Using B through A: ";
        b_obj.display();
    }
};

// Function demonstrating composition safety
void testFunction()
{
    cout << "=== INSIDE testFunction() ===" << endl;

    // ✅ SAFE: Local composition - automatic lifetime management
    A localA("LocalA", 100);
    localA.display();

    cout << "=== LEAVING testFunction() ===" << endl;
    // Automatic destruction in reverse order of construction
}

int main()
{
    cout << "=== COMPOSITION DEMO - SAFE OBJECT LIFETIME ===" << endl;

    // ✅ SAFE 1: Direct composition initialization
    cout << "\n1. Creating A with composed B:" << endl;
    A a1("MainA", 42);
    a1.display();

    // ✅ SAFE 2: Copy works correctly
    cout << "\n2. Copying A (B is also copied):" << endl;
    A a2 = a1;  // Copy constructor
    a2.display();

    // ✅ SAFE 3: Modification through interface
    cout << "\n3. Modifying B through A:" << endl;
    a1.modifyB(999);
    a1.display();
    a2.display();  // a2 remains unchanged (independent copy)

    // ✅ SAFE 4: Function scope demonstration
    cout << "\n4. Testing function scope:" << endl;
    testFunction();

    // ✅ SAFE 5: Array of composition objects
    cout << "\n5. Array of A objects:" << endl;
    A arr[2] = {A("ArrayA1", 1), A("ArrayA2", 2)};
    for(int i = 0; i < 2; i++)
    {
        arr[i].display();
    }

    cout << "\n6. End of main - automatic destruction begins:" << endl;

    return 0;
}
