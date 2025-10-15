#include <iostream>

using namespace std;

// Multilevel Inheritance :
// A->B->C and so on in a chain like structure
// Constructor Order matters (if any) : A,B,C
// Destructor Order matters : C,B,A
// They are called like this from base to most derived class for constructor and reverse for destructor when object of the most derived class is made


// Subobjects :
/*
[C object]
 ├─ B subobject
 │   └─ A subobject
 └─ C-specific part
*/

// Forward Declare any class you want to declare , with or without inheritance
class Student;
class Exam;

// E.g : Student->Exam->Result
class Student
{
private:
protected:
    int roll_number;

public:
    void get_roll_number();
    void set_roll_number(int);
};

void Student::set_roll_number(int r)
{
    roll_number = r;
}
void Student::get_roll_number()
{
    cout << "The Roll Number of this Student is : " << roll_number << endl;
}

class Exam : public Student
{
protected:
    // Here roll_number is protected already
    float maths;
    float physics;

public:
    // Here get_roll_number and set_roll_number are public
    void get_marks();
    void set_marks(float, float);
};

void Exam::set_marks(float m, float p)
{
    maths = m;
    physics = p;
}
void Exam::get_marks()
{
    cout << "Your marks of Mathematics and Physics are : " << maths << " and " << physics << endl;
}

class Result : public Exam // Multilevel Inheritance , A-B-C is the inheritance path
{
private:
    float percentage;

protected:
    // Here roll_number , maths and physics are protected .
public:
    // Here get_roll_number , set_roll_number , get_marks, set_marks are also present.
    void display();
};

void Result::display()
{
    get_roll_number();
    get_marks(); // Sometimes , nesting member functions is useful as we don't need to put a lot of functions in the main() , we just set their values using cout , cin through main() using setmarks etc and put get marks into our finalized function which will do everything . But the functions we are putting in the finalized function should be public or inherited , otherwise they won't work.
                 //  Nesting member functions is used not only in protected or private access but also sometimes for saving line of code or reducing complexity.
    percentage = (maths + physics) / 2.0;
    cout << "Your Result is : " << percentage << "%" << endl;
    if (percentage >= 90.0)
    {
        cout << "Excellent Result" << endl;
    }
    else if (percentage >= 80.0)
    {
        cout << "Very Good Result" << endl;
    }
    else if (percentage >= 70.0)
    {
        cout << "Good Result" << endl;
    }
    else if (percentage >= 60.0)
    {
        cout << "Average Result" << endl;
    }
    else if (percentage >= 50.0)
    {
        cout << "Poor Result" << endl;
    }
    else
    {
        cout << "You are Fail ! You need to work harder to pass next Year !" << endl;
    }
}

int main()
{
    // We can also make Exam objects but then it won't be able to display result . It will be useful if a student registered has left the school.

    Result huzaifa; // Always try to use the objects which are derived as they already have base class properties plus a few other . But in some cases we also use Base class objects. E.g if there is a person and a police man and a gangster , then all of them can walk so we will create person from base class and other two from derived classes .We should see according to our needs from which class do we have to create an object
    huzaifa.set_roll_number(801637);
    // huzaifa.get_roll_number(); This one is put in display()
    huzaifa.set_marks(100.0, 96.0); // You can use cin in set_marks and create variables there or cin here and create variables here and give the variables as actual arguments
    //  huzaifa.get_marks(); This one is put in display()
    huzaifa.display();

    return 0;
}
