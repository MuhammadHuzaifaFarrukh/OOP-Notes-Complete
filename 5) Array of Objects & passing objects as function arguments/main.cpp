#include <iostream>

using namespace std;

//Array of Objects
class emp
{
private:

    int salary;
public:
    int id;
    void get_id();
    void set_id();
};

void emp::get_id()
{

    cout<<"Your ID is : "<<id<<endl;
}
void emp::set_id()
{
    salary=122;
    cout<<"Enter your ID : ";
    cin>>id;
}

int main()
{
    //emp goku;
    // goku.set_id();
    //goku.get_id();


    emp fb[4];
    //Array storing 4 objects of type emp
    for(int i=0; i<4 ; i++  )
    {
        fb[i].set_id();
        fb[i].get_id();
    }
    cout<<fb[0].id;
    return 0;
}



//Passing Objects as arguments / using Objects as paramters in member functions
//Here it doesn't matter if the data of class is public or private as we are working with member functions


/*
class complex
{
private:
    int a,  b;
public:
    void complex_no_display(int,int );
    void complex_no_sum( complex , complex);
    void print_numbers();

};
void complex::complex_no_display( int a1, int b1 )
{
    a=a1;
    b=b1;
}
void complex::complex_no_sum( complex o1, complex o2 )
{
    a=o1.a+o2.a;  //c1=o1 and c2=o2
    b=o1.b+o2.b;
}

void complex::print_numbers()
{
   cout<<"The complex number is "<<a<<"+"<<b<<"i"<<endl;
}

int main()
{
    complex c1 , c2 , c3;

    c1.complex_no_display(3,4);
    c1.print_numbers();  //c1.a=3  and c1.b=4

    c2.complex_no_display(5,6);
    c2.print_numbers();  //c2.a=5 and c2.b=6



    //c1 and o1 are object no 1 , c2 and o2 are object no 2
    c3.complex_no_sum(c1,c2);
    c3.print_numbers();   //c3.a = 8  and c3.b =10

    return 0;
}
*/

//We can also pass the objects as arguments to a normal functions and work with its data if the object's data is public
//Otherwise , if the object's data is private , and we need to pass the object using normal function then we use friend functions and make this normal function as friend function of our class or make another class' member function as friend of this class etc
