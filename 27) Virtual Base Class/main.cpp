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

//As compiler sees functions/variables on two different memory location for the same base class functions/variables
//Can be solved using Scope Resolution Operator to tell exact intermediate class but not a good idea

//This problem is just like Multiple Inheritance but now due to having two copies of the base members , updating one ,requires
//updating the other as well , also memory wastage and redundancy
//The Difference is that in Multiple Inheritance , the two functions although had same names , but we used them for different
//purpose and different implementation , same goes for variables, so we didn't need to update the other
//But here the two functions/variables coming are actually copies so even if we set / execute one , the other one is not set / executed as we
//set/execute them through B and C class , not from class A

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
//If this class had a constructor and a parameterized one then we would have to initialize all three classes above it using member initialization list


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
//When we use virtual inheritance , then a vbtable is made for each class say (A,B,C,D classes)
//Then B and C class contain a separate vbtable for their own vbtable is one per class
//Class D also gets its own vbtable for this purpose

//Now if an object of D is created and the class D contains B and C as sub objects then class B and C for that specific (or each object)
//have a pointer called vbptr
//The vbtable is a static array that stores the distance (offset) from the vbptr to the shared A.
//B’s Constructor runs: It sets the vbptr to point to B's vbtable. (For a brief moment, the object thinks it's just a B).
//C’s Constructor runs: It sets its vbptr to point to C's vbtable.
//D’s Constructor runs: This is the "takeover." It overwrites those pointers. It tells B's vbptr and C's vbptr:
//"Stop looking at your old maps. Use my map (D's vbtable) from now on."
//The vbptrs of B and C are used on and point to the vbtable of D only
//A class only gets a vbtable if it has to look for a virtual base.
//A class only needs a vbptr if it has to "look up" where its parent is.


//Without Virtual the Constructor (if present) would also be called two times for the base
//Constructor order would be : Student , Test , Student , Sports , Result

//With Virtual Inheritance (public Test , public Sports) , the Constructor order is :
//Student , Test , Sports , Result

//With Virtual Inheritance (public Sports, public Test) , the Constructor order is :
//Student , Sports, Test, Result

//The Most Derived class (D) directly builds the class A , keeps it in a special shared location
//and when classes B and C are about to be made inside D
//then B and C are child of virtual parent A so they don't build A , instead they get vbptr to D's vbtable
//Now class D can use the vbptr of B (if B comes first in the inheritance initialization order) to access the data of A

//Member functions among objects are shared but diamond problem can disturb this process
//Also it creates two subobjects (with two two member variables from only one class) leading to ambiguity and more memory as well
//Virtual base class solution can help use less memory even if we solve this diamond problem by :: operator by referring

//Without Virtual Base Classes :
/*
D
├── B
│    └── A (1)
└── C
     └── A (2)
//Two copies of A in D now → ambiguity! through one B and one C sub object
//Class D directly builds
//If all classes are empty we see that D class has a size of 2 bytes (1 from B and 1 from C)
*/


//With Virtual Base Classes :
/*
D
├── B
│     ↘
│      (shared virtual base A , contains int x)
│     ↗
└── C
//D contains only B and C subobjects , sub-object of A inside D is at the end now
//B and C share the A class
//B and C have a vbptr (typically of size 4 bytes on 32 bit / 8 bytes on 64 bit compilers) that lets them see data of class A
//so if all classes are empty then we see that D object has a size of either 8 or 16 bytes
//In D's memory it contains , B Data , C Data , D Data , A Data (Shared)
//Virtual Class Data is always moved to the end
//If a class contains its own vbptr , then it is always at the first before any data members. (in this case D uses from B and C and doesn't have its own vbptr)

*/
// If D : B,C then class D takes shared data of A through B
// If D : C,B then class D takes shared data of A through C
// For Constructor in D , when we write it using member initialization list , then we always try to initialize the class most derived and
// first that is shared as most derived class D initializes A itself and for B and C , you may leave them or initialize them as well
// If you provide a non-parameterized constructor in D , then it will work without any member initialization list


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
//When we make D obj , we get the B object copies (2) here
C class contains a subobj of B while D contains two , one directly from B and one indirectly from C
If all classes are empty and we create an object of class D , and check size of its object then it will be 2 bytes (1 from C and 1 from B)
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
//Now class D contains C as sub object , and D and C both share B
If all classes are empty and we create an object of class D , and check size of its object then it will be 4 bytes (which is the vbptr)
//In D's memory it contains , C Data , D data , B data
//If a class contains its own vbptr , then it is always at the first before any data members. (in this case D uses from C and doesn't have its own vbptr)
*/
//Also when the constructor call runs , and class D virtual public B , public C object is created then two things happen
//B is created first as virtual classes are constructed before normal ones
//Then class C constructor is called and as B is the parent of C , so C tries to call B but as B is created once inside D ,
//therefore the constructor call of C to B is skipped

//Class D builds the object of (A+B) and puts it to a special shared location , then builds C and when C is about to build B
// it sees that B is already built so it skips the constructor of B
//In this setup :
//D contains a vbtable and borrowed vbptr (initially no , but later it takes)
//C contains a vbtable and vbptr (initially it has , but later no)
//C contains a vbptr that points first to the vbtable of C and then to D
//Now compiler uses Optimization in vbptrs and lets D borrow the vbptr of C (same as C) that points to the vbptr of D
//When C's constructor is running: The compiler puts the address of C's vbtable into that (vbptr)
//When D's constructor starts: The compiler overwrites that same space with the address of D's vbtable.
//Now this vbptr belongs to object of D , not C as it points to D's vbtable
//This borrowing happens as class D is made from virtual B and non-virtual C so it prioritizes the non-virtual class to move
//at the top in the memory layout of D , and as B is virtual so it moves B to the very end of the object (that is shared)
//There is only one vbptr in this setup for each object


//Rules for having a vbptr :
//1) NEW ONE :
//A class creates a brand-new vbptr only if it is the first class in its lineage to introduce virtual inheritance.
//Condition: If the class inherits virtual public, but NONE of its parents have a vbptr

//2) NO :
//i)  A class has zero vbptrs if it does not use virtual inheritance and none of its parents do either
//ii) If a derived class has all base class that contain vbptrs then this derived class will not have vbptr of its own e.g original diamond problem

//3) BORROW / SHARING :
//A class borrows (reuses) a vbptr if its primary base class (the first one listed in the inheritance) already has one.
//Condition: class D : public C. Since C already has a vbptr, D just reuses that memory slot.
//It doesn't add any size to the object for a "D-pointer."
//Also like above example


//The vptr or vbptr always points to the table of the constructor currently running.
//
//C is building? Pointer = C's table.
//
//D is building? Pointer = D's table.
//
//D is finished? The pointer stays as D's table for the rest of the object's life.

//Rule of C++ for Empty Class
//If a class is empty (contains no variables) then compiler still gives it 1 byte for memory address
//But if it contains something say (int x) then it has 4 bytes now , not 5
