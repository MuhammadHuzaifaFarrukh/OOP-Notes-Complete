#include <iostream>

int main()
{
    //For using istream and ostream , to input and output:
    //rdbuf() connects the high-level stream object (like std::cout) to the
    //low-level physical I/O mechanism (like the console or keyboard).
    //rdbuf gives access to the underlying stream buffer (std::streambuf) that the stream object is using.

    // 1. Initialize general stream objects
    // 'is' is an istream object initialized to use std::cin's buffer (the keyboard).
    std::istream is(std::cin.rdbuf());

    // 'os' is an ostream object initialized to use std::cout's buffer (the console).
    std::ostream os(std::cout.rdbuf());

    // 2. Variable declaration
    int user_input;

    // 3. Output a prompt using the generic ostream 'os'
    os << "Enter an integer using the generic ostream: ";

    // 4. Read the integer using the generic istream 'is'
    is >> user_input;

    // 5. Output the result using the generic ostream 'os'
    os << "You read the number " << user_input << " from the generic istream." << std::endl;


    /*
    When you declare a generic stream object without a buffer pointer (e.g., std::istream is;), the object is created, but its internal pointer accessed by rdbuf() is typically null or points to a default disconnected state. It is not ready for I/O.
    This is why, to make a generic stream usable for standard I/O, you have to manually provide a buffer pointer using the constructor:
    */
    //Here we took input output using istream and ostream objects by redirecting their buffer to cin and cout objects
    //We can also read/write from file if we redirect their buffer to the file's pointer ifstream and ofstream objects
    //We can also use std::cout and redirect buffer so that it will be used to output in the file

    // Polymorphism is involved, and happens primarily at the std::streambuf level when
    // the stream object uses its connection to perform the actual character transfer. It happens at initialization of streams with rdbuf() above
    // The ability of the std::istream constructor to accept the pointer returned by std::cin.rdbuf() relies on inclusion polymorphism
    // The ability of the constructor to accept any derived buffer pointer is a form of Polymorphism (Runtime)

    // We can also use std::ofstream and redirect its buffer to cout's buffer , and it doesn't break polymorphism
    // As we are only changing the internal pointer buffers only which changes pointers and preserves the objects
    // The key is that console buffer and file buffer are derived from the class std::streambuf so both have same class buffers
    // More Specifically : The ability of a stream object (like std::cout or std::ofstream) to dynamically accept and use any derived stream buffer pointer (std::streambuf*) is the mechanism of Runtime Polymorphism that allows I/O redirection.

    // E.g : if we use ofstream to redirect its buffer to cout , then the streambuf* of ofstream pointing to derived now points to base class (totally fine !)
    // E.g : if we use cout to redirect its buffer to ofstream's buffer , then the streambuf* of cout is pointing to derived now instead of base class ( totally fine !)

    //Also for operator overloading for stream operators , we don't use rdbuf because we pass cout and cin as references so they already have rdbuf of cin and cout (Polymorphism)

    return 0;
}
