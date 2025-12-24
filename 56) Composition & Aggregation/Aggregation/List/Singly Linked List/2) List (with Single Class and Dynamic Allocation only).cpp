#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    // Create initial list: 1 → 2 → 3
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next = b;
    b->next = c;
    
    Node* head = a;  // Track the head
    
    // Insert new node at left (beginning)
    Node* newNode = new Node(0);
    newNode->next = head;
    head = newNode;
    
    // Now list is: 0 → 1 → 2 → 3 → null
    
    // Print to verify
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " → ";
        current = current->next;
    }
    cout << "null" << endl;
    
    // MEMORY DEALLOCATION - IMPORTANT!
    current = head;
    while (current != nullptr) {
        Node* temp = current;      // Save current node
        current = current->next;   // Move to next node
        delete temp;               // Delete saved node
    }
    head = nullptr;  // Good practice
    
    return 0;
}