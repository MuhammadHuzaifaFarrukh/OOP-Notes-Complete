#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
    ofstream out("File.ppm");
    int width = 200, height = 200;
    int maxval = 255;
    out << "P3\n";
    out << "# Created by Irfan View\n";
    out << width << " " << height << "\n";
    out << maxval << "\n";

    int pixels[200][200][3];

    srand(time(0));
    for(int j = 0; j<200 ; j++)
    {
        int row = 0 ;
        int col = j;

        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;

        //First fill the right side of the diagonals
        while(row <200 && col <200)
        {
            pixels[row][col][0] = red;
            pixels[row][col][1] = green;
            pixels[row][col][2] = blue;
            row++;
            col++;
        }
    }

    for(int i = 0; i<200 ; i++)
    {
        //Now fill the Left side of the diagonals

        int row = i ;
        int col = 0;
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;
        while(row <200 && col <200)
        {
            pixels[row][col][0] = red;
            pixels[row][col][1] = green;
            pixels[row][col][2] = blue;
            row++;
            col++;
        }
    }


    for(int i = 0 ; i<height ; i++)
    {
        for(int j  = 0 ; j<width ; j++)
        {
            out<<pixels[i][j][0]<<" "<<pixels[i][j][1]<<" "<<pixels[i][j][2]<<" ";
        }
    }

    out.close();

    return 0;
}
