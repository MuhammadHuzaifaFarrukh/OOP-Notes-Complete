#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
};

int main() {
    // Stack-allocated nodes (auto-cleaned)
    Node a, b, c, d;
    a.val = 12;
    b.val = 15;
    c.val = 18;
    d.val = 25;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    cout << a.val << ' ' << a.next->val << ' '
         << a.next->next->val << ' ' << a.next->next->next->val << '\n';
    
    // Heap-allocated node (needs manual deletion)
    b.next = new Node;    // This creates memory leak if not deleted!
    b.next->val = 16;
    b.next->next = &c;
    
    cout << a.val << ' ' << a.next->val << ' '
         << a.next->next->val << ' ' << a.next->next->next->val << ' ' 
         << a.next->next->next->next->val << '\n';
    
    // MEMORY DEALLOCATION for heap-allocated node
    // We need to carefully remove the heap node without breaking the stack nodes
    Node* heapNode = b.next;  // Save pointer to heap node
    b.next = &c;              // Reconnect b directly to c (bypassing heap node)
    delete heapNode;          // Now safely delete the heap node
    
    // Stack nodes a, b, c, d will be automatically destroyed when main() ends
    
    return 0;
}