#include <iostream>
#include <memory> // Required for smart pointers

class Node
{
public:
    int val;
    std::unique_ptr<Node> next; // The node "owns" the next one

    Node(int v = 0) : val(v), next(nullptr) {}
};

class List
{
    std::unique_ptr<Node> head;
    Node* tail; // Raw pointer for tail is OK because it doesn't "own" the memory
public:
    int size = 0;

    List() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(int val)
    {
        auto newNode = std::make_unique<Node>(val);

        if (!head)
        {
            head = std::move(newNode);
            tail = head.get(); // .get() returns the raw pointer address
        }
        else
        {
            newNode->next = std::move(head); // Transfer ownership of old head to newNode
            head = std::move(newNode);       // Transfer ownership of newNode to head
        }
        size++;
    }

    void pop_front()
    {
        if (!head) return;

        // Simply moving head to head->next automatically deletes the old head
        head = std::move(head->next);

        if (!head) tail = nullptr;
        size--;
    }

    // No Destructor needed!
    // When the List object goes out of scope, 'head' is destroyed.
    // Because it's a unique_ptr, it destroys its Node.
    // That Node destroys its 'next' unique_ptr, and so on (recursive cleanup).
};

int main()
{
    List l1;
    l1.push_front(5);
    l1.push_front(10);
    l1.push_front(15);

    return 0;
}

//Why tail is still a raw pointer Node * type :

//A std::unique_ptr represents exclusive ownership.
//In a linked list, Node A's next pointer owns Node B.
//If you also make the List's tail pointer a unique_ptr, you are telling the computer that the tail also owns Node B.
//C++ will not allow this. You cannot have two unique_ptrs pointing to the same memory. If you try to use std::shared_ptr
//for both, it would "work," but it is inefficient and creates a risk of circular references (memory leaks).
