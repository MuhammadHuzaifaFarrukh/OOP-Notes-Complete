#include <iostream>

using namespace std;

//When we assign an int or char the pointer or memory address of the other data type like :
//    int arr[5] = {100, 99,98,97};
//    int *p = arr;
//    char *ch = (char *)p;     or (char *)arr;
//    cout<<*(ch+8)<<endl;
//We can do arithmetic of pointers and move according to the type of pointer (here ch so 1 byte move for each +1)

//We can exhibit similar phenomenon using Classes also and achieve polymorphism and more
//This type of work is useless / less imp in Composition / Aggregation

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
    Printer *p ;
//    p -> print();
    p = new Bubblejet;
//    p -> print();
    Bubblejet *b = (Bubblejet *)p;       //b now points to where p points , p must point to a Bubblejet Object here else it will be wrong logically cause C-Styled Typecast doesn't highlight these errors
    //Here 'b' is down-casted , two pointers pointing to same location
    //Here we must specify the type else it will give errors
    cout<<"DOWN-CASTING"<<endl;
    b->print();
    b -> test();
    b -> Printer::print();
    //This is called Down-casting
    //Here if 'p' pointed to a Printer object and then we used this casting , then first this would be logically incorrect ,
    //and b->functions would call the functions from Printer instead of Bubblejet of same named
    delete p;
    cout<<endl<<endl<<endl;
    //Pointer Arithmetic Works fine if both Pointer and Object belong to same class
    //But here we will see the Pointer Arithmetic when Pointer and Object are of different class

    //Here pointer arithmetic may/may not fail if we try to use Printer/Bubblejet array objects and then use a Bubblejet Pointer
    //to traverse it.
    //If sizes are different then it may crash or give Undefined Behaviour                     (Memory Alignment Issues Critical)
    //This might still give undefined Behaviour if the sizes are same , here though it doesn't (Memory Alignment Issues Less Critical)
//    Printer *ptr2 = new Printer[3];       //or new Bubblejet[3] to traverse Bubblejet array using Bubblejet pointer
//    Bubblejet *b2 = (Bubblejet *)ptr2;
//    b2 = b2+1;
//    b2->test();     //Invokes Bubblejet's own member functions even though test() is not in Printer , it is just executed
//    b2->print();    //Invokes Printer's print() if Printer objects array else Bubblejet's print()
    //This type of work is useless / less imp in Composition / Aggregation



    //Up-Casting :
    cout<<"UP-CASTING"<<endl;
    Bubblejet *ptr = new Bubblejet;
    p = ptr;        //No need to specify the type as this is what we usually do in Polymorphism
    p->print();     //Polymorphism is maintained
    delete p;
    //You can do arithmetic of Pointers here if you have an array of objects (adding one skips over the next object)
    //And works fine only if the sizes are same of both , derived and base class
    //Otherwise program crash   (Memory Alignment Issues Critical)
    // Bubblejet *ptr = new Bubblejet[3];
    // p = ptr;
    // Now p+1 will point to Bubblejet[1]
    //This type of work is useless / less imp in Composition / Aggregation

    return 0;
}
