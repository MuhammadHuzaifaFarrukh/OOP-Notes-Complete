#include <chrono>
#include <iostream>
#include "Rectangle.h"
#include "Rectangle.cpp"


using namespace std;


int main()
{
    Rect player(0,0,50,50), enemy(60,0,50,50);
    if(player & enemy)
    {
        cout<<"Collision"<<endl;
    }
    player.move(20,0);
    player.display();

    player.scale(1.5,1.5);
    player.display();

    if(player>=enemy)
    {
        cout<<"Player is right or overlapping the enemy "<<endl;
    }

    Rect clone = player;
    if(clone == player)
    {
        cout<<"Same Rectangle "<<endl;
    }

    return 0;
}
