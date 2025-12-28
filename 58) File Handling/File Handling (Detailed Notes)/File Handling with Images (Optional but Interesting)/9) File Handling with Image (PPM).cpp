#include <iostream>
#include <fstream>

using namespace std;

//File Handling for image
//Portable Pix Map (PPM File)
//Can be Opened using IrfanView Software

int main()
{
    //Read from an image PPM file
    ifstream in("black goku aka zamasu(2).ppm");
    string magic, comments;
    getline(in, magic);
    getline(in, comments);
    int height, width, maxval;
    in>>width;
    in>>height;
    in>>maxval;

    int **red = new int*[height];
    for(int i = 0 ; i<height ; i++)
    {
        red[i] = new int [width];
    }
    int **blue = new int*[height];
    for(int i = 0 ; i<height ; i++)
    {
        blue[i] = new int [width];
    }
    int **green = new int*[height];
    for(int i = 0 ; i<height ; i++)
    {
        green[i] = new int [width];
    }


    for(int i = 0 ; i<height ; i++)
    {
        for(int  j = 0 ; j<width ; j++)
        {
            in>>red[i][j]>>green[i][j]>>blue[i][j];
        }
    }

    in.close();


    //Here in between you can perform operations to make images get brighter , darker , smoother , add borders etc



    //Write to an image file (PPM)
    ofstream out("new_black goku aka zamasu(2).pgm");
    out<<"P3\n";
    out<<"# Created by IrfanView\n";
    out<<width<<" "<<height<<"\n";
    out<<"255\n";


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            out<<red[i][j]<<" "<<green[i][j]<<" "<<blue[i][j]<<" ";
        }
    }

    out.close();


    for (int i = 0; i < height; ++i)
    {
        delete[] red[i]; // Delete each row
        delete[] blue[i];
        delete[] green[i];
    }

    delete[] red; // Delete the array of pointers (the columns)
    delete[] green; // Delete the array of pointers (the columns)
    delete[] blue; // Delete the array of pointers (the columns)



    return 0;
}
