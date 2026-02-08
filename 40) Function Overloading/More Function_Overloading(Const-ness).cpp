#include <iostream>
#include <string>

using namespace std;
class MathBox
{
private:
    int value;

public:
    MathBox(int v) : value(v) {}

    // 1. CONST MEMBER FUNCTION OVERLOADING
    // This is called when the object is NOT const.
    void showValue()
    {
        cout << "Non-const member function: " << value << endl;
    }

    // This is called when the object IS const.
    void showValue() const
    {
        cout << "Const member function: " << value << endl;
    }
};

// 2. PARAMETER OVERLOADING (References)
// The compiler can distinguish between a reference that can modify data and one that cannot.
void printInfo(string &s)
{
    cout << "Non-const reference: " << s << endl;
}

void printInfo(const string &s)
{
    cout << "Const reference: " << s << endl;
}

// 3. TOP-LEVEL CONST (The "Trap")
/* void check(int x) { ... }
void check(const int x) { ... }
// ERROR: The above two are seen as the same because 'x' is a copy.
// The compiler ignores 'const' for parameters passed by value.
*/

int main()
{
    // --- Member Function Overloading ---
    MathBox mutableBox(10);
    const MathBox constantBox(20);

    mutableBox.showValue();  // Calls non-const version
    constantBox.showValue(); // Calls const version

    // --- Parameter Overloading ---
    std::string msg = "Hello";
    const std::string c_msg = "World";

    printInfo(msg);   // Calls printInfo(std::string&)
    printInfo(c_msg); // Calls printInfo(const std::string&)

    return 0;
}