#include <iostream>
#include <string>

using namespace std;

class ClassB
{
private:
    string b_data;
public:
    ClassB(string val) : b_data(val) {}

    // Getter for ClassA to use
    string getData() const
    {
        return b_data;
    }
};

class ClassA
{
private:
    string a_data;
public:
    ClassA() : a_data("Empty") {}

    // CUSTOM CONVERSION CONSTRUCTOR
    // This allows: ClassA objA = objB;
    ClassA(const ClassB& objB)
    {
        cout << "Conversion Constructor called: Transforming ClassB to ClassA" << endl;
        this->a_data = objB.getData();
    }

    void display()
    {
        cout << "ClassA Data: " << a_data << endl;
    }
};

int main()
{
    ClassB objB("Hello from B");

    // This looks like assignment, but it's actually INITIALIZATION.
    // It calls the constructor: ClassA(const ClassB& objB)
    ClassA objA = objB;
    objA.display();

    return 0;
}
