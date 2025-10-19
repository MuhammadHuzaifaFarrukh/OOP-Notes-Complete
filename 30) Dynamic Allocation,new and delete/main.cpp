#include <iostream>

using namespace std;

int main()
{

    int *ptr1=new int;
    *ptr1=4;

    float *ptr2= new float(5.23);

    cout<<"Value at address ptr1 is " <<*ptr1<<endl;
    cout<<"Value at address ptr2 is " <<*ptr2<<endl;

    int *arr = new int[3]; //Specifying the size of array as 3
    arr[2] = 5;   //But unlike pointers of variables , we assign value in array without * here , dynamic initialization.
    //The memory would leak even if I comment it out after running it once. So whole memory space for array of 3 elements will waste away
    cout<<"The value of arr[2] is : " <<arr[2]<<endl;

    delete ptr1;
    delete ptr2;
    delete[] arr;

    ptr1=nullptr;
    ptr2=nullptr;
    arr=nullptr;

    //The value after delete[] might still be there or waiting to be overwritten by other programs

    /*
     How to access a deleted dynamically allocated memory or change value of it.
    int *ptr = new int(3);
     cout<<ptr<<endl;
     delete ptr;

     ptr= nullptr;
     ptr = new int(5);  // Here no need to initialize and declare ptr again . new int means that in heap , a dynamically allocated memory is for a value which will be pointed by the pointer ptr. ptr stores the address of that location

     cout<<*ptr<<endl;
    cout<<ptr;
    //delete ptr;
    //ptr = nullptr;

    */


    return 0;
}
