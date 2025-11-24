#include <iostream>
using namespace std;

class University
{
private:
    string universityName;
    int establishedYear;

    // ✅ Composition: University CONTAINS Department objects
    class Department
    {
    private:
        string deptName;
        int budget;

        // Friendship for bidirectional access
        friend class University;

    public:
        Department(string name, int bg) : deptName(name), budget(bg)
        {
            cout << "Department " << deptName << " created\n";
        }

        ~Department()
        {
            cout << "Department " << deptName << " destroyed\n";
        }

        void display() const
        {
            cout << "Dept: " << deptName << ", Budget: " << budget << endl;
        }
    };

    // University composition: has multiple departments
    Department csDept;
    Department eeDept;

public:
    University(string name, int year)
        : universityName(name), establishedYear(year),
          csDept("Computer Science", 500000),
          eeDept("Electrical Engineering", 400000)
    {
        cout << "University " << universityName << " created\n";
    }

    ~University()
    {
        cout << "University " << universityName << " destroyed\n";
        // ✅ Automatic: csDept and eeDept destroyed automatically
    }

    void displayUniversity()
    {
        cout << "\n=== " << universityName << " (Est: " << establishedYear << ") ===" << endl;

        // ✅ Can access Department private members due to friendship
        cout << "CS Dept Budget: " << csDept.budget << endl;
        cout << "EE Dept Budget: " << eeDept.budget << endl;

        csDept.display();
        eeDept.display();
    }

    // Department can access University private data through methods
    void letDepartmentsAccess()
    {
        cout << "\nDepartments accessing University data:" << endl;
        // Simulating department accessing university data
        cout << "University established: " << establishedYear << endl;
    }
};

int main()
{
    cout << "=== NESTED CLASS COMPOSITION DEMO ===" << endl;

    {
        University mit("MIT", 1861);
        mit.displayUniversity();
        mit.letDepartmentsAccess();

        cout << "\nLeaving block scope..." << endl;
    } // ✅ Automatic destruction: University → Departments

    cout << "Back in main" << endl;

    return 0;
}
