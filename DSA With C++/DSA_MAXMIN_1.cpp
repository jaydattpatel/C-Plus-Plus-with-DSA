// author: jaydattpatel
//find max and min value from array 
#include <iostream>
#include <vector>
using namespace std;

void MaxMin(vector<int>& arr, int start, int end)
    {
        int min,max;
        int size = arr.size();
        min = max = arr[0]; 
        for(int i =start; i <= end ;i++)
            {
                if(arr[i] < min) 
                    {min = arr[i];} 
                if(arr[i] > max)
                    {max = arr[i];} 
            }
        cout<<"\nMin: "<<min<<"\tMax: "<<max;
    }


int main() 
{
    cout<<"Array[]: ";
    vector<int> arr(10);
    for(int &i : arr)
        {
            do
                i = (rand()%100);
            while(i == 0);
            cout<<i<<" ";
        }
    int size = arr.size() - 1;
    MaxMin(arr,0,size);
    
    return 0;
}
