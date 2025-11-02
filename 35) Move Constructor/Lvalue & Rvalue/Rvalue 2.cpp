// RVALUES AND RVALUE REFERENCES (&&)

#include <iostream>

using namespace std;
// An Rvalue is a temporary value, usually the result of an expression,
// which is about to be destroyed and has no persistent identity (cannot take its address).

// --- 1. Rvalue Binding to Rvalue Reference (T&&) ---

// T&& binds exclusively to Rvalues (temporaries or results of std::move()).
// T&& extends the Rvalue's lifetime to the lifetime of the reference variable.

int getValue()
{
    return 5;
}

int main()
{

    // a) Binding a temporary expression:
    // (1 + 2) is a prvalue (a pure rvalue)
    int&& rref1 = 1 + 2;
    cout << "rref1 holds: " << rref1 << endl; // Output: 3

    // b) Binding a function return (prvalue):
    int&& rref2 = getValue();
    cout << "rref2 holds: " << rref2 << endl; // Output: 5

    // c) Modifying the temporary via the reference:
    // This is allowed because rref2 is a non-const rvalue reference
    rref2 = 99;
    cout << "rref2 modified: " << rref2 << endl; // Output: 99

    // --- 2. Rvalue Reference (T&&) is an Lvalue Itself ---

    // CRITICAL CONCEPT: Once an rvalue is bound to a named rvalue reference (rref),
    // the name of that reference variable is treated as an LVALUE.

    // int&& rref3 = 100;
    // int&& rref4 = rref3; // ERROR! Cannot bind Rvalue reference to an Lvalue (rref3).

    // To treat the named rvalue reference (rref3) as an Rvalue again,
    // you must explicitly cast it using std::move:

    int&& rref3 = 100;
    int&& rref4 = move(rref3); // OK: rref3 is cast to an rvalue, enabling move/transfer.

    // --- 3. Pointer and Reference Compatibility ---

    // Rvalue references (&&) cannot point to Lvalues (named variables) directly:
    int x = 10;
    // int&& rref_bad = x; // ERROR! Rvalue reference cannot bind to Lvalue 'x'.

    // Lvalue references (T&) cannot point to Rvalues (temporaries) unless they are const:
    // int& lref_bad = 50; // ERROR! Non-const Lvalue reference cannot bind to rvalue.

    // --- 4. Const Lvalue Reference Binds to Rvalues ---

    // The const lvalue reference (const T&) is the only other reference that binds to rvalues,
    // but it prevents modification and extends lifetime, similar to T&&:

    const int& const_rref = 100 + 20; // OK: Binds to rvalue and extends its lifetime.
    // const_rref = 5; // ERROR: Cannot modify via a const reference.

    return 0;
}
