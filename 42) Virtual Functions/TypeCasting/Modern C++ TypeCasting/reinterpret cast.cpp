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
    //int x = 20;
    void print()
    {
        cout << "BubbleJet Print\n";
        Printer::print();
    }
    void test()
    {
        cout << "Test of BubbleJet\n";
        //x= x*2;
    }
};

int main()
{
    //It is the most dangerous cast in C++ because it tells the compiler:
    //"Stop thinking about types. Take the raw bits of this memory and pretend they are this
    //other type, no matter how unrelated they are."

    //1)
    struct Data
    {
        int id;
        float value;
    };

    Data d = {101, 3.14f};

    // We want to look at 'd' as an array of bytes (unsigned char)
    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&d);

    for(int i = 0; i < sizeof(Data); i++)
    {
        printf("%02x ", bytePtr[i]); // Print hex value of each byte
    }
    cout<<endl;


    //2)
    //Similar to above , we can use char array and use int * on it to traverse and vice versa
    char arr[5] = {'A','B', 'C', 'D'};
    int *p = reinterpret_cast<int *>(arr);
    cout<<*p<<endl;
    int arr2[5] = {65, 66,67, 68, 69};
    char *p1 = reinterpret_cast<char *>(arr2);
    cout<<*(p1+0)<<endl;
    cout<<*(p1+4)<<endl;

    //3)
    int x = 42;
    int address = reinterpret_cast<int>(&x); // Store address as a number
    cout << "Address as a number: " << address << endl;


    //4)
    //4) Down-Casting
    Printer *p2 = new Bubblejet;
    Bubblejet *b2 = reinterpret_cast<Bubblejet *>(p2);
    b2->test();

    //5) Down-Casting but Danger one
    Printer *p3 = new Printer;
    Bubblejet *b3 = reinterpret_cast<Bubblejet *>(p3);
    b3->print();

    //6)
    //This shouldn't be allowed but reinterpret cast allows this also

    Inkjet *i1 = reinterpret_cast<Inkjet *>(b2);
    i1->Inkjet::print();


    return 0;
}
