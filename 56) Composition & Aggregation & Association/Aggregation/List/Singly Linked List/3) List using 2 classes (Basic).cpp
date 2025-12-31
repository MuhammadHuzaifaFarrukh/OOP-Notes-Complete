#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val, Node* next = nullptr)
    {
        this -> val = val;
        this -> next = next;
    }
};
//Node class can also be nested inside LinkedList class
class LinkedList
{
    Node *start;
public:
    LinkedList()
    {
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
    LinkedList list;
    list.addNode(50);
    list.addNode(49);
    list.addNode(48);
    list.addNode(47);
    list.addNode(46);
    cout << list;
    return 0;
}


