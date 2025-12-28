#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    srand(time(0));
    ofstream out("file.pgm");
    string magic = "P2\n", comments = "# Created by IrfanView\n" ;
    int width = 256, height =256 ;
    int maxval = 255;

    out<<magic<<comments;
    out<<width<<" "<<height<<"\n"<<maxval<<"\n";

    //Real Task here :

    int cur_val =100;
    int prev_val = 100;
    for(int i = 0 ; i<height ; i++)
    {
        cur_val = prev_val;

        for(int j = 0 ; j<width ; j++)
        {
            out<<cur_val<<" ";
            if((j+1)%32==0)
            {
                cur_val+=2;
            }
        }

        if((i+1)%32==0 )
        {
            prev_val = prev_val + ( 2*(256/32) );  //Almost Same indexing logic but a bit easier
        }
    }

    out.close();
    return 0;
}
