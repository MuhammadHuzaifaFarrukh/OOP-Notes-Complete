#include <iostream>

using namespace std;

// Can be overloaded as well using different number of arguments and using default arguments or fixed placeholders

template <class R1 = int, class R2 = string>   //T1 represents first data type and T2 second data type . These rules are same as T like they can represent int , char ,float, double etc.
class MyClass
{
    R1 data1;
    R2 data2;
public :
    MyClass() {}  //Blank Constructor if there is no initialization at the first step.
    MyClass(R1, R2  );
    void display();
    void SetData(R1, R2);
};


template <class R1, class R2 >
void MyClass<R1,R2 >::SetData(R1 a, R2 b )
{
    data1 = a;
    data2 = b;
}

template <class R1, class R2 >
void MyClass<R1,R2 >:: display()
{
    cout<<data1<<endl<<data2<<endl<<endl;  //Either this or this->data1 and this->data2
}

int main()
{
    MyClass <>obj1;  //Here T1 variables will be int and T2 will be char
    // MyClass <double , long int>obj1;  //This will overwrite the data types specified at the first step R1 and R2.
    obj1.SetData(1,"Hello World");
    obj1.display();


    return 0;
}










