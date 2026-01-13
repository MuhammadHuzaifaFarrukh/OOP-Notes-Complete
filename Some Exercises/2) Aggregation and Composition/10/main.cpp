#include <iostream>
#include <string>
#include "EventLogger.h"
#include "Node.h"
#include "EventLogger.cpp"
#include "Node.cpp"
using namespace std;
int main()
{
    //N is max size of logger
    //Q is number of operations
    int N, Q;
    cout << "Enter 2 Numbers : ";
    cin >> N >> Q;
    EventLogger logger;
    for (int i = 0; i < Q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string msg;
            cin >> ws; // Consume whitespace
            getline(cin, msg);
            logger.add_event(msg);
            logger.print_events();
        }
        else if (op == 2)
        {
            logger.trim(N);
            logger.print_events();
        }
    }
    cout << "Final Event Log : " << endl;
    logger.print_events();
}