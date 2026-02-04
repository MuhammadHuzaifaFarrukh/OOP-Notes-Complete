#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class EventLogger
{
    Node *head;
    int size;

public:
    EventLogger();
    void add_event(string val); // on right add new element
    void remove_oldest(); // on the left , first one
    void trim(int maxsize);
    void print_events();
    ~EventLogger();
};