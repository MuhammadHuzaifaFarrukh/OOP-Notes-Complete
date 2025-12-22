#include <iostream>

using namespace std;

//============== Member (Name) Hiding in INHERITANCE ============
//When derived class uses same name for its variable and functions as that in base class then it is called name hiding or function hiding
//Functions might get hidden due to this (Function Hiding or Name Hiding)
//Member variables also get hidden due to this (Name Hiding)
//In Function Hiding , only name matters , not return type or parameters

//We have total 3 solutions for Ambiguity Resolution :
//1) Specifying the Member by "using" keyword inside the class
//2) By Scope Resolution Operator (::)
//3) Redefining the Function and then using class_name::function() in that function and for variable , redefining another one variable with same purpose as you wanted
// These ambiguities usually occur in Multiple and Multilevel Inheritance and are rare in other types of inheritance


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
    //There's no use of "using" here
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
























//Compiler sees two different functions/variables in the lowest class in hierarchy , and will be ambiguous
//So we will resolve this ambiguity of function hiding (or generally : Member Hiding)
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
    // You may also write :
    // using derived1::say;     //using keyword works fine with member functions , but will throw error if used with member variables if they are redefined
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
    //May use Scope Resolution also to solve ambiguity if public members

    // cout<<endl<<d.a<<endl;
    return 0;
}

*/














//Ambiguity in Multiple Inheritance :
//Here we observe Triangular conflict that is , same named member functions / variables when inherited in multiple
//inheritance then this creates ambiguity to choose which one in the instantiated class
//The Name of the function/variable is same but their purpose / implementation might be different in the classes that define them
//When inherited in the lower hierarchy , compiler doesn't know which one to use as it sees two different functions/variables with same names


//This can be solved by either scope resolution operator (::) or writing another member function / variable
//that hides the other one , or by specifying in another class by "using" keyword
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
    // You may also write :
    // using derived1::say;     //using keyword works fine with member functions , but will throw error if used with member variables if they are redefined

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
    //May use Scope Resolution also to solve ambiguity if public members

    // cout<<endl<<d.a<<endl;
    return 0;
}
*/
// =========ANALOGY============
//It s like having two different friends named "John." If you just shout "John!", everyone is confused.
//You didn't "copy" John; you just have two different people with the same name










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
    //Can do "using" or call base function in the redefined function but it would be useless
};
class C :  public A
{

public :
    // int a=8;  //Overwrites the base class A member variable
    void say()
    {
        cout<<"TAAAA "<<endl;  //This will overwrite the member function of A
    }
    //Can do "using" or call base function in the redefined function but it would be useless
};


int main()
{
    C c1;
    // cout<<c1.a<<endl;
    c1.say();
    //May use Scope Resolution also to solve ambiguity if public members

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

//Here we resolve the ambiguity as compiler sees functions/variables on two different memory location for the same base class functions/variables
//Memory is also wasted as compiler contains two copies of variables/functions of A class inside D through class B and C
//This problem is referred to diamond problem which we will discuss later
//Trying to do "using" also fails here
//Here we try to resolve it using scope resolution inside classes , and use the intermediate classes to bring the functions/variables from the base class
//Although after this , the compiler still sees two different memory locations but we will tell it to use the intermediate
//classes functions/variable paths to use , and now we keep one class fixed for this purpose (here either Test or Sports)


//This problem is just like Multiple Inheritance but now due to having two copies of the base members , updating one ,requires
//updating the other as well , also memory wastage and redundancy
//The Difference is that in Multiple Inheritance , the two functions although had same names , but we used them for different
//purpose and different implementation , same goes for variables, so we didn't need to update the other
//But here the two functions/variables coming are actually copies so even if we set / execute one , the other one is not set / executed as we
//set/execute them through B and C class , not from class A


//Here we use Scope Resolution Operator and Nesting Member Function Method to resolve ambiguity
//"using" keyword does not help here
//When we solve this , we are only updating the Sports or Test class' roll_no , so one class will have their roll_no
//uninitialized so we need to make sure that updating one class , and then we use the details of this same class
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
    //float score;


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
    //Use below function if score is private
//    float get_score()
//    {
//        return score;
//    }
};

class Result :  public Test, public  Sports //To avoid set_number and roll_no coming here two times , we need to resolve this ambiguity
{
private:
    float total;
public:
    void display(void)
    {
        // total = maths + physics + set_score(9);  //It will be wrong as the data type of this function is void
        //total = maths + physics + score;   //This will create error as the score is private so it cannot be used or accessed in the function of derived class
        //total - maths + physics + get_score() ; //Use this if score is private
        total = maths + physics + score; // No Error if score is public / protected

        //Student::print_number();  //Wrong here as this function is ambiguous already

        Test::print_number(); //Nesting Member Functions
        //Either use Test or Sports::print_number()
        //Here a small problem is that roll_no is different in both Test and Sports so when we use Sports or Test class to initialize
        //the roll_no , it only initializes its own roll_no and leaves other class roll_no garbage so when we print it using the other class
        //it prints garbage
        ////Both Test and Sports have separate roll_no which is an issue while setting roll_no and printing it

        print_marks();  //Nesting Member Functions
        print_score();  //Nesting Member Functions
        cout<< "Your total score is: "<<total<<endl;
    }
};
int main()
{
    Result huz;
    huz.Test::set_number(4200);
    //Both Test and Sports have separate roll_no which is an issue while setting roll_no and printing it
    //Here roll_no can be initialized using Test or Sports set_number , not by Student or Result
    //Also if we use Test to initialize roll_no , it leaves the other class roll_no uninitialized and when we use print_number of other class
    //it prints garbage and vice verse , so these are small problems that can only be tackled by virtual inheritance (discussed next)

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

