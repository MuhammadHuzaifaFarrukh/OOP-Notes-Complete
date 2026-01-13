#include <iostream>
#include <string>
#include "EventLogger.h"
using namespace std;

EventLogger::EventLogger()
{
    head = nullptr;
    size = 0;
}

void EventLogger::add_event(string val) // on right add new element
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void EventLogger::remove_oldest() // on the left , first one
{
    Node *temp = head->next;
    delete head;
    head = temp;
    size--;
}
void EventLogger::trim(int maxsize)
{
    while (size > maxsize)
    {
        remove_oldest();
    }
}
void EventLogger::print_events()
{
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        cout << temp->getmessage() << " ";
    }
    cout << " \n";
}

EventLogger::~EventLogger()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
