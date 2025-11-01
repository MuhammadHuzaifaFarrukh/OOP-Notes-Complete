#include <iostream>


using namespace std;
//Just like we use classes , now we will use this class as a template for other classes if we wanna use these functions for other data types like float , char , int etc
//If you don't initialize  the object in declaring from template and you have no constructors defined or declared in template then compiler will provide you a default / blank constructor.


//For Defining normal functions inside class , we do it normally and outside we just use a scope resolution operator with it

//For Template Classes , functions inside class , definition is done normally
//But for outside definition , the syntax is :

// template <class_name T>
// Return_Type class_name<T>::function_name(class_name<T> &v){ }
// Here & sign is optional but still its good things when you want to use compiler generated copy constructor in case of dynamic members of a class
// Parameters are also optional here as we can do any number and any data type of paramters


//Below , we can use either class or typename keyword , both are interchangeable
template <class T>  //T will represent the data types here . We will change all the data types to T except for a few things like array index and the dummy variables in the form of index or in the form of class objects itself
class vector    //We can also write A , B ,C or any alphabet other than T.
{
public :
    T *arr;     //Might be any data type
    int size;  //It is always int.

    vector(int);
    T DotProduct(vector &);
    //vector() { size = 0; arr = nullptr; } // ADDED DEFAULT CONSTRUCTOR
    void say();
    /*
    Use this syntax when making the function definition with declaration
    vector(int m)
    {
        size = m;
        arr = new T[size]; //Might be any data type
    }



    T DotProduct(vector &v)  //v2 is like v now . As a template , T will return any data type now
    {
        T result;
        for(int i = 0 ; i<size  ; i++ )  // i is index here
        {
            result +=  ((this->arr[i])*(v.arr[i]));   //OR result = result + ((this->arr[i])*(v.arr[i]));
        }   // v.arr[i] means the 2nd vector of which the reference is in this function and this-> means that vector for which this function is being called. So 1st vector will be already present as its function is being called and we are adding the corresponding array elements in the result to find dot product which is never a vector but a scalar



        return result;
    }



    void say()
    {
        cout<<"Hello Friends " <<endl;
    }
    */






    //Copy Constructor (Preferred for dynamic Allocation and Deep Copying)
    /*
    //  (copy constructor)
    vector(const vector &other)
    {
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    */
    ~vector()
    {
        delete[] arr;
        arr = nullptr;
    }
};


template <class T>  // Defining  a member function outside a class template
T vector<T>::DotProduct(vector<T> &v)
{
    T result = 0;
    for (int i = 0; i < size; i++)
    {
        result += arr[i] * v.arr[i];
    }
    return result;
}

template <class T> // Defining  a member function outside a class template ( constructor )
vector<T>::vector(int m)
{
    size = m;
    arr = new T[size]; //Might be any data type
}

template <class T>
void vector<T>::say()
{
    cout<<"Hello Friends " <<endl;
}



int main()
{
    /*Using without a template (like a class only )
    vector v1( 3 );
    v1.arr[0] = 10;
    v1.arr[1] = 11;
    v1.arr[2] = 12;

     vector v2 ( 3 );
    v2.arr[0] = 1;
    v2.arr[1] = 2;
    v2.arr[2] = 3;

    int dotprodmain = v1.DotProduct( v2 ); // either this or v2.Dotproduct(v1) , we can do the self dot product by call by pointer  and in the for loop changing v.arr to v->arr

    cout <<dotprodmain<<endl;
    */


    //Using a template now
    vector <float>v1(5); //Here this template works for float data type and v1 passes 3 to its constructor called implicitly as defined by us in the template
    //Can also call it even after not initializing it , by simply using :
    //So Constructor is called only once but this type of initialization makes us think it is called explicitly as well which will fail if we don't have our custom copy assignment operator and still use it
    //v1 = vector<float>(5); //This will need the default copy assignment operator as first it calls the constructor not for this but for a brand new object and then using "=" operator compiler generates its own copy assignment operator but because in dynamic allocation it not works so we make our own copy assignment operator to make it work

    v1.arr[0] = 1.2;
    v1.arr[1] = 2.3;
    v1.arr[2] = 3.4;

    vector <float>v2 ( 3 );
    v2.arr[0] = 10.1;
    v2.arr[1] = 11.2;
    v2.arr[2] = 12.3;

    float dotprodmain = v1.DotProduct( v2 ); //Now this line will get us error if we have the paramter of DotProduct as only value not by reference , bcz it invokes the compiler generate copy constructor which does not work in case of dynamically allocated heap memory and so shallow copy issue arrives , instead either define your copy constructor or if not then use &sign to avoid compiler generated copy constructor
    cout <<dotprodmain<<endl;
    v1.say();



    return 0;
}












/*
//Making our Bank class a template to improve code reusability
#include <iostream>

using namespace std;

template <class T>
class bank
{
private :

    T principal;
    T years;
    T return_value;
    T interest_Rate;

public :





void show()
{
    cout<<endl<<"Principal Amount was "<<principal<<endl
    <<"Return Value after "<<years<<" years is " << return_value<<endl;

}

    bank(T &p, T &y, T &r)  //Or simply T p, T y , T r
    {
        principal=p;
        years=y;
        interest_Rate=r;
        return_value=principal;
        for(  int i=0 ; i <y  ;i++)
        {
            return_value = return_value*(1+interest_Rate);
        }
    }


};









int main()
{

    float p , y, R;  // Objects are not initialized yet

    cout<< "Enter your Principal Amount : ";
    cin>>p;
    cout<< "Enter your number of years : ";
    cin>>y;
    cout<< "Enter your interest Rate like 1% to 0.01 : ";
    cin>>R;
   bank <float>person1(p,y,R); // Dynamic Initialization (Runtime Initialization)
    person1.show();


    return 0;
}

*/

















/*
//Using inheritance template and it is different than the one without templates
// Here we use this pointer or :: operator or using Base<T>


#include <iostream>


using namespace std;
//Just like we use classes , now we will use this class as a template for other classes if we wanna use these functions for other data types like float , char , int or even a derived data type etc.

template<class T>
class Base
{
public:
    T data;

    void setData(T value)
    {
        data = value;
    }
};

// Derived class template inheriting from Base template
template<class T>
class Derived : public Base<T>
{
public:
    //Inside the Derived class , we cannot access the data members directly , even though we can from main()
   //using Base<T> data; can be alternate
    void displayData()
    {
        std::cout << "Data from Derived: " <<Base<T>::data << std::endl;  // You cannot access data directly here now. Use this approach or this->data or using Base<T> data
    }
};

int main()
{
    Derived<int> obj;
    obj.setData(42);
    obj.displayData();

    return 0;
}
*/




//You can also make friend functions as template functions :
// 3 Ways to do but we will write most common one :
// 1. Non-Template Friend of a Template Class (Most Common)
// A regular function (not a template itself) is made a friend of a specific instantiation of a template class
// return_type function_name(const class_name<T? &obj){} and use this in class public area : friend return_type function_name<T>(const class_name<T> & obj);

// 2. Template Friend of a Non-Template Class
// Here, the class is not a template, but the friend function is.

// 3. Template Friend of a Template Class (Full Template)
// This is the most complex scenario, where a function template is declared as a friend of a class template.
// It typically requires an out-of-body declaration of the template function inside the class body,
// usually involving some form of injected class name or helper struct.


//There might be other cases like when a function is from another class and is the friend of another class becoming a template etc
