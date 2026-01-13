#pragma once
#include <string>
using namespace std;

class Node
{
    string message;

public:
    Node *next;
    Node(string m = "Unknown", Node *new_next = nullptr);
    string getmessage();
    Node *getnextnode();
};