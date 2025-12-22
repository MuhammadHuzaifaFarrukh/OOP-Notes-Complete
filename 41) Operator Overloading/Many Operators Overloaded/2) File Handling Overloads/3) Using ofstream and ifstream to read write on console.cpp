#include <iostream>
#include <fstream>
#include <string>

// Polymorphism is involved, but not in the most obvious way. It happens primarily at the std::streambuf level when
// the stream object uses its connection to perform the actual character transfer. It happens at initialization of streams with rdbuf()
// The ability of the std::ostream constructor to accept the pointer returned by std::ofstream.rdbuf() relies on inclusion polymorphism
// The ability of the constructor to accept any derived buffer pointer is a form of Polymorphism (Runtime)

// More Specifically : The ability of a stream object (like std::cout or std::ofstream) to dynamically accept and use any derived stream buffer pointer (std::streambuf*) is the mechanism of Runtime Polymorphism that allows I/O redirection.
// E.g : if we use ofstream to redirect its buffer to cout's buffer , then the streambuf* of ofstream is pointing to base now instead of derived class ( totally fine !)


using namespace std;

int main()
{
    // --- PART 1: Output Redirection (ofstream to Console) ---
    cout << "--- Part 1: Redirecting ofstream to Console (cout) ---" << endl;

    // 1. Create a file stream object (it initializes with a file buffer: filebuf)
    ofstream file_out("redirect_log.txt");

    // 2. SAVE the original stream buffer pointer from the ofstream.
    //    This is the pointer to the file's buffer. We need it to restore the stream later.
    streambuf* original_file_out_buffer = file_out.rdbuf();

    // 3. REDIRECT: Get the console's output buffer (cout.rdbuf()) and assign it
    //    to the internal buffer pointer of the 'file_out' object.
    //    This is where RUNTIME POLYMORPHISM is set up.
    file_out.rdbuf(cout.rdbuf());

    // 4. Test: Any output to 'file_out' now goes to the console (screen) instead of the file.
    cout << "This line is from cout." << endl;
    file_out << "This line is from file_out, but it prints to the CONSOLE!" << endl;

    // 5. RESTORE the original file buffer.
    file_out.rdbuf(original_file_out_buffer);

    // 6. Verification: Output now goes back to the file (and won't appear on the console).
    file_out << "This line goes back into the file 'redirect_log.txt'." << endl;
    file_out.close();
    cout << "Output redirection finished. Check the file for the last line." << endl;

    cout << "\n---------------------------------------------------" << endl;

    // --- PART 2: Input Redirection (ifstream to Console) ---
    cout << "--- Part 2: Redirecting ifstream to Console (cin) ---" << endl;

    // To properly test input, we must first create a valid ifstream object,
    // even though we won't read from the file.
    ifstream file_in("any_file.txt");

    // 1. SAVE the original stream buffer pointer from the ifstream.
    streambuf* original_file_in_buffer = file_in.rdbuf();

    // 2. REDIRECT: Get the console's input buffer (cin.rdbuf()) and assign it
    //    to the internal buffer pointer of the 'file_in' object.
    file_in.rdbuf(cin.rdbuf());

    // 3. Test: The file_in object is now listening to the keyboard (cin).
    int console_input_number;
    cout << "Please type a number and press Enter: ";

    // This reads from the keyboard, despite using the 'file_in' object.
    file_in >> console_input_number;

    cout << "You successfully read the number " << console_input_number
         << " using the 'file_in' object!" << endl;

    // 4. RESTORE the original file buffer.
    file_in.rdbuf(original_file_in_buffer);
    file_in.close();

    cout << "Input redirection finished." << endl;

    return 0;
}

// We can also do this using fstream and without ofstream ifstream
// But in that case we need to make sure to change internal pointers for both I and O
// Doing change for one expecting for other to be changed automatically might lead to undefined behaviours
