#include <iostream>
using namespace std;

class A
{
private:
    int x;
public:
    A(int s) : x(s) {}

    // Address operator & (unary)
    A* operator&()
    {
        return this;
    }

    int getdata() const
    {
        return x;
    }
};

int main()
{
    A a1(5), a2(3);

    // Using address operator &
    A* ptr = &a1;

    //Although we made our own overloaded one , this is generally not needed or used (overloading & for address)
    //Even if we run this code without overloading & , it works because & automatically gives address
    //But we might need to overload it if we cast one data type to another only in that case it may be helpful


    cout << "Address operator: " << ptr->getdata() << endl;

    return 0;
}
