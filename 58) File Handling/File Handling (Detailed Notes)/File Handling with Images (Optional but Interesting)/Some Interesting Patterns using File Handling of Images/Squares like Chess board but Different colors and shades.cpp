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

    //By Checker Board method :

    int square_size = 32; // Set the size of the squares (e.g., 16x16 pixels)

    int startRow = 0, endRow = height;
    int startCol = 0, endCol =  width ;
    int val = 100; //Base
    int inc_shade = 2 ; //Shade increase by each block

    for (int i = startRow ; i < endRow ; i++)
    {
        for(int j = startCol ; j < endCol ; j++)
        {

            // Calculate the "block coordinates"
            int block_i = i / square_size; // block_i -> 0 to 7
            int block_j = j / square_size; // block_j -> 0 to 7

            int block_index = (block_i * (256/32) ) + block_j; // Like (i*col + j)


            int shade_value = val + (inc_shade*block_index);
            if(shade_value>maxval)
            {
                shade_value = maxval; // Incase the shade goes out of range (i.e greater than 255)
            }
            out<<shade_value<<" ";
        }
    }

    out.close();
    return 0;
}
