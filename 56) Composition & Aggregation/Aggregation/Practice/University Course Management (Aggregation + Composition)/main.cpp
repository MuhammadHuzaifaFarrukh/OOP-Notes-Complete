#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Student
{
    string name;
    float midterm_marks, final_marks, assignment_marks, total_marks = 0;
    string grade ;
public:
    //This one is necessary as every v[i] of Students will call this
    Student()
    {
        name = "";
        midterm_marks = 0;
        final_marks = 0;
        assignment_marks = 0;
    }
    Student(string n, float mm, float fm, float am ) : name(n), midterm_marks(mm), final_marks(fm), assignment_marks(am)
    {
        cout<<"Student Paramterized Constructor called "<<endl;
        CalculateTotal();
        CalculateGrade();
    }
    void CalculateTotal()
    {
        total_marks = midterm_marks + final_marks + assignment_marks;
    }
    void CalculateGrade()
    {
        if(total_marks>=90)
        {
            grade = "A+";
        }
        else if(total_marks>=80)
        {
            grade = "A";
        }
        else if(total_marks>=70)
        {
            grade = "B";
        }
        else if(total_marks>=60)
        {
            grade = "C";
        }
        else
        {
            grade = "F";
        }
    }

    string getname()
    {
        return name;
    }
    float mid()
    {
        return midterm_marks;
    }
    float fin()
    {
        return final_marks;
    }
    float assignment()
    {
        return assignment_marks;
    }
    float gettotalmarks()
    {
        return total_marks;
    }
    string getgrade()
    {
        return grade;
    }

    void show()
    {
        cout<<name<<"\t"<<midterm_marks<<"\t"<<final_marks<<"\t"<<
            assignment_marks<<"\t"<<total_marks<<"\t"<<grade<<"\n";
    }
};

class Courses
{
    string coursecode;
    vector<Student> v;
    float avg = 0.0;
    float low = 0, high = 0;
    int count_pass = 0;
    int count = 0;
    int count_grade = 0;

public:
    Courses()
    {
        coursecode = "";

    }
    Courses(string cc) : coursecode(cc)
    {
        cout<<"Courses Paramterized Constructor Called"<<endl;
    }
    void AddStudent(Student s)
    {
        v.push_back( {s.getname(), s.mid(), s.fin(), s.assignment()} );
        count++;
    }
    void generate_report()
    {
        calculateclassavg();
        highest();
        lowest();
        passpercentage();
        cout<<"Course Code : "<<coursecode<<endl;
        cout<<"Name\tMid\tFinal\tAssignment\tTotal\tGrade"<<endl;
        for(int i = 0 ; i<v.size() ; i++)
        {
            v[i].show();
        }
        cout<<"Lowest Marks : "<<low<<endl;
        cout<<"Highest Marks : "<<high<<endl;
        cout<<"Average Marks : "<<avg<<endl;
        cout<<"Percentage Passed : "<<count_pass/v.size()*100<<endl;
        cout<<"Number of students who got A+ :"<<countgrade("A+")<<endl;
        cout<<"Number of students who got A :"<<countgrade("A")<<endl;
        cout<<"Number of students who got B :"<<countgrade("B")<<endl;
        cout<<"Number of students who got C :"<<countgrade("C")<<endl;
    }
    void calculateclassavg()
    {
        avg = 0;
        for(int i = 0 ; i<v.size() ; i++)
        {
            avg += v[i].gettotalmarks();
        }
        if(v.size()>0)
            avg /= v.size();
    }
    void highest()
    {
        high = 0;
        for(int i = 0 ; i<v.size() ; i++)
        {
            if(high<v[i].gettotalmarks())
            {
                high = v[i].gettotalmarks();
            }
        }
    }
    void lowest()
    {
        low = INT_MAX;
        for(int i = 0 ; i<v.size() ; i++)
        {
            if(low>v[i].gettotalmarks())
            {
                low = v[i].gettotalmarks();
            }
        }
    }
    void passpercentage()
    {
        count_pass = 0;
        for(int i = 0 ; i<v.size() ; i++)
        {
            if(v[i].getgrade()!="F" )
            {
                count_pass++;
            }
        }
    }
    int countgrade(string g)
    {
        count_grade = 0;
        for(int i = 0 ; i<v.size() ; i++)
        {
            if(v[i].getgrade() == g)
            {
                count_grade++;
            }
        }
        return count_grade;
    }
    float get_course_avg()
    {
        return avg;
    }
    string get_name()
    {
        return coursecode;
    }
    vector<Student> getstudents()
    {
        return v;
    }
};

class University
{
    string name;
    vector<Courses> cc;
    float avg = 0.0;
    float high_avg = 0.0;
    string top_course ="";

    int allstudents=0;
public:
    University()
    {
        name = "";
    }
    University(string n ) : name(n)
    {
        cout<<"University Paramterized Constructor Called "<<endl;
    }
    void AddCourse(Courses c)
    {
        cc.push_back( c );
    }
    void generate_report()
    {
        for(int i = 0 ; i<cc.size(); i++)
        {
            cc[i].generate_report();
        }
    }
    void average_all()
    {
        for(int i = 0 ; i<cc.size(); i++)
        {
            avg +=cc[i].get_course_avg();
        }
        avg /= cc.size();
    }
    void students_enrolled_courses()
    {
        for(int i = 0 ; i<cc.size() ; i++)
        {
            allstudents += cc[i].getstudents().size();
        }
    }
    void highest_avg()
    {
        for(int i = 0 ; i<cc.size() ; i++)
        {
            if(high_avg < cc[i].get_course_avg())
            {
                high_avg = cc[i].get_course_avg();
            }
        }
    }
    void FindTopCourse()
    {
        for(int i = 0 ; i<cc.size() ; i++)
        {
            if(high_avg == cc[i].get_course_avg())
            {
                top_course = cc[i].get_name();
            }
        }
    }
    void Summary()
    {
        cout<<"University Name : "<<name<<endl;
        cout<<"Total Courses : "<<cc.size()<<endl;
        cout<<"Total Students : "<<allstudents<<endl;
        cout<<"University Average Marks : "<<avg<<endl;
        cout<<"Top Course (Highest Average) : "<<top_course<<endl;
    }
};
int main()
{
    // Create University
    University uni("Virtual University");
    // Create Course CS101 and add students
    Courses cs101("CS101");
    cs101.AddStudent(Student("Ali", 30, 50, 15));
    cs101.AddStudent(Student("Sara", 40, 38, 12));
    cs101.AddStudent(Student("Hamza", 25, 45, 18));
    uni.AddCourse(cs101);
    // Create Course CS102 and add students
    Courses cs102("CS102");
    cs102.AddStudent(Student("Ayesha", 35, 42, 15));
    cs102.AddStudent(Student("Bilal", 28, 40, 20));
    uni.AddCourse(cs102);


    // Generate reports for all courses
    uni.generate_report();
    // Show University Summary

    uni.average_all();
    uni.students_enrolled_courses();
    uni.highest_avg();
    uni.FindTopCourse();
    uni.Summary();

    return 0;
}
