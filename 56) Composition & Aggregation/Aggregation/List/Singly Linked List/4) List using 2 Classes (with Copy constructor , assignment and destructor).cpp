#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

//You can also use this Node class Nested inside List
class Node
{
public:
    int val;
    Node *next;
    Node(int val, Node* next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};

class LinkedList
{
    Node *start;
public:
    // Constructor
    LinkedList()
    {
        start = nullptr;
    }

    // Destructor
    ~LinkedList()
    {
        clear();
    }

    // Copy Constructor
    LinkedList(const LinkedList& other)
    {
        start = nullptr;
        if (other.start != nullptr)
        {
            // Copy first node
            start = new Node(other.start->val);
            Node* current = start;
            Node* otherCurrent = other.start->next;

            // Copy remaining nodes
            while (otherCurrent != nullptr)
            {
                current->next = new Node(otherCurrent->val);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    // Copy Assignment Operator
    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)    // Protect against self-assignment
        {
            // Clear current list
            clear();

            // Copy from other list (same logic as copy constructor)
            if (other.start != nullptr)
            {
                start = new Node(other.start->val);
                Node* current = start;
                Node* otherCurrent = other.start->next;

                while (otherCurrent != nullptr)
                {
                    current->next = new Node(otherCurrent->val);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    // Helper function to clear the list
    void clear()
    {
        while (start != nullptr)
        {
            Node* temp = start;
            start = start->next;
            delete temp;
        }
        start = nullptr;
    }

    void addNode(int val)
    {
        start = new Node(val, start);
    }

    friend ostream& operator << (ostream &out, const LinkedList &list)
    {
        for (Node *temp = list.start ; temp != nullptr ; temp = temp -> next)
            out << temp -> val << ' ';
        out << '\n';
        return out;
    }
};

int main()
{
    // Test the implementation
    LinkedList list1;
    list1.addNode(50);
    list1.addNode(49);
    list1.addNode(48);
    cout << "List1: " << list1;

    // Test copy constructor
    LinkedList list2 = list1;  // Copy constructor
    cout << "List2 (copy of list1): " << list2;

    // Test copy assignment operator
    LinkedList list3;
    list3.addNode(100);
    list3.addNode(200);
    cout << "List3 before assignment: " << list3;

    list3 = list1;  // Copy assignment
    cout << "List3 after assignment: " << list3;

    // Test self-assignment
    list3 = list3;  // Should handle safely
    cout << "List3 after self-assignment: " << list3;

    // All objects will be automatically destroyed when main() ends
    // Destructors will clean up all memory - NO LEAKS!
    return 0;
}
