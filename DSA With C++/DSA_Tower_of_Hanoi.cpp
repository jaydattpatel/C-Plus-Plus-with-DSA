//author: jaydatt

#include <iostream>
using namespace std;

void Tower_of_hanoi(int no_of_disk, char source, char temp, char destination)
{

    if(no_of_disk>0)
    {
        Tower_of_hanoi(no_of_disk-1,source,destination,temp);
        cout<<"\nMov Disk from "<< source<<" to "<<destination;
        Tower_of_hanoi(no_of_disk-1,temp,source,destination);
    }
}

int main()
{
    Tower_of_hanoi(4,'A','B','C');
    return 0;
}