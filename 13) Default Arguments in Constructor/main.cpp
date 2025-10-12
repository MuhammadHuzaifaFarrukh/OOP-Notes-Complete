#include <iostream>

using namespace std;

//Default Arguments can be used in constructors like normal functions
//But there can be errors if we use default arguments and constructor overloading for almost same number / type of arguments as it becomes hard for compiler to identify in the function call as well

class Simple
{
private:
    int data1,data2;
public:
    Simple(int ,  int );
    void printdata();
};

Simple::Simple(int a,  9) //Default Argument b=9
{
    data1=a;
    data2=9;
}

void Simple::printdata()
{
    cout<<"The Data 1 and Data 2 are : " <<data1<<" and " <<data2<<" respectively"<<endl;
}

int main()
{
    Simple s = Simple(1); // Simple(1,4) Here 4 will overwrite 9 in the function parameter
    s.printdata();
    return 0;
}





