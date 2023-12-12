// author: jaydattpatel
/*
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

// reading an entire binary file
#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
    streampos size;
    char * memblock;

    ifstream file ("sample.txt", ios::in|ios::binary|ios::ate);
    if (file.is_open())
        {
            size = file.tellg();
            memblock = new char[size];
            file.seekg (0, ios::beg);
            file.read (memblock, size);
            cout<<memblock<<endl;
            file.close();
            cout << "the entire file content is in memory";
            delete[] memblock;
        }
    else 
        cout << "Unable to open file";
    return 0;
}