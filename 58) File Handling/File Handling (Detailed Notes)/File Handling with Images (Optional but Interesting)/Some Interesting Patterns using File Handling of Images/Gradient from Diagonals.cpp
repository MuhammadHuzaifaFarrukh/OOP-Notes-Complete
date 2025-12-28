#include <iostream>
#include <fstream>

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

    int file[200][200];

    // --- Start of Requested Two-Loop Logic ---
    // We used these separate conditions not traditional triangle condtions because now we are printing gradient 
    // Although it will work if there was a solid color but we have to print gradient so that's why we choose different conditions
    

    // Generate the Upper-Right Triangle Pattern ( Cols >= Rows or x>=y for here)
    // The intensity is based on the horizontal distance from the diagonal: (x - y).
    for (int y = 0; y < height; ++y)
    {
        for (int x = y; x < width; ++x)
        { 
            // Start x at y to cover the upper-right area
            // Distance from the diagonal: 0 on the diagonal, increasing away from it.
            int distance = x - y;
            int intensity = maxval - distance;

            // Ensure the value doesn't go below zero (clamp to 0)
            if (intensity < 0)
            {
                intensity = 0;
            }
            file[y][x] = intensity;
        }
    }

    // 3. Generate the Lower-Left Triangle Pattern (Cols < Rows or x<y or x<=y for here )
    // The intensity is based on the vertical distance from the diagonal: (y - x).
    for (int x = 0; x < width; ++x)
    {
        for (int y = x + 1; y < height; ++y) // Start from second row as first one is covered already
        { // Start y at x + 1 to cover the lower-left area
            // Distance from the diagonal: 1 near the diagonal, increasing away from it.
            int distance = y - x;
            int intensity = maxval - distance;

            // Ensure the value doesn't go below zero (clamp to 0)
            if (intensity < 0)
            {
                intensity = 0;
            }
            file[y][x] = intensity;
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