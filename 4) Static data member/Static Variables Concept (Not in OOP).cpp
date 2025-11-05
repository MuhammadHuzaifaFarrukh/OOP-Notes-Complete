#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//====STATIC VARIABLES =========\\

// Scope of Static variables depends on where declared
// Life time of Static variables is whole program execution
// Where we initialize static var / pointers  , that line is only executed once , no matter how many times that line is again executed somewhere else in a function etc
// They reside in either .BSS or Data Segment
// If they are initialized (any value or even zero) then in DATA SEGMENT otherwise uninitialized are in .BSS

// Also if during a calculation , if static variable was initialized a value and then again after calc , it becomes zero , then it doesn't go to .BSS
// But if it was uninitialized and calculation like x = 5-5 happened then it still remains in .BSS




// Global non-static variable (externally visible, can be used here)
int g_global_value = 100;

// Global static variable (only visible in this file)
static int file_counter = 0;

// Static function (only callable from within my_module.cpp)
static void increment_and_print()
{
    // 1. Can use and reassign values to Global Static variable (file_counter) -> YES
    file_counter++;

    // 2. Can use and reassign values to Local Static variable -> YES
    static int call_count = 0;
    call_count++;

    // 3. Can use and reassign values to Local Non-Static variable -> YES
    int temp = 5;

    // 4. Can use and reassign values to Non-Static Global Variable -> YES
    g_global_value++;

    std::cout << "File Counter: " << file_counter << std::endl;
    std::cout << "Call Count: " << call_count << std::endl;
    std::cout << "Global Value Counter: " << g_global_value << std::endl;
}





// Showing the use of static pointer :
// the static keyword on the pointer dictates the pointer's lifetime, not the lifetime or
// type of the object it holds the address of
// If pointer doesn't point to anything (uninitialized) then its also in .BSS
// But if we assign it nullptr or any other memory location , it resides in Data segment

void demonstrate_static_pointer()
{
    // A regular local variable that is destroyed when the function ends
    int non_static_data = 99;

    // **The pointer variable 'ptr' is static.**
    // It is initialized only once, and retains its value across calls.
    static int* ptr = nullptr;

    if (ptr == nullptr)
    {
        // Assign the address of the local variable 'non_static_data'
        // WARNING: This is UNSAFE outside of this immediate function call,
        // as 'non_static_data' is destroyed when the function returns.
        ptr = &non_static_data;
        std::cout << "Pointer initialized to address: " << ptr << std::endl;
    }
    else
    {
        std::cout << "Pointer already initialized. Current address: " << ptr << std::endl;
        // In reality, this address would be invalid/dangling on the second call
        // because the stack space of 'non_static_data' is reused.
    }
}



int main()
{
    //Static variables have scope local if inside {} and lifetime global
    cout << "--- Start of main() ---" << endl;

    // This static variable is initialized to 10 ONLY ONCE.
    static int static_counter = 10;

    cout << "Initial value: " << static_counter << endl;

    for (int i = 0; i < 3; ++i)
    {
        static_counter++;
        cout << "Counter after iteration " << i + 1 << " : " << static_counter << endl;
    }

    cout << "--- End of main() ---" << endl<<endl<<endl;

    // If main were called again (which it shouldn't be), static_counter
    // would still hold the value 13.


    //Calling Static Normal Function :
    increment_and_print();
    increment_and_print();
    increment_and_print();

    cout<<endl<<endl<<endl;

    //Static Pointer :
    demonstrate_static_pointer(); // First call: Initializes ptr
    demonstrate_static_pointer(); // Second call: Uses the retained address from ptr

    return 0;
}



/*
For Working in Multiple Files :
//💡 Best Practice: Avoid Static Functions in Headers Files
//Because if we have multiple parallel files using this function , then instead of sharing the code efficiently , each
file gets its own private copy of the static function bcz linker doesn't treat it as normal function , making final
machine code much larger than usual

//This might be small for only one file usage , but for parallel files that use it , it will be an overhead

//There will be errors if we declare static function in one file and give its implementation in an other file (so use only global.h to declare & initialize there)



//Static Functions are hidden from other files , so two cpp files can have same static functions with same name , no clash
//Whereas Non-Static Function are visible to other files , so name clashes can occur

static void hiddenFunction()    // Only visible in this file / program , Can use other variables as well
{
    std::cout << "I'm hidden from other files!" << std::endl;
}

void publicFunction()    // Visible to other files
{
    std::cout << "I'm public!" << std::endl;
}

int main()
{
    hiddenFunction();  // ✅ Works - same file
    publicFunction();  // ✅ Works
    return 0;
}

//If we include a header containing a static function , then we can make the static function with same name as it will not do name clash as discussed above.
*/
