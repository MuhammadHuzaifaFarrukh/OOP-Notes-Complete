#include <iostream>
#include <utility>
#include <vector>
#include "Skill.h"
#include "Experience.h"
#include "Entry.h"
#include "Resume.h"
#include "Skill.cpp"
#include "Experience.cpp"
#include "Entry.cpp"
#include "Resume.cpp"
using namespace std;

int main()
{
    // Level 1 :
    cout << "Testing Level 1 Classes : " << endl;
    Skill s("C++", 5);
    Entry p("Chatbot", "RAG-Based AI");
    Experience e("Frontend Intern", "6 Months");
    s.show();
    p.showproject();
    e.show();

    // Level 2+3 :
    Resume r;
    r.addSkill("C++", 4);
    r.addSkill("HTML", 3);
    r.addproject("Chatbot", "RAG-Based Chatbot");
    r.addproject("Portfolio", "Basic HTML/CSS Site");
    r.addExperience("Frontend Intern", "6 months");
    r.addEducation("BSCS", "GPA : 3.7");

    // Delete Example :
    r.deleteProject(1);
    // Deletes  Portfolio
    // Display Full Resume :
    r.displayResume();

    return 0;
}