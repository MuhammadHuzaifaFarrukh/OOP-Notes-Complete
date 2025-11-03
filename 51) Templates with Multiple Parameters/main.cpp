#include <iostream>

using namespace std;

// Class Templates with Same Names Can be overloaded using different number of arguments and using default arguments or fixed placeholders

template <class T1, class T2>   //T1 represents first data type and T2 second data type . These rules are same as T like they can represent int , char ,float, double or even a derived data type etc.
class MyClass
{
    T1 data1;
    T2 data2;
public :
    MyClass() : data1(T1()), data2(T2()) {}
    MyClass(T1, T2  );
    void display();
};


template <class T1, class T2>
MyClass<T1,T2>::MyClass(T1 a, T2 b )
{
    data1 = a;
    data2 = b;
}

template <class T1, class T2>
void MyClass<T1,T2>:: display()
{
    cout<<data1<<endl<<data2<<endl<<endl;  //Either this or this->data1 and this->data2
}

int main()
{
    MyClass <int,char>obj1(1,'c');  //Here T1 variables will be int and T2 will be char

    //obj1 = MyClass <int,char>(4,'c'); //For using , make sure to have blank / default constructor
    //Above code can be done now as there is no dynamically allocated member so we can use parameter constructor and then compiler generated copy assignment operator
    obj1.display();


    return 0;
}










