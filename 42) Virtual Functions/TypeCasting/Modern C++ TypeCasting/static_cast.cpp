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
    int x = 20;
    void print()
    {
        cout << "BubbleJet Print\n";
        Printer::print();
    }
    void test()
    {
        cout << "Test of BubbleJet\n";
        x= x*2;
    }
};

int main()
{
    //static_cast is the "responsible" cast
    //It is called "static" because the conversion happens entirely at compile-time.
    //The compiler checks if the two types are related, and if they are, it handles the
    //conversion—sometimes even changing the underlying data to make it fit.

    //Unlike reinterpret_cast, static_cast can actually modify the bits to ensure
    //the value remains logically the same in the new type

    //In implicit type cast :
//    double d = 9.87;
//    int i = (d); // i becomes 9

    //1) :
    //The Explicit Cast :
    double d = 9.87;
    int i = static_cast<int>(d); // i becomes 9

    //2) :  Reinterpret cast allowed this but static cast will throw error here as it is a safe cast
//    int arr[5] = {65,66,67,68,69};
//    char *p = static_cast<char *>(arr);
    //Doesn't allow Pointer to Pointer conversion of different types


    //3) : Objects (Up Casting)
    Bubblejet *bub = new Bubblejet;
    Printer *prnt = static_cast<Printer *>(bub);    //Also works fine without type cast as it is the actual polymorphism

    //4) Down-Casting
    Printer *p = new Bubblejet;
    Bubblejet *b = static_cast<Bubblejet *>(p);
    b->test();

    //5) Down-Casting but Danger one
    Printer *p1 = new Printer;
    Bubblejet *b1 = static_cast<Bubblejet *>(p1);
    b1->print();        //Calls Print from the Printer instead of Bubblejet
    //Here it was wrong type but still doesn't throw error as this is checked on runtime not compile

    //6)
    //This shouldn't be allowed and static cast catches this and throws error
    //Bubblejet *b3 = new Bubblejet;
    //Inkjet *i1 = static_cast<Inkjet *>(b3);
    //Static Cast detects this as it looks at b3 and knows that its a Bubblejet* so it never allows the conversion from independent classes


    //Moving from Parent to Child without a runtime check.
    //Warning: Unlike dynamic_cast, static_cast does not check the Vtable.
    //If your Parent pointer doesn't actually point to a Child, static_cast will still give you a pointer,
    //but using it will likely crash the program

    return 0;
}
