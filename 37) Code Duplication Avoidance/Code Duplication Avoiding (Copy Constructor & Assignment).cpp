#include <iostream>

using namespace std;

//Avoid Code Duplication
//Copy Constructor sometimes has the same code as the Copy Assingment Operator but with few changes so we make one common function for both
//Similarly for Destructor (although this might not be required)
//Similary we can do this for move constructor and move assignment operator as well

class S
{
private:
    int* ptr;
    size_t size; // Use size_t for size/count

    // Helper function to encapsulate deep copy logic
    // Returns S& to allow for cleaner integration into the assignment operator
    // You can also write here void return type or S& only but not (never) S
    // Using S as return type will cause infinite recursion as it will keep calling copy constructor of yours on returning for making copy of object , and then that copy constructor will call your helper function and this helper function will again return as S which again calls another copy constructor and so on . Although it might work , if we are using default compiler generated constructor , if its user one , then this will definitely create infinite recursion in this way
    S& copy_from(const S& other)
    {
        size = other.size;

        // 1. Allocate new memory
        ptr = new int[size];

        // 2. Deep copy data
        for (size_t i = 0; i < size; ++i)
        {
            ptr[i] = other.ptr[i];
        }
        return *this;
    }

public:
    //  Default/Parameter Constructor
    S(size_t initial_size = 0) : size(initial_size) //Default Argument used , can be overwritten
    {
        if (size > 0)
        {
            ptr = new int[size];
            // Initialize with zeroes or other default values
            for (size_t i = 0; i < size; ++i)
            {
                ptr[i] = 0;
            }
        }
        else
        {
            ptr = nullptr;
        }
    }

    //With Destructor not necessarily required
    void cleanup()
    {
        delete[] ptr;
    }

    // 2. **Destructor**
    ~S()
    {
        cleanup();
    }

    // 3. **Copy Constructor** (Initializes a new object)
    S(const S& other) : ptr(nullptr), size(0)   // Initialize members safely before copy , Also here this member init list  , we can't overwrite them in function call as this copy constructor takes only one argument
    {
        // Delegate to the helper function (no old resources to clean up)
        copy_from(other);
    }

    // 4. **Copy Assignment Operator** (Copies into an existing object - Operator Overloading)
    S& operator=(const S& other)
    {
        // **VITAL Self-Assignment Check**
        if (this != &other)
        {
            // A. Clean up old resources (Memory Leak Prevention)
            delete[] ptr;

            // B. Perform the deep copy
            copy_from(other);
        }

        // C. Return a reference to the current object (for assignment chaining: s1 = s2 = s3)
        return *this;
    }

    // Example Method for testing/demonstration
    void print() const
    {
        std::cout << "S object at " << this << " (Heap data at " << ptr << "): ";
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    S sen(10);
    S sen2;
    sen2 = sen;
    sen2.print();

    return 0;
}
