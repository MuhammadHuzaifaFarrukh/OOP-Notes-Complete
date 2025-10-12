#include <iostream>

using namespace std;

//If we don't have created any destructor then compiler provides us with one compiler generated destructor
//Destructor cannot return or take any value but perform operation
//If we have made any variable / array on heap in class then in destructor we can delete them as well
//To deallocate memory on heap using destructor , we need to make our own destructor not compiler one
//Also it is a good practice to make our own destructor as memory leaks can occur if we had a var on heap in class and its obj goes out of scope so using destructor can save when the obj goes out of scope the destructor is called immediately

//Destructor usually does cleanup actions even if there is no dynamically allocations




//int count = 0; has the same effect has static one but its scope and lifetime is global


class number
{
public:
    static int count;  //It has neither global nor local scopeClass variables.Their Lifetime is global . On the other hand, have a scope that encompasses the entire class definition.
    //int *n = new int(5); //Variable made on heap can be deallocated using destructor
public:
    number();
    ~number(); //Declaring a destructor

};

number::number()
{
    count++;
    cout<<"The constructor was called for this object number : " <<count<<endl;
}
number::~number()
{
    cout<<"Destructor was called for this object number : "<<count<<endl;
    count--;
    //delete n; //Deallocation in the end for all instances that use 'n' from heap
    //Here we can also use obj.close() to close any file object etc
}

int number::count;

int main()
{
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    number n1;
    {
        // Created a block of code for simplicity.
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        number n2, n3;
        cout<<"Exiting this block"<<endl;  // Destructor will be called here as the block is about to be finished


        //number *n = new number();
        //delete n; //This line calls destructor for obj above only once
        //The Above two lines create an obj on heap memory so delete keyword will deallocate the memory for it as well
        //Also delete will trigger the destructor for this object by itself

        //Destructor for dynamically allocated object runs only once by using delete keyword
        //If delete keyword is not used and no destructor explicit, then memory leaks
        //If delete keyword is not used but destructor explicitly used then still memory leak
        //Remember to use delete keyword to deallocated the dynamically allocated.

        //n->~number();
        //This is an explicit call of a destructor for an obj made on heap , although not any error , not a good practice to foll
        //Explicitly calling destructor still doesn't deallocate memory for dynamically allocated objects so use delete
        //Explicit calling destructor only runs destructor one more time for static objects , and only one time for dynamically allocated objects if no delete is used for them
    }
    cout<<"Back to main"<<endl;

    //delete n1.n; //Using delete here will provide errors if delete was used in destructor as well because when the destructor called for this object uses delete then this will make delete to be used twice leading to undefined behaviour or crash program
    //So use delete on only one place either in destructor or manually here
    //To use delete n1.n , n must be public or else use public getter / setter or use delete in destructor



    //Also destructor is called implicitly when we use delete for object on heap or when obj scope ends so don't try to call it by explicit call as this can also lead to undefined behaviours
    //obj_name.destructor()
    //n1.~number();
    //To use explicity destructor call for heap objects , use obj_name->~destructor() , this will trigger the destructor call only once and delete keyword also triggering destructor call once making it two calls (again not a good thing)
    //Explicitly calling destructor usually doesn't give errors but not a good practice


    //Using explicit Destructor for a stack allocated object doesn't really clean up the object unless that object goes out of scope
    //So you can still access member variables of a stack allocated object even after explicit destructor call
    //But if you use delete for dynamically allocated obj and then try to access a member variable of it then it gives garbage value
    //And if you use nullptr after delete for this dynamically allocated obj , then the program will likely get runtime error if you try to access any member variable of it after nullptr
    return 0;
}



















/*
//Multiple Constructors but only one destructor .
class MyClass
{
public:
  // Default constructor
  MyClass()
  {
    std::cout << "Default constructor called." << std::endl;
  }

  // Constructor with argument
  MyClass(int value) : value_(value)
  {
    std::cout << "Constructor with argument called: " << value << std::endl;
  }

  // Destructor (always called when object goes out of scope)
  ~MyClass()
  {
    std::cout << "Destructor called." << std::endl;
  }

private:
  int value_ = 0; // Member variable
};

int main()
{
  // Create object with default constructor
  MyClass obj1;

  // Create object with argument constructor
  MyClass obj2(42);

  // Objects go out of scope here, triggering destructors
  std::cout << "Ending main function..." << std::endl;

  return 0;
}
*/




















/*Can be used even if no contructor , or if there is a global or static variable or abstract class or new or resource management or closing any file log if you don't know it opened in the system unaware .
#include <iostream>

using namespace std;

class huzaifa
{
private:
    static int count ;
public:
    ~huzaifa()
    {
        count++;
        cout<<"The destuctor was called " <<count<<endl;
        count--;
    }

};
int huzaifa::count;
int main()
{
    huzaifa h1;

    return 0;
}
*/
