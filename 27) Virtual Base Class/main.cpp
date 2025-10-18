#include<iostream>
using namespace std;

//Virtual base class is used to overcome the diamond problem in multiple and hybrid inheritance
//                   Student
//                    |   |
//                  Test  Sports
//                    |   |
//                    Result       This is the diamond problem. as Result class will inherit both member variables from Test and Sports from the first base class Student
//This Technique is called virtual inheritance
//The Diamond problem can't be solve by "using" , can be solved by virtual base class or by specifying the function by referring using scope resolution operator


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

class Test :   virtual public Student  // Student inherits it set_number and print_number function
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

class Sports:   virtual public Student   // Student inherits it set_number and print_number function
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
    int roll_no=5;
    void display(void)
    {

        // total = maths + physics + set_score(9);  //It will be wrong as the data type of this function is void
        //total = maths + physics + score;   //This will create error as the score is private so it cannot be used or inherited in the function of derived class
        total = maths + physics + score;

        //Here Test or Sports::print_number() will also work without virtual base classes , but not the "using"
        print_number(); //Nesting Member Functions
        print_marks();  //Nesting Member Functions
        print_score();  //Nesting Member Functions

        cout<< "Your total score is: "<<total<<endl;
    }

};
int main()
{
    Result huz;
    huz.set_number(4200);
    huz.set_marks(99, 99.5);
    huz.set_score(7);
    huz.display();

    return 0;
}



//Member functions among objects are shared but diamond problem can disturb this process
//Also it creates two subobjects (with two two member variables from only one class) leading to ambiguity and memory as well
//Virtual base class solution can help use less memory even if we solve this diamond problem by :: operator by referring

//Without Virtual Base Classes :
/*
D
├── B
│    └── A (1)
└── C
     └── A (2)
//Two copies of A in D now → ambiguity!
*/


//With Virtual Base Classes :
/*
D
├── B
│     ↘
│      (shared virtual base A)
│     ↗
└── C

*/







//Example with Animal Class for Diamond Problem
/*

class Animal
{
public:
    void eat()
    {
        std::cout << "Animal eats" << std::endl;
    }
};

class Mammal : virtual public Animal
{
public:
    void giveBirth()
    {
        std::cout << "Mammal gives birth" << std::endl;
    }
};

class Bird : virtual public Animal
{
public:
    void fly()
    {
        std::cout << "Bird flies" << std::endl;
    }
};

class Bat : public Mammal, public Bird
{
public:
    void display()
    {
        eat(); // Calls Animal::eat()
        giveBirth();
        fly();
    }
};

int main()
{
    Bat b;
    b.display();

    return 0;
}
*/



//Another Example with another problem :
//Suppose now we have A->B , B->C , B+C -> D
/*
//Here A can be neglected or previous chains if no other duplications before this chain as well
D
├── B
│   └── A
└── C
    └── B
        └── A
//When we make D obj , we get the B object copies (2) here , don't consider the previous ones than B now

*/


//We check for the latest class in the chain that is duplicated and its contents being copied more than one time , we put virtual with only that class when declaring other classes from it
//E.g above example can be solved as B is the latest duplicated class being two times duplicated in D
// Put virtual with B when making C and D as B is duplicate and we need to make it a shared class so other derived classes from it will share it only so no duplicate copies will be generated from it in further
// class C : virtual public B and class D : virtual public B , public C
// Now B is shared among C and D class
/*

D
├────
│      ↘
│      (shared virtual base B)
│     ↗
└── C

*/


