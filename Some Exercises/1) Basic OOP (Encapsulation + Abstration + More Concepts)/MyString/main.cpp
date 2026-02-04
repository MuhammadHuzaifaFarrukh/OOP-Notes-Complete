#include "MyString.h"
#include "MyString.cpp"
#include <iostream>
using namespace std;

int main()
{
    // 1. Test Negate
    MyString str1(6,"AbC123");
    cout << "Original string: ";
    str1.show();
    MyString negated = str1.negate();
    cout << "Negated string: ";
    negated.show();  // Expected: aBC123

    // 2. Test remove_substr
    MyString str2(12, "bananabanana");
    cout << "\nOriginal string: ";
    str2.show();
    MyString temp = str2.remove_substr("ana");
    cout << "After remove_substr(\"ana\"): ";
    temp.show();  // Expected: bnnbn

    // 3. Test palindrome
    MyString str3(5, "radar");
    cout << "\nIs \"" ;
    str3.show() ;
    cout << "\" palindrome? ";
    cout << (str3.palindrome() ? "true" : "false") << endl;  // true

    MyString str4(5,"hello");
    cout << "Is \"" ;
    str4.show();
    cout << "\" palindrome? ";
    cout << (str4.palindrome() ? "true" : "false") << endl;  // false

    // 4. Test anagram
    MyString str5(6, "listen");
    MyString str6(6,"silent");
    cout << "\nAre \"" ;
    str5.show();
    cout << "\" and \"" ;
    str6.show();
    cout << "\" anagram? ";
    cout << (str5.anagram(str6) ? "true" : "false") << endl;  // true

    MyString str7(5,"hello");
    MyString str8(5, "world");
    cout << "Are \"" ;
    str7.show() ;
    cout<<  "\" and \"" ;
    str8.show() ;
    cout<< "\" anagram? ";
    cout << (str7.anagram(str8) ? "true" : "false") << endl;  // false

    // 5. Test operator + (concatenation)
    MyString str9(7,"hello, ");
    MyString str10(8, "world");
    MyString concat = str9 + str10;
    cout << "\nConcatenation of \"" ;
    str9.show();
    cout << "\" + \"" ;
    str10.show();
    cout << "\": ";
    concat.show();  // Expected: helloworld

    // 6. Test addLargeEqual
    MyString num1(4,"1234");
    MyString num2(3,"567");
    MyString sumEqual = num1.addLargeEqual(num2);
    cout << "\naddLargeEqual of " ;
    num1.show();
    cout << " + ";
    num2.show();
    cout << ": ";
    sumEqual.show();  // Expected: 1801 or 0 if size exceeded

    MyString num3(3,"999");
    MyString num4(1, "1");
    MyString sumEqual2 = num3.addLargeEqual(num4);
    cout << "addLargeEqual of " ;
    num3.show();
    cout << " + " ;
    num4.show();
    cout << ": ";
    sumEqual2.show();  // Expected: 0

    // 7. Test addLargeExtend
    MyString num5(3, "999");
    MyString num6(1,"1");
    MyString sumExtend = num5.addLargeExtend(num6);
    cout << "\naddLargeExtend of " ;
    num5.show() ;
    cout << " + " ;
    num6.show();
    cout << ": ";
    sumExtend.show();  // Expected: 1000

    MyString num7(3,"123");
    MyString num8(2, "77");
    MyString sumExtend2 = num7.addLargeExtend(num8);
    cout << "addLargeExtend of " ;
    num7.show() ;
    cout<<" + " ;
    num8.show();
    cout << ": ";
    sumExtend2.show();  // Expected: 200

    return 0;
}
