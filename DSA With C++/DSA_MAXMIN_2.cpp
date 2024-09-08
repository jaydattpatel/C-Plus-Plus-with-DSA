// author: jaydattpatel
//find max and min value from array with divide and conqure
#include <iostream>
#include <vector>
using namespace std;

void MaxMin(vector<int> &arr,int start,int end,int &min,int &max)
{

    int mid;
    mid = (end + start)/2;

    if(arr[start] < min)
        min = arr[start];
    if(arr[mid] < min)
        min = arr[mid];
    if(arr[end] < min)
        min = arr[end];

    if(arr[start] > max)
        max = arr[start];
    if(arr[mid] > max)
        max = arr[mid];
    if(arr[end] > max)
        max = arr[end];

    if(start>=end)
        return;

    MaxMin(arr, start+1, mid-1, min, max);
    MaxMin(arr, mid+1, end-1, min, max);

return ;
        
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
        };
    int n = arr.size() - 1;
    int min, max;
    min = max = arr[0];
    int start = 0;
    MaxMin(arr, start, n, min, max);
    cout<<"\nMin: "<<min<<"\tMax: "<<max;
    return 0;
}
