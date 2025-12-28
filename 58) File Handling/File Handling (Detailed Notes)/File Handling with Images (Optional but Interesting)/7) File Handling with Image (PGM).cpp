#include <iostream>
#include <fstream>

using namespace std;

//File Handling for image
//Portable Gray Map (PGM File)
//Can be Opened using IrfanView Software

int main()
{
    //Read from an image pgm file
    ifstream in("practice image.pgm");
    string magic, comments;
    getline(in, magic);
    getline(in, comments);
    int height, width, maxval;
    in>>width;
    in>>height;
    in>>maxval;

    int **arr = new int*[height];
    for(int i = 0 ; i<height ; i++)
    {
        arr[i] = new int [width];
    }

    for(int i = 0 ; i<height ; i++)
    {
        for(int  j = 0 ; j<width ; j++)
        {
            in>>arr[i][j];
        }
    }

    in.close();


    //Here in between you can perform operations to make images get brighter , darker , smoother , add borders etc



    //Write to an image file
    ofstream out("new_practice_file.pgm");
    out<<"P2\n";
    out<<"# Created by IrfanView\n";
    out<<width<<" "<<height<<"\n";
    out<<"255\n";


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            out<<arr[i][j]<<" ";
        }
    }

    out.close();


    for (int i = 0; i < height; ++i)
    {
        delete[] arr[i]; // Delete each row
    }

    delete[] arr; // Delete the array of pointers (the columns)



    return 0;
}
