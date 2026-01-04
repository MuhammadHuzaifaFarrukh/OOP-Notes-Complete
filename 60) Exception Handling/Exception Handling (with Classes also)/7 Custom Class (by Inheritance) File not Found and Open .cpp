#include <iostream>
#include <fstream>
#include <stdexcept>

//We can make our own custom exception handling messages by inheriting from exception classes or other classes in its hierarchy
//Here we can either print our own custom messages like we did in passing to its constructor
//Or we can also override the e.what() function in both classes and then call this e.what() function
//You may/may not write virtual in its implementation
//We usually use it when we want to write some codes or specific data values that we put as attributes in the class

using namespace std;

class FileNotFound : public runtime_error
{
public:
    FileNotFound() : runtime_error("Error: File literally does not exist.") {}
    virtual const char* what()const noexcept
    {
        return "Bro , No File Here so Get Lost !\n";
    }
};

class FileNotOpen : public runtime_error
{
public:
    FileNotOpen() : runtime_error("Error: File not Open") {}
    virtual const char* what()const noexcept
    {
        return "Bro , File didn't Open so Get Lost !\n";
    }
};

int main()
{
    ifstream file("missing.txt");
    try
    {
        if (!file) throw FileNotFound();            //Here we must put () as throw wants exact match even if non-parameterized constructor call
        if (!file.is_open()) throw FileNotOpen();
    }
    catch (const FileNotFound& e)   //or exception& e also works
    {
        cout << "Handle Missing File: " << e.what() << endl;
    }
    catch (const FileNotOpen& e)    //or exception& e also works
    {
        cout << "Handle Bad Data: " << e.what() << endl;
    }
}
