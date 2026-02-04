#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

Node::Node(string m , Node *new_next) : message(m), next(new_next) {}
string Node::getmessage() { return message; }
Node* Node::getnextnode() { return next; }
