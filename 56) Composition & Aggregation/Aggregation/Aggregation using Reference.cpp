#include <iostream>

class B
{
public:
    void sayHello()
    {
        std::cout << "Hello from B!" << std::endl;
    }
};

class A
{
private:
    B& b_ref; // Aggregation via Reference

public:
    // You MUST use the Initializer List here
    A(B& object) : b_ref(object)
    {
        std::cout << "A constructed with reference." << std::endl;
    }

    // ❌ The following would cause a COMPILER ERROR:
    /*
    A(B& object) {
        b_ref = object; // Error: 'b_ref' declared as reference but not initialized
    }
    */

    void useB()
    {
        b_ref.sayHello(); // No need to check for null
    }
};

int main()
{
    B myB;      // B exists independently
    A myA(myB); // Pass the object itself, not the address
    myA.useB();
    return 0;
}
