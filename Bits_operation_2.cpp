
#include <iostream>
using namespace std;

// Function to get the bit at the ith position
bool getBit(int num, int i)
{
    return ((num & (1 << i)));  // Return true if the bit is set. Otherwise return false
}

// Function to set the ith bit of the given number num
int setBit(int num, int i)
{
    return (num | (1 << i)); // Sets the ith bit and return the updated value
}

// Function to clear the ith bit of the given number num
int clearBit(int num, int i)
{
    int mask = ~(1 << i); // Create the mask for the ith bit unset
    return num & mask;  // Return the updated value
}

int main()
{
    int N = 70;
    cout << "The bit at the 3rd position from LSB is: "<< (getBit(N, 3) ? '1' : '0')<<endl;
    cout << "The value of the given number after setting the bit at LSB is: "<< setBit(N, 0) << endl;
    cout << "The value of the given number after clearing the bit at LSB is: "<<clearBit(N, 0) << endl;
 
    return 0;
}