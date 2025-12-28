#include <iostream>
#include <fstream>

using namespace std;


//In binary files , PGM have header P5 , PPM have header P6
//In TxT files, it is P2 and P3


// >> Operator reads till it encounters a whitespace e.g \n or  ' ' etc and skips them (doesn't consume them)
// >> Operator with consecutive int will work fine and read skipping whitespaces , fails only when it finds float , char etc other than its data type
// But when reading consecutive string with >> can cause trouble so either use getline() for these or after each >> , use the ignore operator to ignore the contents in the buffer

// Whereas the getline( ) will consume any characters and read till \n or any specified delimiter

int main()
{
    //Reading pgm bin files
    ifstream in("superman_black.ppm" , ios::binary);
    string type , comment;
    int width , height , maxval ;


    // You can use char arrays for type , comment like
    // char type[3] , comment[100] and use in.getline(type , 3) or
    //in.getline(comment , 100) which will stop input when \n occurs ,  not all 100 chars and discards \n as \0 is placed by default



    getline(in , type); //Don't use in>>type or you can use in.ignore if you use in>>type
    //Here using in>>type can be dangerous as it will not read the \n and cursor will be right before \n , then next string will be empty as getline reads till \n


    getline(in , comment); //Don't use in>>comment as it contains whitespaces
    in>>width>>height>>maxval;
    in.ignore();
    //You may use in.ignore to skip the newline after this or can even skip it , its your choice
    //Here you can use this if you want just to be safe as in>>char_data can create input problems , here it might not as we are doing with .read and .write




    //Now use a 1D array to first get all the info of the binary data
    //Then you can either use this 1D array to change the data or first store it into a 2D array , change data and then store it again into 1D array

    unsigned char *p = new unsigned char[width*height*3];
    in.read( (char *) p , width * height);
    in.close();


    //Perform Operations : (either on 1D or 2D or 3D array)
    //Use Flat array like : i*D2*D3 + j*D3 + k
    //Or Use 3 2D Flat Arrays (more work !)
    //Or Use only 1 3D array and then flat or unflatten it as its your choice


    //Now writing the data :
    ofstream out("superman_black_new.ppm",ios::binary);
    out<<type<<"\n";
    out<<comment<<"\n";
    out<<newWidth<<" "<<newHeight<<"\n";
    out<<maxval<<"\n";
    out.write( (char *)p,  3*width*height);


    delete[] p;
    out.close();

    return 0;
}
