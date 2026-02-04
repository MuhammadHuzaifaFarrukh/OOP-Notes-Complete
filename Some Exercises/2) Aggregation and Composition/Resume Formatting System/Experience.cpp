#include <iostream>
#include <utility>
#include <vector>
#include "Experience.h"
using namespace std;

    Experience::Experience() {}
    Experience::Experience(string jt, string jd)
    {
        job.first = jt;
        job.second = jd;
    }
    void Experience::show()
    {
        cout << "Experience : " << endl;
        cout << "\tJob Title : " << job.first << endl;
        cout << "\tJob Duration : " << job.second << endl;
    }
    string Experience::getjobtitle() { return job.first; }
    string Experience::getjobdescription() { return job.second; }
