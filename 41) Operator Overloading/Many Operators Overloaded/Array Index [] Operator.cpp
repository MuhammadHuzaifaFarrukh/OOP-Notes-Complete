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

    int& operator[](int index)
    {
        //Use return getdata(index)
        //return getdata(index); //also for this , you should use return by reference for the function return type

        //or simply
        if(index>=0 && index<3) //Safe Validation
        {
            return arr[index];
        }
        cout<<"Invalid Index"<<endl;
    }

//    int& getdata(int index) //Remove & , if you aren't using it
//    {
//        if(index>=0 && index<3) //Safe Validation
//        {
//            return arr[index];
//        }
//        cout<<"Invalid Index"<<endl;
//    }
    //Can use getdata(some value) instead of arr[index]
};

int main()
{
    A a1(3, 1, 4);
    cout << "Element 0: " << a1[0] << endl;
    cout << "Element 1: " << a1[1] << endl;
    cout << "Element 2: " << a1[2] << endl;

    a1[1] = 5;
    cout << "Modified element 1: " << a1[1] << endl;

    return 0;
}
