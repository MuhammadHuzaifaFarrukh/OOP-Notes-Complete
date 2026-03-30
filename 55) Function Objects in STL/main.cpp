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
    // Here we can also write other class functors also known as Functor Composition / Wrapping
    // This is used when we want to have multiple relational or arithmetic expression solving for a class but function overloading doesn't allow it.
    // Therefore we make each function in a separate struct for this purpose and then use the instance of this struct.
    // Mainly used in User Defined Data Types where a data structure like vector or heap of our own class objects needs sorting but we haven't overloaded < or > then we use separate structs for more professional way , although overloading is much more easier. 
    
};

int main()
{
    int arr[] = {20,10,30,40,35,23,22,70};
    int i;
    //sort(arr , arr+7);
    sort(&arr[0], &arr[7], greater<int>()); 
    /*
    // We could also do it like this :
    // std::greater<int> myObj; // Create instance
    // std::sort(&arr[0], &arr[7], myObj); // Pass instance
    greater<int> is called almost NLogn times as std::sort works in O(Nlogn). 
    */


    //greater<int> is a functor as we are calling the code :
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
    // For having multiple relational operations of a class in a functor , we usually implement them in separate structs instead of the original class as function overloading like this won't be allowed.
    // For our User Defined Class :
    // E.g : Using vector<myclass> st , we want to sort then : sort(st.begin() , st.end() , greater<myclass>)

    //Another example using greater<int>
    // Named instance approach :
    greater<int> comp;           // Create named functor
    bool result = comp(5, 3);    // Use it like a function , Just like comp.operator().(5,3)
    cout << result << endl;      // Output: 1 (true)
    
    // For our User Defined Class :
    // E.g : Using vector<myclass> st , we want to sort then : sort(st.begin() , st.end() , myc) where myc is an object of greater<myclass> which contains that relational operation ()
    // So in our class , while using the less or greater<myclass> , our myclass needs to have the overloaded functions < or >.
    // But if we do the Functor Composition then we simply pass that , not the greater or less or etc , we pass our custom functor.
    // E.g Passing our own MinCompare struct instead of overloading > for the greater<int> then we will write: sort(st.begin() , st.end() , MinCompare) or you can instantiate MinCompare and then pass it as discussed above.

    //Using our own function object
    Add a1, a2;  // Create an instance of the Add functor

    int result = a2(3, 5, 7);  // User-Defined , Using the functor instance like a function , just like a2.operator()(3,5,7);
    //Objects treated like function , Member function used like a normal function as above line
    std::cout << "Result of adding : " << result << std::endl;

    return 0;
}
