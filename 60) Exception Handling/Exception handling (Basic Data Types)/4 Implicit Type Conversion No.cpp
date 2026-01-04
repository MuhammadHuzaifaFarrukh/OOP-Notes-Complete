#include <iostream>

using namespace std;

//We can use catch all block to catch all the exceptions occur
//Here we throw an int exception and catch(...) will catch it now
//Advantage : It ensures your program doesn't crash even if an unexpected error occurs.

//Disadvantages :
//No Information: You cannot give the exception a name (like e). Therefore, you cannot access its value or call .what().
//Hides Bugs: It can make debugging difficult because it "swallows" the error without telling you exactly what went wrong.

//Implicit Type Conversion doesn't happen for primitive data types (E.g int converted to char or vice versa etc)
int main()
{
    try
    {
        throw 'a';      //This is a character or a character constant
    }
    catch(int c)
    {
        cout<<"Caught a character exception "<<c<<endl;
    }
    catch(...)
    {
        cout<<"Default Exception "<<endl;
    }

    return 0;
}
