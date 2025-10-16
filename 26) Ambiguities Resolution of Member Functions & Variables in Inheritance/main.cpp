#include <iostream>

using namespace std;

//When derived class uses same name for its variable and functions as that in base class then it is called name hiding or function hiding
//Functions might get hidden due to this (Function Hiding or Name Hiding)
//Member variables also get hidden due to this (Name Hiding)


//Resolving Ambiguities in Member Functions and Variables in Single Inheritance
//The case in local variables will be same as that of the static variables
class base
{
public:
    int a=6;
    void say()
    {
        cout<<"Hello World"<<endl;
    }

};


class derived : public base
{
public:

    int a=32; //Overwrites the values from base classes
    //Will use previous one if not overwritten
    void say()
    {
        //You will have to specify like this in order to use it : base::say();

        cout<<"Hello Buddies"<<endl; //Uses its own function   Overwrites the previous one
        //Will use previous one if not overwritten

    }


};

int main()
{
    derived d;
    d.say();

    // cout<<endl<<d.a<<endl;
    return 0;
}























/*
//To refer a base class member in derived class object .
#include <iostream>

using namespace std;

//Resolving Ambiguities in Member Functions and Variables in Single Inheritance
//The case in local variables will be same as that of the static variables
class base
{
public:
    int a=6;
    void say()
    {
        cout<<"Hello World"<<endl;
    }

};


class derived : public base
{
public:

    int a=32; //Overwrites the values from base classes
    //Will use previous one if not overwritten
    void say()
    {

        cout<<"Hello Buddies"<<endl; //Uses its own function   Overwrites the previous one
        //Will use previous one if not overwritten

    }


};

int main()
{
    derived d;


    cout<<endl<<d.base::a<<endl;//Referring bsae class variable in derived object
    d.base::say();   //Referring base class function in derived object

    return 0;
}
*/

























/*
//Resolving Ambiguities in Member Functions and Variables in Multilevel Inheritance
class base
{
public:
    int a=6;
    void say()
    {
        cout<<"Hello World"<<endl;
    }

};
class derived1 : public base
{
public:
    int a=7;

    void say()
    {
        cout<<"Hello Friend"<<endl;
    }
};


class derived2 : public derived1
{
public:
    // int a=8;  // Overwrites the value of 'a'
    // using base::a;  //Uses a=6 from base class and will provide error if the above line is also written as well.
    void say() // Own Function
    {
        //cout<<"Hello Buddies"<<endl; Uses its own function
        base::say();   //Uses the function in base class through nesting member functions
        cout<<endl <<base::a;   // You can also access base class 'a' , without "using" like this .
    }


};

int main()
{
    derived2 d;
    d.say();

    // cout<<endl<<d.a<<endl;
    return 0;
}

*/















/*
//Resolving Ambiguities in Member Functions and Variables in Multiple Inheritance
class base1
{
public:
    int a=6;
    void say()
    {
        cout<<"Hello World"<<endl;
    }

};
class base2
{
public:
    int a=7;

    void say()
    {
        cout<<"Hello Friend"<<endl;
    }
};


class derived : public base1,public base2
{
public:

    // int a=32; overwrites the values from base classes
    using base2::a;  //Uses the 'a' from base2 class and above line generates error
    void say()
    {
        base1::say();   //Uses the function in base class through nesting member functions
        // cout<<"Hello Buddies"<<endl; Uses its own function

    }


};

int main()
{
    derived d;
    d.say();

    // cout<<endl<<d.a<<endl;
    return 0;
}
*/










/*
//Ambiguity Resolution of Member Functions and Variables in Hierarchical Inheritance
class A
{
public:
    int a=6;
    void say()
    {
        cout<<"Hello World"<<endl;
    }

};

class B :  public A
{
public:
    void say()
    {
        cout<<"Hello Buddies"<<endl; //This will overwrite the member function of A, but you can still access former one by "using" or just nested member functions or referring base class function in derived object
    }


};
class C :  public A
{

public :
    // int a=8;  //Overwrites the base class A member variable
    void say()
    {
        cout<<"TAAAA "<<endl;  //This will overwrite the member function of A
    }

};


int main()
{
    C c1;
    // cout<<c1.a<<endl;
    c1.say();

    return 0;
}

*/















/*
//Ambiguity Resolution of Member Functions and Variables in Hybrid Inheritance
#include<iostream>
using namespace std;
//Hybrid Inheritance
//Student --> Test
//Student --> Sports
//Sports + Test ---> Result


class Student
{
private:

protected:
    int roll_no;
public:
    void set_number(int a)
    {
        roll_no = a;
    }
    void print_number(void)
    {
        cout<<"Your roll no is "<< roll_no<<endl;
    }
};

class Test :   public Student  // Student inherits it a set_number function
{
private :

protected:
    float maths, physics;
public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void print_marks(void)
    {
        cout << "You result is here: "<<endl
             << "Maths: "<< maths<<endl
             << "Physics: "<< physics<<endl;
    }
};

class Sports:   public Student   // Student inherits it a set_number function
{
private :


protected:
    float score;
public:
    void set_score(float sc)
    {
        score = sc;

    }

    void print_score(void)
    {
        cout<<"Your PT score is "<<score<<endl;
    }

};

class Result :  public Test, public  Sports //To avoid set_number coming here two times , we need to resolve this ambiguity . Virtual Base Class allows its derived classes to inherit only one member function or variable to further derived class
{

private:
    float total;
public:
    void display(void)
    {
        // total = maths + physics + set_score(9);  //It will be wrong as the data type of this function is void
        //total = maths + physics + score;   //This will create error as the score is private so it cannot be used or inherited in the function of derived class
        total = maths + physics + score; // No Error if score is public

        Test::print_number(); //Nesting Member Functions
        //Either use Test or Sports::print_number()

        print_marks();  //Nesting Member Functions
        print_score();  //Nesting Member Functions
        cout<< "Your total score is: "<<total<<endl;
    }
};
int main()
{
    Result huz;
    huz.Test::set_number(4200);
    huz.set_marks(99, 99.5);
    huz.set_score(7);
    huz.display();
    // cout<<endl<<huz.Sports::roll_no ;  // It will solve ambiguity for roll number if roll number is public
    // cout<<endl<<huz.Test::roll_no ;     // It will solve ambiguity for roll number if roll number is public
    // cout<<endl<<huz.Result::roll_no ;  //Error as no direct access for protected ones.
    // cout<<endl<<huz.Student::roll_no ; // Error as Student class is not linked directly to Result class


    return 0;
}
*/

