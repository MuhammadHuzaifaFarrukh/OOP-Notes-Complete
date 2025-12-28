#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
    ofstream out("File.pgm");
    int width = 200, height = 200;
    int maxval = 255;
    out << "P2\n";
    out << "# Created by Irfan View\n";
    out << width << " " << height << "\n";
    out << maxval << "\n";

    int file[200][200] = {0};

    srand(time(0));

    int x = rand() % width;
    int y = rand() % height;
    int prevDir = -1;
    for (int i = 0; i < 100; i++)
    {
        //int direction = rand() % 4; // 0=up, 1=down, 2=left, 3=right
        int direction;
        do
        {
            direction = rand() % 4; // 0=up, 1=down, 2=left, 3=right
        } while (direction == prevDir); // ensure new direction differs from previous
        prevDir = direction;

        int length = rand() % 30 + 10; // random length between 10–40 pixels

        for (int j = 0; j < length; j++)
        {
            if (x >= 0 && x < width && y >= 0 && y < height)
                file[y][x] = 255; // white pixel

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
            out << file[i][j] << " ";
        }
    }
    out.close();

    return 0;
}