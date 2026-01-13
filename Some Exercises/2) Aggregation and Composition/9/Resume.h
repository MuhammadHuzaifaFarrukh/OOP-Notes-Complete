#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "Experience.h"
#include "Skill.h"
#include "Entry.h"
using namespace std;

class Resume
{
    vector<Skill> skills;
    vector<Entry> projects;
    vector<Experience> experiences;
    vector<Entry> education;
    int count_skills = 0;
    int count_proj = 0;
    int count_exp = 0;
    int count_edu = 0;

public: 
    void addSkill(string name, int rating);
    void addproject(string title, string description);
    void addExperience(string degree, string gpa);
    void addEducation(string title, string dur);
    void deleteProject(int ind);
    void deleteEducation(int ind);
    void deleteSkills(int ind);
    void deleteExperience(int ind);
    void displayResume();
};