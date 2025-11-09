#include <iostream>
#include <iomanip>

using namespace std;

class A
{
private:
    int arr[3];
public:
    A() {}
    A(int a, int b, int c)
    {
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
    }

    int operator()(int index)
    {
        if(index >=0 && index <3)
        {
            return arr[index];
        }
    }

};

int main()
{
    A a1(3, 1, 4);
    cout << "Using (): " << a1(0) << endl;
    cout << "Using (): " << a1(1) << endl;
    cout << "Using (): " << a1(2) << endl;

    return 0;
}
