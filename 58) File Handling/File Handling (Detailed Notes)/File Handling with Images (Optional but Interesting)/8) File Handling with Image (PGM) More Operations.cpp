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

    //1) Make image brighter :
    /*
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            arr[i][j] = min(255, arr[i][j] + 50);
        }
    }
    */

    //2) // Making Image More Bright
    /*
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            arr[i][j]= min(255 , arr[i][j]+128) ;
        }
    }
    */


    //3) Make image Darker :
    /*
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            arr[i][j] = max(0, arr[i][j] - 50);
        }
    }
    */


    //4) Smooth Image :
    /*
    for(i = 1 ; i < height – 1 ; i++)
    {

        for(j = 1; j < width – 1 ; j++)
        {
            sum = 0;
            for(di = -1 ; i <= 1 ; di++)
            {
                for(dj = -1 ; dj < 1 ; dj++)
                {
                    sum += arr[i + di][j + dj];
                }
            }
            arr[i][j] = sum/9;
        }
    }
    */

    //5) Add Border to Image :
    //Makes first and last column , top and bottom row to zero value
    /*
    for(i = 1 ; i < height – 1 ; i++)
    {
        arr[i][0] = arr[i][width-1] = 0;
        for (j = 0 ; j < width ; j++)
        {
            arr[0][j] = arr[height - 1][j] = 0;
        }
    }
    */

    //6) Add Border to Image but with specific thickness :
    /*
    int thickness = 5; // <-- Set your desired border thickness here (T)
    int border_value = 0; // <-- Set the desired border color (e.g., 0 for black)

    // 1. Zeroing the Left and Right Borders (Columns)
    // We loop through the rows, but only for the inner part (i >= thickness and i < height - thickness)
    // We need to cover the entire height, otherwise the top/bottom loops below will skip the corners.

    // Loop through all rows to set the side borders
    for(int i = 0 ; i < height ; i++)
    {
        // Set the left border (from column 0 up to thickness - 1)
        for(int j = 0; j < thickness; j++)
        {
            arr[i][j] = border_value;
        }

        // Set the right border (from column width - thickness up to width - 1)
        for(int j = width - thickness; j < width; j++)
        {
            arr[i][j] = border_value;
        }
    }

    // 2. Zeroing the Top and Bottom Borders (Rows)
    // This loop ensures the corners and the top/bottom edges are set correctly,
    // even if the side loops already covered them (it's safe to overwrite the corners).

    // Loop through the first 'thickness' rows (top border) and the last 'thickness' rows (bottom border)
    for (int i = 0 ; i < thickness ; i++)
    {
        // Set the entire top row
        for(int j = 0 ; j < width ; j++)
        {
            arr[i][j] = border_value;
        }

        // Set the entire bottom row (arr[height - 1 - 0], arr[height - 1 - 1], etc.)
        for(int j = 0 ; j < width ; j++)
        {
            arr[height - 1 - i][j] = border_value;
        }
    }
    */



    //7) Insert black & white squares in middle
    //The Pattern here is iterating between even and odd values like 1 box black , other white of size 1 x 1
    //The Pattern here won't be much clear if the pixels are too much like 500 or even more
    //Because the pixels of black and white are set of 1 x 1 size here so they are so small for larger pixels and can't be viewed clearly with our eyes
    //It will create an optical illusion for us and we may see an image of (0+255)/2 = 127.5 Valued Color

    /*
    int startRow = height/4, endRow = 3 * height / 4;
    int startCol = width / 4, endCol = 3 * width / 4;
    for (int i = startRow ; i < endRow ; i++)
    {
        for(int j = startCol ; j < endCol ; j++)
        {
            if (((i+j)%2) == 0)
            {
                arr[i][j]=0;
            }
            else
            {
                arr[i][j]=255;
            }
        }
    }
    */

    //8) Black & White Squares in middle but clearer now as square size is set now
    /*
    int square_size = 16; // Set the size of the squares (e.g., 16x16 pixels)

    int startRow = height/4, endRow = 3 * height / 4;
    int startCol = width / 4, endCol = 3 * width / 4;
    for (int i = startRow ; i < endRow ; i++)
    {
        for(int j = startCol ; j < endCol ; j++)
        {

            // Calculate the "block coordinates"
            int block_i = i / square_size;
            int block_j = j / square_size;

            // Check the parity of the block coordinates
            if (((block_i + block_j) % 2) == 0)
            {
                arr[i][j] = 0;   // Black block
            }
            else
            {
                arr[i][j] = 255; // White block
            }
        }
    }
    */

    //9) Add a 100 by 100 white box in the exact middle :
    /*
    for (i = height/2-50 ; i < height/2 + 50 ; i++)
        for (j = width/2-50 ; j < width/2 + 50 ; j++)
            pixels[i * width + j] = 255;
    */

    //10 : Place a white box in the center of the image
    /*
    int startRow = height / 4;
    int endRow = (3 * height) / 4;
    int startCol = width / 4;
    int endCol = (3 * width) / 4;

    for (int row = startRow-50; row < endRow+50; row++)
    {
        for (int col = startCol-50; col < endCol+50; col++)
        {
            arr[row * width + col] = 255;  // White pixel
        }
    }
    */


    //11) Invert Colors in a PGM File :
    /*
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            arr[i][j]= 255 - arr[i][j] ;
        }
    }
    */



    //12) Practice File Question to display central pixels based on even/odd values of dimensions
    // --- 2. Determine Central Coordinates ---

    // Core logic for center calculation using integer division (floor)
    /*
    int center_row_1 = (height - 1) / 2;
    int center_row_2 = height / 2;
    int center_col_1 = (width - 1) / 2;
    int center_col_2 = width / 2;

    // --- 3. Conditional Display Logic ---

    // A. Both Odd (e.g., 5x5 image -> center at 2,2)
    if (height % 2 != 0 && width % 2 != 0)
    {

        cout << "Case: Both dimensions are ODD (Single central pixel)." << endl;

        // Target index: The single pixel at [center_row_2, center_col_2]
        // center_row_1 and center_row_2 will be the same here (e.g., (5-1)/2=2, 5/2=2)
        long long index = (long long)center_row_2 * width + center_col_2;

        // Read and discard pixels until the target index
        int value;
        for (long long k = 0; k <= index; ++k)
        {
            if (!(in >> value))
            {
                cerr << "Error reading data." << endl;
                return;
            }
        }

        cout << "Central Pixel (" << center_row_2 << ", " << center_col_2 << "): " << value << endl;
    }

    // B. One Dimension Even (e.g., 6x5 image)
    else if (height % 2 != 0 || width % 2 != 0)
    {

        cout << "Case: One dimension is EVEN (Central two pixels)." << endl;

        // The two center pixels will be adjacent along the even dimension.
        // We will display two pixels: [R1, C1] and [R2, C2]
        int R1, C1, R2, C2;

        // If width is even (e.g., 6x5): Pixels are side-by-side at the single center row.
        if (width % 2 == 0)
        {
            R1 = R2 = center_row_2; // Single center row
            C1 = center_col_1;      // Col 2 (the left one)
            C2 = center_col_2;      // Col 3 (the right one)
        }
        // If height is even (e.g., 5x6): Pixels are one above the other at the single center column.
        else
        {
            C1 = C2 = center_col_2; // Single center col
            R1 = center_row_1;      // Row 2 (the top one)
            R2 = center_row_2;      // Row 3 (the bottom one)
        }

        // Calculate the index of the first pixel
        long long index1 = (long long)R1 * width + C1;
        long long index2 = (long long)R2 * width + C2;

        // Read to the first target index (index1 is always the smaller one)
        int value;
        for (long long k = 0; k <= index1; ++k)
        {
            if (!(in >> value))
            {
                cerr << "Error reading data." << endl;
                return;
            }
        }
        cout << "Central Pixel 1 (" << R1 << ", " << C1 << "): " << value << endl;

        // Read to the second target index (may be the next pixel or a jump)
        if (index2 > index1)
        {
            // Read and discard pixels between index1 and index2-1
            for (long long k = index1 + 1; k < index2; ++k)
            {
                if (!(in >> value))
                {
                    cerr << "Error reading data." << endl;
                    return;
                }
            }
            // Read the second target pixel
            if (!(in >> value))
            {
                cerr << "Error reading data." << endl;
                return;
            }
            cout << "Central Pixel 2 (" << R2 << ", " << C2 << "): " << value << endl;
        }
        // If the two pixels are adjacent (index2 == index1 + 1), 'value' already holds the second pixel.
        else
        {
            cerr << "Error in index logic." << endl;
            return;
        }
    }

    // C. Both Even (e.g., 6x6 image -> 2x2 central block)
    else   // height % 2 == 0 && width % 2 == 0
    {

        cout << "Case: Both dimensions are EVEN (Central four pixels)." << endl;

        // The 4 pixels form a 2x2 square:
        // [center_row_1, center_col_1]   [center_row_1, center_col_2]
        // [center_row_2, center_col_1]   [center_row_2, center_col_2]

        // Pixel 1: Top-Left
        long long index1 = (long long)center_row_1 * width + center_col_1;
        // Pixel 2: Top-Right (index1 + 1)
        long long index2 = index1 + 1;
        // Pixel 3: Bottom-Left (index1 + width)
        long long index3 = index1 + width;
        // Pixel 4: Bottom-Right (index1 + width + 1)
        long long index4 = index3 + 1;

        // Read up to the first pixel
        int value;
        for (long long k = 0; k <= index1; ++k)
        {
            if (!(in >> value))
            {
                cerr << "Error reading data." << endl;
                return;
            }
        }
        cout << "Central Pixel 1 (" << center_row_1 << ", " << center_col_1 << "): " << value << endl;

        // Read Pixel 2 (Adjacent)
        if (!(in >> value))
        {
            cerr << "Error reading data." << endl;
            return;
        }
        cout << "Central Pixel 2 (" << center_row_1 << ", " << center_col_2 << "): " << value << endl;

        // Read and discard pixels between Pixel 2 and Pixel 3 (end of row 1, start of row 2)
        // We need to jump (width - 2) pixels
        for (int k = 0; k < width - 2; ++k)
        {
            if (!(in >> value))
            {
                cerr << "Error reading data." << endl;
                return;
            }
        }

        // Read Pixel 3 (Bottom-Left)
        if (!(in >> value))
        {
            cerr << "Error reading data." << endl;
            return;
        }
        cout << "Central Pixel 3 (" << center_row_2 << ", " << center_col_1 << "): " << value << endl;

        // Read Pixel 4 (Bottom-Right, Adjacent)
        if (!(in >> value))
        {
            cerr << "Error reading data." << endl;
            return;
        }
        cout << "Central Pixel 4 (" << center_row_2 << ", " << center_col_2 << "): " << value << endl;
    }
    */

    //13) Rotate by 90,180,270 degrees
    //14) Take transpose of the image

    //15) Adding the Same image on the original but 2nd one is rotated by 180 degrees
    //16) Appending a Horizontal Flipped image to the right
    //17) Merging all 4 images (Top-left : original , Top-right : horizontal flip , Bottom-left : vertical flip , Bottom-right : vertical & horizontal flip)


    //18) Adding some white / black lines in any image PGM

    /*
    int num_h_lines = 8; // Example: 8 horizontal lines
    int line_thickness = 2;
    int white = 255;

    for (int n = 0; n < num_h_lines; n++)
    {

        // a. Choose a random starting row index (i)
        // We choose a starting row that allows for the line_thickness without going out of bounds
        int random_row = rand() % (height - line_thickness);

        // b. Draw the line (set pixels in the row(s) to white)
        // The outer loop handles the thickness
        for (int t = 0; t < line_thickness; t++)
        {
            int current_row = random_row + t;

            // The inner loop sets every column (j) in that row to white
            for (int j = 0; j < width; j++)
            {
                arr[current_row][j] = white;
            }
        }
    }



    int num_v_lines = 8; // Example: 8 vertical lines

    for (int n = 0; n < num_v_lines; n++)
    {

        // a. Choose a random starting column index (j)
        int random_col = rand() % (width - line_thickness);

        // b. Draw the line (set pixels in the column(s) to white)
        // The outer loop handles the thickness
        for (int t = 0; t < line_thickness; t++)
        {
            int current_col = random_col + t;

            // The inner loop sets every row (i) in that column to white
            for (int i = 0; i < height; i++)
            {
                arr[i][current_col] = white;
            }
        }
    }
    */


    //19) Resizing an image (Stretch / Compress) :
    //Formula to map new coordinates :
    // x(new) = orignal_width/new_width
    // y(new) = orignal_height/new_height

    /*
    // 1. Define source data (pretend you read this from the file)
    int original_W = 256;
    int original_H = 256;
    // Load original_image_data[256][256] from file...

    // 2. Define target size
    int new_W = 128; // Example: compress by half
    int new_H = 128;

    // 3. Create the new image array
    int new_image_data[new_H][new_W];

    // 4. Resample: Iterate through every pixel in the NEW image
    for (int y_new = 0; y_new < new_H; y_new++)
    {
        for (int x_new = 0; x_new < new_W; x_new++)
        {

            // Calculate the fractional coordinate in the original image
            double x_old_float = (double)x_new * ( (double)original_W / new_W );
            double y_old_float = (double)y_new * ( (double)original_H / new_H );

            // Use Nearest Neighbor (rounding to the nearest whole pixel)
            int x_old_int = (int)round(x_old_float);
            int y_old_int = (int)round(y_old_float);

            // Ensure coordinates don't go out of bounds (max index is Width/Height - 1)
            if (x_old_int >= original_W) x_old_int = original_W - 1;
            if (y_old_int >= original_H) y_old_int = original_H - 1;

            // Assign the value
            new_image_data[y_new][x_new] = original_image_data[y_old_int][x_old_int];
        }
    }

    // 5. Write the new_image_data along with the new_W and new_H to a new PGM file.
    */
    //You can use above method for doing the program to add more columns / rows e.g first use this program to stretch an image by 5 rows and 5 columns (all 4 sides) , then apply the borders of thickness 5 (all 4 sides) , this will increase the rows and columns by 10 from all sides by adding borders on the stretched parts



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
