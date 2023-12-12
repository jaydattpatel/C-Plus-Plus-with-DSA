/*
// author: jaydattpatel
These internal stream positions point to the locations within the stream where the next reading or writing operation is performed. These positions can be observed and modified using the following member functions:

tellg()
tellp()

These two member functions with no parameters return a value of the member type streampos, which is a type representing the current get position (in the case of tellg) or the put position (in the case of tellp).

seekg ( position );
seekp ( position );

seekg ( offset, direction );
seekp ( offset, direction );

ios::beg	offset counted from the beginning of the stream
ios::cur	offset counted from the current position
ios::end	offset counted from the end of the stream

streampos -	ios::pos_type -	Defined as fpos<mbstate_t>.
It can be converted to/from streamoff and can be added or subtracted values of these types.

streamoff -	ios::off_type -	It is an alias of one of the fundamental integral types (such as int or long long).
*/

// obtaining file size
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main () 
{
    streampos begin,end;
    ifstream myfile ("File_size_calculate_seekp_seekg.cpp", ios::binary);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);
    end = myfile.tellg();
    myfile.close();
    
    double size = end-begin;
    if(size<pow(1024,0) && size<pow(1024,1))
        cout << "size is: " << size << " bytes.\n";

    else if(size>=pow(1024,1) && size<pow(1024,2))
        cout << "size is: " << (size/pow(1024,1)) << " KB.\n";

    else if(size>=pow(1024,2) && size<pow(1024,3))
        cout << "size is: " << (size/pow(1024,2)) << " MB.\n";

    else if(size>=pow(1024,3))
        cout << "size is: " << (size/pow(1024,3)) << " GB.\n";
    return 0;
}