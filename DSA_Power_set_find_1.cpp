/*
author: Jaydatt Patel
Find Power Set
*/

#include<iostream>
#include<math.h>
using namespace std;

bool getBit(int num, int i)
{
    return ((num & (1 << i)));  // Return true if the bit is set. Otherwise return false
}

void printSet(char *arr,int n,int value)
{
    for(int i = 0; i < n ; i++)
    {
        if(getBit(value,i))
            cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void powerSet(char *arr,int n)
{
    int count = 0;
    int totalSet = pow(2,n);
    for(int i = 0; i < totalSet; i++)
    {
        cout<<count<<":\t";
        printSet(arr,n,i);
        count++;
    }

}

int main()
{
    char arr[] = {'A','B','C','D','E'};
    int size = sizeof(arr)/sizeof(arr[0]);
    powerSet(arr,size);
    return 0;
}