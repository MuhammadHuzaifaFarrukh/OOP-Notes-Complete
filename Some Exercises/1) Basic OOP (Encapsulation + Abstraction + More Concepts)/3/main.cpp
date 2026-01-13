#include <iostream>
#include <string>

#include "Rational.h"
#include "Rational.cpp"

using namespace std;

int main()
{
    Rational r1(2, 3); // 2/3
    Rational r2(4, 5); // 4/5

    cout << "Initial values:\n";
    r1.show(); // 2/3
    r2.show(); // 4/5

    cout << "\nAddition (r1 + r2): ";
    (r1 + r2).show(); // Expected new Rational object with sum

    cout << "\nSubtraction (r1 -= r2): ";
    (r1 -= r2).show(); // r1 becomes result of subtraction

    cout << "\nMultiplication (r1 * r2): ";
    (r1 * r2).show(); // new object returned

    cout << "\nEquality check (r1 == r2): ";
    cout << ((r1 == r2) ? "Equal" : "Not Equal") << endl;

    cout << "\nPre-increment (++r1): ";
    (++r1).show(); // r1 += 1, show updated value

    cout << "\nPost-increment (r1++): ";
    (r1++).show(); // show old value

    cout << "After post-increment: ";
    r1.show(); // now increased by 1
    cout << "\nDivision by another Rational (r1 /= r2): ";
    (r1 /= r2).show(); // divide current by r2
    cout << "\nMultiplication by integer (r1 * 2): ";
    (r1 * 2).show(); // new object, r1 unchanged
    cout << "\nDivision by integer (r1 /= 3): ";
    (r1 /= 3).show(); // modify current object

    return 0;
}
