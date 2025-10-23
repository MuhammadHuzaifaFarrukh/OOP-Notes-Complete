#include <iostream>
#include <cstring>

//Move assignment Operator:
/*
It is a special function that lets an object take ownership of resources from another object without copying.
*/

//It frees up the space from obj , then assigns it value and then nullifies the obj from which it copied



class MyString
{
    char* data;

public:
    // Constructor
    MyString(const char* str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // User-defined move assignment operator
    MyString& operator=(MyString&& other) //Don't use const , as this function is used by a non-constant object for which data is being moved so its contents will need to be changed , if we wrote const here , then it would also allow const objects to work but it would then behave differently as const objects cannot be changed but we are stealing and changing resources allowing Undefined Behaviour
    {
        std::cout << "Move assignment called\n";

        if (this != &other)
        {
            // Free old memory
            delete[] data;
            // Steal the pointer
            data = other.data;
            // Set source to null
            other.data = nullptr;
        }

        return *this;
    }

    // Destructor
    ~MyString()
    {
        delete[] data;
    }

    void print() const
    {
        if (data)
            std::cout << data << "\n";
        else
            std::cout << "[empty]\n";
    }
};
int main()
{
    MyString a("Hello");
    MyString b("World");

    b = std::move(a);

    b.print();
    a.print();
}
