#include <iostream>
#include <memory> // Header for smart pointers

using namespace std;

// SHARED POINTER:
// Prefer it when:
// - Shared ownership semantics are needed
// - Multiple objects need to manage the same resource lifetime
// - When you don't know which will be the last to use the resource
// - For implementing shared caches, observer patterns, etc.

// Key differences from unique_ptr:
// - COPYING IS ALLOWED (shared ownership)
// - Reference counting automatically tracks owners
// - Object destroyed when last shared_ptr is destroyed
// - Slightly more overhead due to reference counting

// - Don't use it for variables and arrays stuff as unique pointer is the best for that purpose

void basic_variables()
{
    cout << "=== BASIC VARIABLES WITH shared_ptr ===\n";

    // ✅ Creating shared_ptr for single variables
    shared_ptr<int> intPtr = make_shared<int>(42);
    shared_ptr<double> doublePtr = make_shared<double>(3.14159);
    shared_ptr<string> stringPtr = make_shared<string>("Hello");

    // Accessing values
    cout << "int: " << *intPtr << "\n";
    cout << "double: " << *doublePtr << "\n";
    cout << "string: " << *stringPtr << "\n";

    // Modifying values
    *intPtr = 100;
    *doublePtr = 2.71828;
    *stringPtr = "World";

    cout << "Modified int: " << *intPtr << "\n";

    // ✅ Checking use count (number of owners)
    cout << "intPtr use count: " << intPtr.use_count() << "\n";

    // ✅ COPYING IS ALLOWED - shared ownership
    shared_ptr<int> intPtr2 = intPtr; // Copy!
    cout << "After copy - use count: " << intPtr.use_count() << "\n";
    cout << "Both point to same value: " << *intPtr << " and " << *intPtr2 << "\n";

    // ✅ Resetting - decreases use count
    intPtr2.reset();
    cout << "After reset - use count: " << intPtr.use_count() << "\n";
}

// SIMPLIFIED ARRAY CREATION - Works with all C++ versions
shared_ptr<int> one_dimensional_arrays()
{
    cout << "\n=== 1D ARRAYS WITH shared_ptr ===\n";
    const size_t SIZE = 5;

    // ✅ SIMPLIFIED: Use shared_ptr<int> with new[] and custom deleter
    // This works consistently across all C++ versions
    shared_ptr<int> arr(new int[SIZE], [](int* p)
    {
        delete[] p;
    });

    // ✅ Access array elements using get()
    int* rawArr = arr.get();

    // ✅ Initializing array
    for (size_t i = 0; i < SIZE; ++i)
    {
        rawArr[i] = static_cast<int>(i * 10);
    }

    // ✅ Printing array
    cout << "1D Array: ";
    for (size_t i = 0; i < SIZE; ++i)
    {
        cout << rawArr[i] << " ";
    }
    cout << "\n";
    cout << "Use count: " << arr.use_count() << "\n";

    // ✅ Modifying array elements
    rawArr[2] = 999;
    cout << "Modified element at index 2: " << rawArr[2] << "\n";

    // ✅ Copying shares the same array!
    auto arrCopy = arr;
    cout << "After copy - use count: " << arr.use_count() << "\n";

    int* rawArrCopy = arrCopy.get();
    rawArrCopy[1] = 777;
    cout << "Original array after modification through copy: " << rawArr[1] << "\n";

    return arr; // Return shared ownership
}

// SIMPLIFIED 2D Array Creation
shared_ptr<shared_ptr<int>[]> create2DArray(size_t rows, size_t cols)
{
    cout << "\n=== CREATING 2D ARRAY ===\n";

    // Create array of shared_ptrs (each pointing to a row)
    shared_ptr<shared_ptr<int>[]> arr(new shared_ptr<int>[rows]);

    for (size_t i = 0; i < rows; ++i)
    {
        // Each row is a shared_ptr to an array of integers
        arr[i] = shared_ptr<int>(new int[cols], [](int* p)
        {
            delete[] p;
        });
    }

    // Initialize with values
    for (size_t i = 0; i < rows; ++i)
    {
        int* rowPtr = arr[i].get();
        for (size_t j = 0; j < cols; ++j)
        {
            rowPtr[j] = static_cast<int>(i * 10 + j);
        }
    }

    return arr;
}

// Pass by value - SHARES OWNERSHIP (increases use count)
void shareOwnership(shared_ptr<int> ptr)
{
    if (ptr)
    {
        cout << "Inside shareOwnership: " << *ptr << "\n";
        cout << "Use count in function: " << ptr.use_count() << "\n";
        *ptr = 888; // Modifies the shared object
    }
    // ptr destroyed here - decreases use count
}

// Pass by reference - NO ownership change, just access
void modifyInteger(shared_ptr<int>& value)
{
    if (value)
    {
        *value *= 2;
        cout << "Modified integer: " << *value << "\n";
        cout << "Use count during modification: " << value.use_count() << "\n";
    }
}

// Pass by raw pointer - NO ownership change
void useIntegerRaw(int* value)
{
    if (value)
    {
        cout << "Raw pointer value: " << *value << "\n";
        *value += 10;
    }
}

// Pass by reference to actual value
void useIntegerDirectly(int& value)
{
    cout << "Direct value: " << value << "\n";
    value += 5;
}

// SIMPLIFIED: Passing 1D array as Parameter by reference
void modify1DArray(shared_ptr<int>& arr, size_t size)
{
    cout << "Before modification - use count: " << arr.use_count() << "\n";
    int* rawArr = arr.get();
    for (size_t i = 0; i < size; ++i)
    {
        rawArr[i] *= 2;
    }
    cout << "Array modified (all elements doubled)\n";
}

// SIMPLIFIED: Passing 2D array as Parameter by reference
void print2DArray(shared_ptr<shared_ptr<int>[]>& arr, int rows, int cols)
{
    cout << "2D Array contents (use count: " << arr.use_count() << "):\n";
    for (int i = 0; i < rows; ++i)
    {
        int* rowPtr = arr[i].get();
        for (int j = 0; j < cols; ++j)
        {
            cout << rowPtr[j] << "\t";
        }
        cout << "\n";
    }
}

class Resource
{
public:
    string name;

    Resource(const string& n) : name(n)
    {
        cout << "Resource '" << name << "' created\n";
    }

    ~Resource()
    {
        cout << "Resource '" << name << "' destroyed\n";
    }

    void work()
    {
        cout << "Resource '" << name << "' working...\n";
    }
};

// Example 1: Basic shared_ptr with reference counting
void basic_shared_ptr()
{
    cout << "\n=== BASIC shared_ptr EXAMPLE ===\n";

    shared_ptr<Resource> res1 = make_shared<Resource>("Database");
    cout << "Use count after creation: " << res1.use_count() << "\n";

    {
        shared_ptr<Resource> res2 = res1; // Copy increases use count
        cout << "Use count in inner scope: " << res1.use_count() << "\n";
        res2->work();
    } // res2 destroyed here - decreases use count

    cout << "Use count after inner scope: " << res1.use_count() << "\n";
    res1->work();

    // Resource destroyed when res1 goes out of scope
}

// Example 2: Multiple ownership demonstration
void multiple_ownership()
{
    cout << "\n=== MULTIPLE OWNERSHIP DEMO ===\n";

    auto resource = make_shared<Resource>("SharedResource");
    cout << "Initial use count: " << resource.use_count() << "\n";

    // Multiple owners
    auto owner1 = resource;
    auto owner2 = resource;
    auto owner3 = resource;

    cout << "Use count with 4 owners: " << resource.use_count() << "\n";

    // All can use the same resource
    owner1->work();
    owner2->work();

    // Reset some owners
    owner2.reset();
    owner3.reset();

    cout << "Use count after some resets: " << resource.use_count() << "\n";
}

// Example 3: SIMPLIFIED Array support with shared ownership
void array_example_shared()
{
    cout << "\n=== ARRAY WITH SHARED OWNERSHIP ===\n";

    // Simplified array creation that works everywhere
    shared_ptr<int> arr(new int[5], [](int* p)
    {
        delete[] p;
    });
    int* rawArr = arr.get();

    for (int i = 0; i < 5; ++i)
    {
        rawArr[i] = i * 10;
    }

    cout << "Original array use count: " << arr.use_count() << "\n";

    // Share the array
    auto arrCopy = arr;
    cout << "After copy - use count: " << arr.use_count() << "\n";

    // Both can modify the same array
    int* rawArrCopy = arrCopy.get();
    rawArrCopy[2] = 999;
    cout << "Original array[2] after modification through copy: " << rawArr[2] << "\n";
}

// Example 4: As class member with shared ownership
class SharedManager
{
private:
    shared_ptr<Resource> resource_;

public:
    SharedManager(const string& name)
        : resource_(make_shared<Resource>(name))
    {
        cout << "SharedManager created, use count: " << resource_.use_count() << "\n";
    }

    // With shared_ptr, copying is automatic and safe!
    void setResource(shared_ptr<Resource> newResource)
    {
        resource_ = newResource; // No move needed - sharing ownership
        cout << "Resource set, use count: " << resource_.use_count() << "\n";
    }

    shared_ptr<Resource> getResource() const
    {
        return resource_; // Returns a copy - shares ownership
    }

    void useResource()
    {
        if (resource_)
        {
            resource_->work();
            cout << "Current use count: " << resource_.use_count() << "\n";
        }
    }
};

// Example 5: Circular reference demonstration (POTENTIAL ISSUE)
class Node
{
public:
    string name;
    shared_ptr<Node> next;

    Node(const string& n) : name(n)
    {
        cout << "Node '" << name << "' created\n";
    }

    ~Node()
    {
        cout << "Node '" << name << "' destroyed\n";
    }
};

void circular_reference_demo()
{
    cout << "\n=== CIRCULAR REFERENCE DEMO ===\n";

    auto node1 = make_shared<Node>("Node1");
    auto node2 = make_shared<Node>("Node2");

    // Create circular reference
    node1->next = node2;
    node2->next = node1;

    cout << "Node1 use count: " << node1.use_count() << "\n";
    cout << "Node2 use count: " << node2.use_count() << "\n";

    // Even when we leave scope, objects won't be destroyed due to circular reference!
    // This is a MEMORY LEAK!
    // Solution: Use weak_ptr for one of the references
}

// Example 6: Using weak_ptr to break circular references
class SafeNode
{
public:
    string name;
    weak_ptr<SafeNode> next; // Use weak_ptr instead of shared_ptr

    SafeNode(const string& n) : name(n)
    {
        cout << "SafeNode '" << name << "' created\n";
    }

    ~SafeNode()
    {
        cout << "SafeNode '" << name << "' destroyed\n";
    }

    void setNext(shared_ptr<SafeNode> nextNode)
    {
        next = nextNode; // weak_ptr doesn't increase use count
    }

    void printNext()
    {
        if (auto nextPtr = next.lock()) // Convert to shared_ptr temporarily
        {
            cout << "Next node: " << nextPtr->name << "\n";
        }
        else
        {
            cout << "Next node no longer exists\n";
        }
    }
};

void weak_ptr_demo()
{
    cout << "\n=== WEAK_PTR DEMO (Breaking circular references) ===\n";

    auto node1 = make_shared<SafeNode>("SafeNode1");
    auto node2 = make_shared<SafeNode>("SafeNode2");

    node1->setNext(node2);
    node2->setNext(node1);

    cout << "Node1 use count: " << node1.use_count() << "\n"; // Should be 1
    cout << "Node2 use count: " << node2.use_count() << "\n"; // Should be 1

    node1->printNext();
    node2->printNext();

    // Objects will be properly destroyed when leaving scope
}


/*
// Constructor
SharedPtrClass(int value, const string& n) : data(make_shared<int>(value)), name(n)
{
    cout << "SharedPtrClass '" << name << "' constructed with value: " << value
         << " (use_count: " << data.use_count() << ")\n";
}
*/


/*
// MANUAL COPY CONSTRUCTOR
SharedPtrClassManual(const SharedPtrClassManual& other) : data(other.data), name(other.name + "_manual_copy")  // shared_ptr copy constructor - increases ref count
{
    cout << "MANUAL SharedPtrClass COPY constructor called for '" << name
         << "' - use_count: " << data.use_count() << "\n";
}
*/


/*
// MANUAL COPY ASSIGNMENT
SharedPtrClassManual& operator=(const SharedPtrClassManual& other)
{
    cout << "MANUAL SharedPtrClass COPY assignment called\n";

    if (this != &other)    // Self-assignment check
    {
        // shared_ptr assignment operator handles:
        // 1. Decreases ref count for current data (may delete if last owner)
        // 2. Increases ref count for other.data
        // 3. Transfers ownership
        data = other.data;
        name = other.name + "_manual_assigned";

        cout << "After manual copy assignment - use_count: " << data.use_count()
             << " for '" << name << "'\n";
    }
    return *this;
}
*/




/*
// MANUAL MOVE CONSTRUCTOR
SharedPtrClassManual(SharedPtrClassManual&& other) noexcept : data(move(other.data)),  name(std::move(other.name) + "_manual_moved") // Moves the shared_ptr ownership
{
    cout << "MANUAL SharedPtrClass MOVE constructor called for '" << name << "'\n";
    // After move, other.data is empty (nullptr)
}
*/



/*
// MANUAL MOVE ASSIGNMENT
SharedPtrClassManual& operator=(SharedPtrClassManual&& other) noexcept
{
    cout << "MANUAL SharedPtrClass MOVE assignment called\n";

    if (this != &other)
    {
        // Move the shared_ptr - transfers ownership
        data = std::move(other.data);
        name = std::move(other.name) + "_manual_move_assigned";

        cout << "After manual move assignment - use_count: " << data.use_count()
             << " for '" << name << "'\n";
        // other.data is now empty after the move
    }
    return *this;
}
*/




/*
// Destructor
~SharedPtrClass()
{
    cout << "SharedPtrClass '" << name << "' destroyed - data: "
         << (data ? to_string(*data) : "NULL")
         << " (final use_count: " << (data ? data.use_count() : 0) << ")\n";
}
*/




int main()
{
    cout << "========== SHARED_PTR COMPREHENSIVE GUIDE ==========\n";

    // Basic variable operations
    basic_variables();

    // Array operations
    auto arr = one_dimensional_arrays();

    // 2D array operations
    auto matrix = create2DArray(3, 4);
    print2DArray(matrix, 3, 4);

    // Function parameter passing demonstrations
    auto number = make_shared<int>(50);
    cout << "\n=== FUNCTION PARAMETER PASSING ===\n";
    cout << "Initial use count: " << number.use_count() << "\n";

    shareOwnership(number); // Pass by value - shares ownership
    cout << "After shareOwnership - use count: " << number.use_count() << "\n";

    modifyInteger(number); // Pass by reference - no ownership change
    useIntegerRaw(number.get()); // Raw pointer access
    useIntegerDirectly(*number); // Direct value access

    // Array parameter passing
    shared_ptr<int> testArr(new int[3], [](int* p)
    {
        delete[] p;
    });
    int* rawTestArr = testArr.get();
    rawTestArr[0] = 1;
    rawTestArr[1] = 2;
    rawTestArr[2] = 3;
    modify1DArray(testArr, 3);

    // Class examples
    basic_shared_ptr();
    multiple_ownership();
    array_example_shared();

    // Manager class demonstration
    SharedManager manager("ManagerResource");
    auto sharedRes = manager.getResource();
    cout << "Resource use count after getting from manager: " << sharedRes.use_count() << "\n";

    // Circular reference and weak_ptr demonstrations
    circular_reference_demo();
    weak_ptr_demo();

    cout << "\n=== RESET AND REASSIGNMENT ===\n";
    // Three ways to reset shared_ptr:
    auto ptr = make_shared<int>(100);
    cout << "Initial use count: " << ptr.use_count() << "\n";

    // 1. Reset to empty
    ptr.reset();
    cout << "After reset - use count: " << ptr.use_count() << "\n";

    // 2. Reset with new object
    ptr.reset(new int(200));
    cout << "After reset with new object: " << *ptr << "\n";

    // 3. Assign new shared_ptr
    ptr = make_shared<int>(300);
    cout << "After assignment: " << *ptr << "\n";

    cout << "\n========== GUIDE COMPLETE ==========\n";
    return 0;
}
