#include <iostream>
using namespace std;

class B
{
private:
    int id;
public:
    B(int id) : id(id)
    {
        cout << "B Constructor: " << id << endl;
    }

    ~B()
    {
        cout << "B Destructor: " << id << endl;
    }

    void display()
    {
        cout << "B object ID: " << id << endl;
    }

    void setId(int newId)
    {
        id = newId;
    }
};

class A
{
private:
    B* b_ptr;  // Aggregation - pointer to B
    int size;

public:
    // CONSTRUCTOR: Allocation with new
    A(int arrSize) : size(arrSize)
    {
        cout << "A Constructor - Allocating B array of size: " << size << endl;
        b_ptr = new B[size];  // Dynamic allocation in constructor (Just like Composition)

        // Initialize B objects
        for(int i = 0; i < size; i++)
        {
            b_ptr[i].setId(i + 1);
        }
    }

    // DESTRUCTOR: Deallocation with delete[]
    ~A()
    {
        cout << "A Destructor - Deallocating B array" << endl;
        delete[] b_ptr;  // Cleanup in destructor (Just like Composition)
    }

    // OTHER FUNCTION: Reallocation with new/delete
    void resize(int newSize)
    {
        cout << "Resizing from " << size << " to " << newSize << endl;

        // 1. Delete old array
        delete[] b_ptr;

        // 2. Allocate new array
        b_ptr = new B[newSize];  // Aggregation being observed clearly (As the object being created is independent and Lifetime unbounded)
        size = newSize;

        // 3. Initialize new objects
        for(int i = 0; i < size; i++)
        {
            b_ptr[i].setId((i + 1) * 10);
        }
    }

    // OTHER FUNCTION: Create single B object
    B* createSingleB()
    {
        cout << "Creating single B object dynamically" << endl;
        B* singleB = new B(999);  // Allocation in regular function
        return singleB;
    }

    // OTHER FUNCTION: Delete single B object
    void deleteSingleB(B* ptr)
    {
        cout << "Deleting single B object" << endl;
        delete ptr;  // Deallocation in regular function (Lifetime unbounded shown again !)
    }

    void display()
    {
        cout << "A contains " << size << " B objects:" << endl;
        for(int i = 0; i < size; i++)
        {
            b_ptr[i].display();
        }
    }
};

int main()
{
    cout << "=== AGGREGATION DEMO ===" << endl;

    // 1. Constructor allocation
    cout << "\n1. Creating A object (constructor allocation):" << endl;
    A a1(3);
    a1.display();

    // 2. Other function reallocation
    cout << "\n2. Resizing A object (other function allocation):" << endl;
    a1.resize(2);
    a1.display();

    // 3. Other function single object allocation
    cout << "\n3. Single object allocation in other function:" << endl;
    B* singleB = a1.createSingleB();
    singleB->display();

    // 4. Other function single object deallocation
    cout << "\n4. Single object deallocation in other function:" << endl;
    a1.deleteSingleB(singleB);

    cout << "\n5. End of main - automatic destructor call:" << endl;
    // Destructor will automatically call delete[] when a1 goes out of scope

    return 0;
}
