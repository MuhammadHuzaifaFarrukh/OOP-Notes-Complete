#include <iostream>

using namespace std;


/*

case 1:
class B : public  A
{
  //Order of Execution  : first A() then B() for object of B class
};

case 2 :
class C : public  A , public  B
{
  //Order of Execution  : first A() then B() and then C() for object of C class
};

case 3 :
class C : public  A , public virtual B
{
  //Order of Execution  : first B() , then A() and then C() for object of C Class
};


*/

//The Order matters for non-virtual base classes whereas virtual base class' constructor runs first always


//Constructors in Multiple Inheritance through Member Initialization List
class Base1
{
private :
    int data1;
public :
    //  Base1(){} Necessary if Object is not initialized yet
    Base1(int a)
    {
        data1=a;
        cout<<"Base1 Class Constructor Called "<<endl;
    }

    void printdata1()
    {
        cout<<"The Value of data1 is : "<<data1 <<endl;
    }

};

class Base2
{
private :
    int data2;
public :
    //  Base2(){} Necessary if Object is not initialized yet
    Base2(int a)
    {
        data2=a;
        cout<<"Base2 Class Constructor Called "<<endl;
    }

    void printdata2()
    {
        cout<<"The Value of data2 is : "<<data2 <<endl;
    }

};

class Derived :  public Base2 , public Base1 //Changing Order here matters only for non-virtual classes , whichever is first is constructed
{
private :
    int derived1, derived2;
public:
    //Derived(){} // Necessary if Object is not initialized yet
    Derived(int a, int b, int c, int d ) : Base1(a), Base2(b )      //Changing Order here will do nothiing
    {
        derived1=c;
        derived2=d;
    }
    void printdata3()
    {
        cout<<"The Value of derived1 is : "<<derived1 <<endl;
        cout<<"The Value of derived2 is : "<<derived2 <<endl;
    }
};


int main()
{
    Derived huz(1,2,3,4);
    huz.printdata1();
    huz.printdata2();
    huz.printdata3();

    return 0;
}









/*
//Single Inheritance
class Base
{
private :
    int data1;
public :

    Base(int a)
    {
        data1=a;
        cout<<"Base1 Class Constructor Called "<<endl;
    }

    void printdata1()
    {
        cout<<"The Value of data1 is : "<<data1 <<endl;
    }

};
class Derived : public Base
{
    private :
    int data2;
public :

    Derived(int a , int b) : Base(b)
    {
        data2=a;
        cout<<"Base2 Class Constructor Called "<<endl;
    }

    void printdata2()
    {
        cout<<"The Value of data2 is : "<<data2 <<endl;
    }
};





int main()
{
   Derived huz(5,10);
   huz.printdata1();
   huz.printdata2();


   return 0;

}
*/






/*
//Multilevel Inheritance
class Base
{
private :
    int data1;
public :

    Base(int a)
    {
        data1=a;
        cout<<"Base1 Class Constructor Called "<<endl;
    }

    void printdata1()
    {
        cout<<"The Value of data1 is : "<<data1 <<endl;
    }

};
class Derived1 : public Base
{
    private :
    int data2;
public :

    Derived1(int a , int b) : Base(b) // b=a and a=b and this a gets to Base(b). Point to note that these are all dummy variables . Derived1 Constructor has separate dummy a,b and Derived2 has separate a,b,c dummy variables
    {
        data2=a;
        cout<<"Derived1 Class Constructor Called "<<endl;
    }

    void printdata2()
    {
        cout<<"The Value of data2 is : "<<data2 <<endl;
    }
};


class Derived2 : public Derived1
{
    private :
    int data3;
public :


  Derived2(int a, int b, int c) : Derived1(b,a)  //This passes b,a to derived1 constructor (a,b)
    {
        data3=c;
        cout<<"Derived2 Class Constructor Called "<<endl;
    }

    void printdata3()
    {
        cout<<"The Value of data3 is : "<<data3 <<endl;
    }
};





int main()
{
   Derived2 huz(5,10,20);
   huz.printdata1();
   huz.printdata2();
   huz.printdata3();


   return 0;

}
*/









/*
//Hierarchical Inheritance
class Base
{
private :
    int data1;
public :

    Base(int a)
    {
        data1=a;
        cout<<"Base1 Class Constructor Called "<<endl<<endl;
    }

    void printdata1()
    {
        cout<<"The Value of data1 is : "<<data1 <<endl;
    }

};
class Derived1 : public Base
{
    private :
    int data2;
public :

    Derived1(int a , int b) : Base(a) // (5,10) = (a,b) , passed to Base (a)

    {
        data2=b;
        cout<<"Derived1 Class Constructor Called "<<endl;
    }

    void printdata2()
    {
        cout<<"The Value of data2 is : "<<data2 <<endl;
    }
};


class Derived2 : public Base
{
    private :
    int data3;
public :


  Derived2(int a, int b) : Base(a)    // (20,30) = (a,b) passed to Base(a) in Base constructor

  {

      data3=b;
        cout <<"Derived 2 Class Constructor Called "<<endl;
  }

    void printdata3()
    {
        cout<<"The Value of data3 is : "<<data3 <<endl;
    }
};





int main()
{
   Derived1 huz(5,10);
   Derived2 wal(20,30);
   huz.printdata1();
   huz.printdata2();
   wal.printdata1();
   wal.printdata3();

   return 0;

}
*/








/*#include <iostream>

using namespace std;

class A
{

  public :
    A(){}  //Blank Constructor here is necessary which is used when we have not initialized our member variables of the object yet
    A(int a)
    {
        cout<<"The value of a is : " <<a<<endl;
        cout<<"I'm Constructor from Class A "<<endl;
    }
    A(float a)
    {
        cout<<"The value of a is : " <<a<<endl;
        cout<<"I'm Constructor from Class A "<<endl;
    }



};

class B: public A
{  int a;
  public :
      B(int i, int j) : A(j)
    {
        cout<<"I'm Constructor from Class B "<<endl;
        a=i;
        cout<<"The value of a is : "<<a<<endl;
    }


};


int main()
{

     A obj2;



    return 0;
}
*/














/*
//We can also place the same name variable in member initialization list
#include <iostream>

using namespace std;
class A
{

public:int a;
   A(int a, int b)  : a(a)  // Outer 'a' is member variable and inner is dummy. This is also valid in inheritance  like A (int a , int b ) : B(b) , a(a) {.... }
   {
       cout<<"Value of a is : "<<a<<endl;
   }



};



int main()
{
    A obj1(3,4);
    cout<<endl<<obj1.a;

    return 0;
}
*/









