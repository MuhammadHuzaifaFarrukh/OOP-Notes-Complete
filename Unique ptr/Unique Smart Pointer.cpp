#include <iostream>
#include <memory> //Header for smart pointers

using namespace std;

//Smart Pointers are used when we need dynamic allocation but more convenient than raw pointers
//They work just like raw pointers
//They are of 3 types : unique , shared, weak

//UNIQUE :
//Prefer it when
//Single ownership semantics
//Resource that should have exactly one owner
//When you want to ensure automatic cleanup
//As a return type from factory functions

//In main() , here are shown uses of unique smart pointer , with data types and arrays
//In class as well
//In functions


void basic_variables()
{
    // ✅ Creating unique_ptr for single variables
    unique_ptr<int> intPtr = make_unique<int>(42);
    unique_ptr<double> doublePtr = make_unique<double>(3.14159);
    unique_ptr<std::string> stringPtr = make_unique<string>("Hello");

    // Accessing values
    cout << "int: " << *intPtr << "\n";
    cout << "double: " << *doublePtr << "\n";
    cout << "string: " << *stringPtr << "\n";

    // Modifying values
    *intPtr = 100;
    *doublePtr = 2.71828;
    *stringPtr = "World";

    cout << "Modified int: " << *intPtr << "\n";

    // ✅ Checking if pointer is valid
    if (intPtr)
    {
        std::cout << "Pointer is valid\n";
    }

    // ✅ Releasing ownership
    int* rawPtr = intPtr.release();
    delete rawPtr; // Now you're responsible for deletion

    if (!intPtr)
    {
        cout << "Pointer is now empty\n";
    }
}






std::unique_ptr<int[]> one_dimensional_arrays()
{
    const size_t SIZE = 5;

    // ✅ Creating unique_ptr for 1D array
    unique_ptr<int[]> arr = make_unique<int[]>(SIZE);

    // ✅ Initializing array
    for (size_t i = 0; i < SIZE; ++i)
    {
        arr[i] = static_cast<int>(i * 10);  // Direct array access
    }

    // ✅ Printing array
    cout << "1D Array: ";
    for (size_t i = 0; i < SIZE; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // ✅ Modifying array elements
    arr[2] = 999;
    cout << "Modified element at index 2: " << arr[2] << "\n";


    return arr; //Return or select void above if you don't want to return
}



//Make and Return 2D Array
//Don't return it with reference , never  , as arr here is local and gets destroyed
unique_ptr<unique_ptr<int[]>[]> create2DArray(size_t rows, size_t cols)
{
    unique_ptr<unique_ptr<int[]>[]> arr = make_unique<unique_ptr<int[]>[]>(rows);

    for (size_t i = 0; i < rows; ++i)
    {
        arr[i] = make_unique<int[]>(cols);
    }

    return arr;
}


// Pass by value - TAKES OWNERSHIP
//Call it using : move
void takeOwnership(unique_ptr<int> ptr)
{
    if (ptr)
    {
        cout << "Inside takeOwnership: " << *ptr << "\n";
        *ptr = 999;  // Can modify
    }
    // ptr destroyed here - ownership was transferred
}


//Send it always using & sign
void modifyInteger(unique_ptr<int>& value)
{
    if (value)
    {
        *value *= 2;
        cout << "Modified integer: " << *value << "\n";
    }
}


// Pass by raw pointer
void useIntegerRaw(int* value)
{
    if (value)
    {
        cout << "Raw pointer value: " << *value << "\n";
        *value += 10;  // Can still modify through raw pointer
    }
}

//If we pass by value int value , then it will take copy of the value from pointer
// Pass by reference to the actual value
void useIntegerDirectly(int& value)
{
    cout << "Direct value: " << value << "\n";
    value += 5;
}








//Send it always using & sign
//Passing 1D array as Parameter
void modify1DArray(unique_ptr<int[]>& arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] *= 2;
    }
}



//Passing 2D array as Parameter
void print2DArray(unique_ptr<unique_ptr<int[]>[]>& arr, int rows, int cols)
{
    cout << "2D Array contents:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}



class Resource
{
public:
    Resource()
    {
        cout << "Resource created\n";
    }
    ~Resource()
    {
        cout << "Resource destroyed\n";
    }
    void work()
    {
        cout << "Working...\n";
    }
};

// Example 1: Basic unique_ptr
void basic_unique_ptr()
{
    unique_ptr<Resource> res = make_unique<Resource>();
    res->work();
    // Automatically deleted when out of scope
}

// Example 2: Transfer ownership
void transfer_ownership()
{
    unique_ptr<int> ptr1 = make_unique<int>(100);
    cout << "ptr1: " << *ptr1 << "\n";

    // Transfer ownership to ptr2
    unique_ptr<int> ptr2 = move(ptr1);

    if (!ptr1)
    {
        cout << "ptr1 is now empty\n";
    }
    cout << "ptr2: " << *ptr2 << "\n";
}

// Example 3: Array support
void array_example()
{
    unique_ptr<int[]> arr = make_unique<int[]>(5);

    for (int i = 0; i < 5; ++i)
    {
        arr[i] = i * 10;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

// Example 4: As class member
class Manager
{
private:
    unique_ptr<Resource> resource_;

public:
    Manager() : resource_(make_unique<Resource>()) {}

    //Without & (pass by value): Requires std::move() at call site, makes ownership transfer explicit

    void setResource(unique_ptr<Resource> newResource)
    {
        resource_ = move(newResource);
    }

    Resource* getResource() const
    {
        return resource_.get();
    }
};


/*
// Constructor
UniquePtrClass(int value, const string& n) : data(make_unique<int>(value)), name(n)
{
    cout << "UniquePtrClass '" << name << "' constructed with value: " << value << "\n";
}
*/


/*
// MANUAL DEEP COPY CONSTRUCTOR
    MyClass(const MyClass& other) : data(make_unique<int>(*other.data))
    {  // Deep copy
        cout << "Custom copy constructor called\n";
    }
*/


/*
// MANUAL DEEP COPY ASSIGNMENT
    MyClass& operator=(const MyClass& other)
    {
        if (this != &other)
        {  // Important: self-assignment check
            // Create new data and copy value
            data = make_unique<int>(*other.data);
        }
        cout << "Custom copy assignment called\n";
        return *this;
    }


*/


/*
// MANUAL MOVE CONSTRUCTOR
UniquePtrClass(UniquePtrClass&& other) noexcept
    : data(move(other.data)), name(move(other.name) + "_moved")
{
    cout << "UniquePtrClass Custom MOVE constructor called for '" << name << "'\n";
}
*/



/*
// MANUAL MOVE ASSIGNMENT
UniquePtrClass& operator=(UniquePtrClass&& other) noexcept
{
    if (this != &other)
    {
        data = move(other.data);
        name = move(other.name) + "_move_assigned";
    }
    cout << "UniquePtrClass Custom MOVE assignment called for '" << name << "'\n";
    return *this;
}
*/


/*
// Destructor
~UniquePtrClass()
{
    cout << "UniquePtrClass '" << name << "' destroyed - data: " << (data ? to_string(*data) : "NULL") << "\n";
}

*/



//Showing Unique Pointer as a Data Member of a Class
class Container
{
private:
    unique_ptr<int> single_value;
    unique_ptr<int[]> dynamic_array;
    size_t array_size;

public:
    // Constructor initializing both
    Container(int value, size_t arr_size): single_value(make_unique<int>(value)),dynamic_array(make_unique<int[]>(arr_size)),array_size(arr_size)
    {
        // Initialize array elements
        for(size_t i = 0; i < arr_size; ++i)
        {
            dynamic_array[i] = i * 10;
        }
    }

    void print()
    {
        cout << "Single value: " << *single_value << endl;
        cout << "Array: ";
        for(size_t i = 0; i < array_size; ++i)
        {
            cout << dynamic_array[i] << " ";
        }
        cout << endl;
    }
};




int main()
{
    unique_ptr<int> number = make_unique<int>(50);
    unique_ptr<double> price = make_unique<double>(99.99);

    //Copy constructor / Copy Assignment can't be used as unique pointer can't be copied
    //Its ownership is transferred , not copied using move assignment and move constructor only
    //E.g : unique_ptr<int> price = move(number) //Now don't use number , or assign it something else


    modifyInteger(number);
    useIntegerRaw(number.get()); //.get() is used to get a raw pointer from unique pointer
    useIntegerDirectly(*number);


    // Create unique_ptr pointing to array
    unique_ptr<int[]> arr = make_unique<int[]>(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;


    //Three ways to assign new locations to arr :
    arr.reset(new int[5] {100, 200, 300, 400, 500}); // Old array destroyed
    arr = make_unique<int[]>(2);  // Previous array destroyed
    arr[0] = 1000;
    arr[1] = 2000;
    arr.reset();  // Array destroyed, arr becomes null
    //These ways are also the ways in which we can reset it for 2D array or values

    unique_ptr<int> num = make_unique<int>(50);
    takeOwnership(move(num));  // MUST use std::move to transfer ownership


    return 0;
}
