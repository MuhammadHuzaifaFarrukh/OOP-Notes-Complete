#include <iostream>
using namespace std;

class Outer
{
private:
    int outer_id;

    // ✅ Composition: Outer contains multiple Inner objects
    class Inner
    {
    private:
        int inner_id;
    public:
        Inner(int id) : inner_id(id)
        {
            cout << "  Inner Constructor: " << inner_id << endl;
        }

        ~Inner()
        {
            cout << "  Inner Destructor: " << inner_id << endl;
        }
    };

    Inner inner1;      // Direct composition
    Inner inner2;      // Another inner object
    Inner* inner_ptr;  // Pointer to inner

public:
    Outer(int id) : outer_id(id), inner1(id * 10), inner2(id * 20),
        inner_ptr(new Inner(id * 30))
    {
        cout << "Outer Constructor: " << outer_id << endl;
    }

    ~Outer()
    {
        cout << "Outer Destructor: " << outer_id << endl;
        delete inner_ptr;  // Manual cleanup for pointer
        // inner1 and inner2 destroyed automatically AFTER this
    }

    // ✅ Inner class with Outer reference data member
    class InnerWithOuterRef
    {
    private:
        Outer& outer_ref;  // ✅ Reference to Outer as data member
        int inner_data;
    public:
        InnerWithOuterRef(Outer& outer, int data)
            : outer_ref(outer), inner_data(data)
        {
            cout << "  InnerWithOuterRef Constructor: " << inner_data << endl;
        }

        ~InnerWithOuterRef()
        {
            cout << "  InnerWithOuterRef Destructor: " << inner_data << endl;
        }

        void accessOuter()
        {
            cout << "  Accessing Outer from Inner, data: " << inner_data << endl;
        }
    };
};

int main()
{
    cout << "=== CONSTRUCTION ORDER ===" << endl;
    {
        cout << "Creating Outer object:" << endl;
        Outer outer1(1);

        cout << "\nCreating InnerWithOuterRef object:" << endl;
        Outer::InnerWithOuterRef inner_ref(outer1, 100);
        inner_ref.accessOuter();

        cout << "\nLeaving block scope..." << endl;
    } // Destruction happens here

    cout << "\n=== DYNAMIC ALLOCATION ===" << endl;
    Outer* dynamic_outer = new Outer(2);

    // Create inner object dynamically
    Outer::InnerWithOuterRef* dynamic_inner =
        new Outer::InnerWithOuterRef(*dynamic_outer, 200);

    cout << "\nManual deletion:" << endl;
    delete dynamic_inner;  // Inner destructor
    delete dynamic_outer;  // Outer destructor (then auto inner destructors)

    return 0;
}
