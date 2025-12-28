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

    int red[200][200] = {0};
    int blue[200][200] = {0};
    int green[200][200] = {0};
    

    srand(time(0));

    int x = rand() % width;
    int y = rand() % height;
    int prevDir = -1;
    for (int i = 0; i < 100; i++)
    {
        //int direction = rand() % 4;    // 0=up, 1=down, 2=left, 3=right
        int direction;
        do 
        {
            direction = rand() % 4; // 0=up, 1=down, 2=left, 3=right
        } while (direction == prevDir); // ensure new direction differs from previous
        prevDir = direction;

        int length = rand() % 30 + 10; // random length between 10–40 pixels

        int r = rand() % 256;    
        int g = rand() % 256;
        int b = rand() % 256;

        for (int j = 0; j < length; j++)
        {
            if (x >= 0 && x < width && y >= 0 && y < height)
                red[y][x] = r;
                green[y][x] = g;
                blue[y][x] = b;

            // Move in direction
            switch (direction)
            {
            case 0:
                y--;
                break; // up
            case 1:
                y++;
                break; // down
            case 2:
                x--;
                break; // left
            case 3:
                x++;
                break; // right
            }

            // Keep inside bounds
            if (x < 0)
                x = 0;
            if (x >= width)
                x = width - 1;
            if (y < 0)
                y = 0;
            if (y >= height)
                y = height - 1;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            out << red[i][j]<< " "<<green[i][j]<< " " <<blue[i][j]<<" ";
        }
    }
    out.close();

    return 0;
}