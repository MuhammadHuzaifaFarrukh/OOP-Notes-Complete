/*#include <iostream>

//If a normal function is using private data from both classes or more classes then it should be a friend in all those classes
using namespace std;
class Y; // Y should be forward declared as it is used in X class

class X
{
private:
    int data;
public:
    void setvalue(int value)
    {
        data = value;
    }
    friend void add(X,Y);
};


class Y
{
private:
    int num;
public:
    void setvalue(int value)
    {
        num = value;
    }
    friend void add(X,Y);
};

void add(X o1, Y o2)
{
    cout<<"Summation : " <<o1.data+o2.num;
}

int main()
{
    X a;
    a.setvalue(3);

    Y b;
    b.setvalue(5);

    add(a,b);
    cout <<endl<< "Hello world!" << endl;
    return 0;
}*/









//CALL BY REFERENCE TO SWAP VALUES OF VARIABLES
//If you pass any numbers to change parameters in private members then it won't do it
//so do this by passing objects like below :

#include<iostream>
using namespace std;

class c2;//Forward declaration as c1 and exchange friend function is using c2.

class c1
{
private:
    int val1;
    friend void exchange(c1 &, c2 &);
public:
    void indata(int a)
    {
        val1=a;
    }
    void display()
    {
        cout<<val1<<" and ";
    }
};

class c2
{
private:
    int val2;
    friend void exchange(c1 &, c2 &);
public:
    void indata(int a)
    {
        val2=a;
    }
    void display()
    {
        cout<< val2<<endl;
    }
};


//Trick to swap two variables  :
//1) temp =a;          2) a=a+b;                 3) a=a^b;
//   a=b;                 b=a-b;                    b=a^b;
//   b=temp;              a=a-b;                    a=a^b;



void exchange(c1 &x, c2 &y)  //oc1=&x or oc1=x and oc2=&y or oc2 = y , using call by reference
{
    // Without & , the values will not swap.
    int temp = x.val1; //temp (34) = a (34)    , Also Temp and x and y are different data types so we use x.val1 and y.val1 to make them integers as well . x and y are objects in fact.
    x.val1=y.val2;     //a (67) = b (67)
    y.val2=temp;       //b (67) = a (34)
}                      // Now b is 34 and a is 67
int main()
{
    c1 oc1;
    c2 oc2;

    oc1.indata(34);  //oc1.val1 = 34
    oc2.indata(67);  // oc2.val2=67
    exchange(oc1,oc2); //A friend function called like a simple function

    cout<<"The values after exchanging become : " ;
    oc1.display();
    oc2.display();

    return 0;

}



























/*
CALL BY POINTERS  :
#include <iostream>
using namespace std;

class c2; // Forward declaration

class c1
{
private:
    friend void swap_by_pointer(c1* , c2* ) ;
    int val1;
public:
    void indata(int a)
    {
        val1 = a;
    }
    void display()
    {
        cout << val1 << " and ";
    }
    // Add a function to swap using call by pointer

};

class c2
{
private:
    int val2;
   friend void swap_by_pointer(c1* , c2* ) ;
public:
    void indata(int a)
    {
        val2 = a;
    }
    void display()
    {
        cout << val2 << endl;
    }
};

 void swap_by_pointer(c1* x, c2* y)
{
    int temp = (*x).val1; // Dereference first to access member
    (*x).val1 = (*y).val2;
    (*y).val2 = temp;
}

int main()
{
    c1 oc1;
    c2 oc2;

    oc1.indata(34);
    oc2.indata(67);

    // Call swap_by_pointer from c1 object
    swap_by_pointer(&oc1, &oc2);

    cout << "The values after exchanging become: ";
    oc1.display();
    oc2.display();

    return 0;
}
*/



















/*
//Swapping of two objects' data without using friend functions (by using the member functions)
#include<iostream>
using namespace std;

class X
{
private:
    int val;
public:

    void indata(int a)
    {
        val=a;
    }

    void setdata( X & , X &);
    void displaydata()
    {
        cout<<val;
    }
};

void X::setdata( X &x , X &y) //demo1=x so demo1.val=x.val and y=demo2 so demo2.val=y.val
{
    int temp = x.val;
    x.val=y.val ;
    y.val=temp;
}

int main()
{
    X demo1,demo2;
    demo1.indata(34); //demo1.val=34;
    demo2.indata(67); // demo2.val=67;

    demo1.setdata( demo1 , demo2 ); // Or you can write demo2.setdata(demo1 , demo2) as it is not a friend function so it needs to be called by mentioning object name .

    cout<<"Value after swapping is : " ;
    demo1.displaydata();  // Not a friend function so called with object
    cout<<" and ";
     demo2.displaydata();

    return 0;

}

*/
































