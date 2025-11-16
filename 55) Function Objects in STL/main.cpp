#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

struct Add    //Here we make a function object using operator() , const might be a good practice
{
    mutable int b1=3;
    int operator()(int a, int b)const
    {
        return a + b;
    }
    int operator()(int a, int b, int c)const // They can be overloaded as well
    {
        b1 = 7;
        cout<<b1<<endl;
        return a + b + c;
    }
};

int main()
{
    int arr[] = {20,10,30,40,35,23,22,70};
    int i;
    //sort(arr , arr+7);
    sort(&arr[0], &arr[7], greater<int>()); //greater<int> is a functor as we are calling the code :
    /*
    // This is what greater<int> looks like (simplified not actual code):
    template<typename T>
    struct greater
    {
        bool operator()(const T& a, const T& b) const
        {
            return a > b;  // This makes it sort in descending order
        }
    };

    */
    for( i = 0; i<8 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Using our own function object
    Add a1, a2;  // Create an instance of the Add functor

    int result = a2(3, 5, 7);  // User-Defined , Using the functor instance like a function , just like a2.operator()(3,5,7);
    //Objects treated like function , Member function used like a normal function as above line
    std::cout << "Result of adding : " << result << std::endl;


    //Another example using greater<int>
    // Named instance approach :
    greater<int> comp;           // Create named functor
    bool result = comp(5, 3);    // Use it like a function , Just like comp.operator().(5,3)
    cout << result << endl;      // Output: 1 (true)
    return 0;
}
