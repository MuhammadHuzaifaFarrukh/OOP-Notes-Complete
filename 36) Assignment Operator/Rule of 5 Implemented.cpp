#include <iostream>
#include <utility>    // for std::move, std::swap
#include <algorithm>  // for std::swap

// We will NOT use 'using namespace std;' at the top to avoid polluting the global namespace.
// We will use 'std::' explicitly or rely on ADL for swap.

class A
{
private:
    int* a; // The critical resource
    float b;

public:
    // Helper function to print object state
    void print_state(const std::string& name) const
    {
        std::cout << "  " << name << " (Addr: " << this << "): ";
        if (a)
        {
            std::cout << "a points to: " << a << " (Value: " << *a << "), b: " << b << std::endl;
        }
        else
        {
            std::cout << "a is nullptr (Moved-from state)." << std::endl;
        }
    }

    // Constructor
    A(int val_a, float val_b) : a(new int(val_a)), b(val_b)
    {
        std::cout << "--- Initializing A(int, float) ---" << std::endl;
    }

    // 1. Destructor (REQUIRED: Frees the resource)
    ~A()
    {
        std::cout << "--- Destructor called for (Addr: " << this << ") ---";
        if (a)
        {
            std::cout << " Deleting resource at " << a << "." << std::endl;
            delete a;
        }
        else
        {
            std::cout << " Resource already null/moved." << std::endl;
        }
    }

    // 2. Copy Constructor (Creates a new, identical deep-copy)
    A(const A& other)
        : a(new int(*other.a)), // Deep copy the resource
          b(other.b)           // Copy the simple member
    {
        std::cout << "--- Copy Constructor (DEEP COPY) called ---" << std::endl;
    }

    // =========================================================
    // REQUIRED for Copy-and-Swap: Custom member swap function
    // =========================================================
    void swap(A& other) noexcept
    {
        using std::swap;
        swap(a, other.a);
        swap(b, other.b);
    }

    // ----------------------------------------------------
    // The Assignment Operators
    // ----------------------------------------------------

    // 3. Copy Assignment Operator (Canonical signature: resolves ambiguity)
    A& operator=(const A& other)
    {
        std::cout << "--- Copy Assignment Operator called (via Copy-and-Swap idiom) ---" << std::endl;

        // Perform the copy-and-swap idiom, which requires a copy to be made first.
        // The copy will be made via the Copy Constructor: A temp = other;
        A temp = other;

        // Then swap the contents of *this with the temporary.
        // This calls the member swap function.
        temp.swap(*this);

        // When 'temp' goes out of scope, its destructor safely deletes the *original* resource of *this.
        return *this;
    }


    // 4. Move Constructor (Steals the resource)
    A(A&& other) noexcept
        : a(other.a), // Steal the pointer
          b(other.b)
    {
        std::cout << "--- Move Constructor (STEAL) called ---" << std::endl;
        other.a = nullptr; // Nullify the source
    }

    // 5. Move Assignment Operator (Releases old resource, steals new one)
    A& operator=(A&& other) noexcept
    {
        std::cout << "--- Move Assignment Operator (STEAL) called ---" << std::endl;
        if (this != &other)
        {
            // 1. Release the old resource held by the destination object
            delete a;

            // 2. Steal the resource and members from the source
            a = other.a;
            b = other.b;

            // 3. Nullify the source to prevent its destructor from freeing the stolen resource
            other.a = nullptr;
        }
        return *this;
    }
};

// =================================================================
// FIX 1: Non-member swap function definition (in the same namespace as A)
// This enables Argument-Dependent Lookup (ADL) to find the swap correctly.
// =================================================================
void swap(A& left, A& right) noexcept {
    left.swap(right);
}


int main()
{
    // 1. Initial Setup
    A source(10, 1.5f);
    A dest(5, 0.5f);
    source.print_state("Source");
    dest.print_state("Dest");

    std::cout << "\n======================================================\n";
    std::cout << "DEMO 1: COPY ASSIGNMENT (dest = source;)" << std::endl;
    std::cout << "======================================================\n";
    // Lvalue 'source' now perfectly matches 'const A& other' in operator=
    dest = source;

    // Check results
    source.print_state("Source");
    dest.print_state("Dest");

    std::cout << "\n======================================================\n";
    std::cout << "DEMO 2: MOVE ASSIGNMENT (dest = A(99, 9.9f);)" << std::endl;
    std::cout << "======================================================\n";

    // Rvalue 'A(99, 9.9f)' now perfectly matches 'A&& other' in operator=
    dest = A(99, 9.9f);

    // Check results
    dest.print_state("Dest");

    std::cout << "\n--- End of main() ---" << std::endl;
    return 0;
}



//Use of noexcept where :
/*
// 1. Destructor (Implicitly noexcept by default, but you can be explicit)
    ~Resource() noexcept { delete[] data; }

    // 2. Copy Constructor (Allows exceptions , use const )
    Resource(const Resource& other);

    // 3. Copy Assignment Operator (Allows exceptions, often uses copy-and-swap , use const)
    Resource& operator=(const Resource& other);

    // 4. Move Constructor (Critical for performance: MUST be noexcept)
    Resource(Resource&& other) noexcept;

    // 5. Move Assignment Operator (Critical for performance: MUST be noexcept)
    Resource& operator=(Resource&& other) noexcept
*/
