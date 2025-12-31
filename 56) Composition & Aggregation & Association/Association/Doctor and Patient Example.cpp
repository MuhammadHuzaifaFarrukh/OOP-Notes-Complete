#include <iostream>
#include <string>

using namespace std;

// Forward declaration so Doctor knows Patient exists
class Patient;

// ================= ASSOCIATION ================
// The "Inner" class (Associated Class)
class Patient
{
private:
    string m_name;
    int m_healthID;

    // Granting friendship so Doctor can access private data
    friend class Doctor;

public:
    Patient(string name, int id) : m_name(name), m_healthID(id)
    {
        cout << "Patient " << m_name << " created.\n";
    }

    void display()
    {
        cout << "Patient Name: " << m_name << " (ID: " << m_healthID << ")\n";
    }
};

// The "Outer" class
//Doctor uses / knows Patient(s)
class Doctor
{
private:
    string m_drName;
    //may use ID as well for the doctor , here we don't

public:
    Doctor(string name) : m_drName(name) {}

    // ASSOCIATION: The object is passed as a parameter
    // The Doctor "Uses" the Patient to perform a task.
    void writePrescription(Patient &p, string medicine)
    {
        // Accessing private m_name because Doctor is a 'friend'
        cout << "Dr. " << m_drName << " is prescribing " << medicine
                  << " for patient: " << p.m_name << "\n";
    }

    void performCheckup(Patient *p)
    {
        //Check for nullptr
        if (p)
        {
            cout << "Dr. " << m_drName << " is checking ID: " << p->m_healthID << "\n";
        }
    }
};

int main()
{
    // 1. Objects are created independently (Unbounded Lifetimes)
    Doctor myDoc("Smith");
    Patient myPatient("John Doe", 101);

    cout << "--- Association Start ---\n";

    // 2. Invoking the function using the associated object
    myDoc.writePrescription(myPatient, "Amoxicillin"); // Passed by reference
    myDoc.performCheckup(&myPatient);                // Passed by pointer

    cout << "--- Association End ---\n";

    // 3. When scope ends, objects are destroyed independently.
    // If 'myDoc' is destroyed, 'John Doe' still exists in this scope.
    return 0;
}
