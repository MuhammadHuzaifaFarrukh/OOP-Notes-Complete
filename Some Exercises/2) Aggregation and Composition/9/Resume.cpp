#include <iostream>
#include <utility>
#include <vector>
#include "Resume.h"     //Resume.h file includes all the other files so no need to include them again
using namespace std;

void Resume::addSkill(string name, int rating)
{
    skills.push_back(Skill(name, rating));
    count_skills++;
}
void Resume::addproject(string title, string description)
{
    projects.push_back(Entry(title, description));
    count_proj++;
}
void Resume::addExperience(string degree, string gpa)
{
    experiences.push_back(Experience(degree, gpa));
    count_exp++;
}
void Resume::addEducation(string title, string dur)
{
    education.push_back(Entry(title, dur));
    count_edu++;
}

void Resume::deleteProject(int ind)
{
    auto it = projects.begin();

    if (ind >= 0 && ind < projects.size())
    {
        it = projects.begin() + ind;
        projects.erase(it);
    }
    projects.shrink_to_fit();
}
void Resume::deleteEducation(int ind)
{
    auto it = education.begin();

    if (ind >= 0 && ind < education.size())
    {
        it = education.begin() + ind;
        education.erase(it);
    }
    education.shrink_to_fit();
}
void Resume::deleteSkills(int ind)
{
    auto it = skills.begin();

    if (ind >= 0 && ind < education.size())
    {
        it = skills.begin() + ind;
        skills.erase(it);
    }
    skills.shrink_to_fit();
}
void Resume::deleteExperience(int ind)
{
    auto it = experiences.begin();

    if (ind >= 0 && ind < experiences.size())
    {
        it = experiences.begin() + ind;
        experiences.erase(it);
    }
    experiences.shrink_to_fit();
}
void Resume::displayResume()
{
    cout << "--------------------------------------------------\n";
    cout << "\t\t\tResume : \n";
    cout << "--------------------------------------------------\n";
    cout << "\n";
    for (int i = 0; i < skills.size(); i++)
    {
        skills[i].show();
    }
    cout << "\n";
    for (int i = 0; i < projects.size(); i++)
    {
        projects[i].showproject();
    }
    cout << "\n";
    for (int i = 0; i < experiences.size(); i++)
    {
        experiences[i].show();
    }
    cout << "\n";
    for (int i = 0; i < education.size(); i++)
    {
        education[i].showeducation();
    }
    cout << "\n";
}
