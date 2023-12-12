// author: jaydattpatel
/*
Merge sort :
Divide-and conquer is a general algorithm design paradigm: 
Divide: divide the input data S in two disjoint subsets S1and S2
Recur: solve the sub problems associated with S1 and S2
Conquer: combine the solutions for S1 and S2 into a solution for S

The base case for the recursion is sub problems of size 0 or 1
Merge-sort on an input sequence S with n elements consists of three steps: 
Divide: partition S into two sequences S1 and S2 of about n/2 elements each Recurrecursively sort S1 and S2 
Conquer: merge S1 and S2 into a unique sorted sequence. 
Merge sort algorithm proceeds as follows: 
1) Divide the array with the size of m as middle= m/2.
2) Update left from 1 to middle.
3) Update right from middle+1 to m
4) Repeat 1 to 3 until m≤1
5) Call merge [left, right].
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..end]
void merge(int arr[],int low,int mid,int high)
{

    int temp_arr[high-low+1];

    int left_low = low, left_high = mid;
    int right_low = mid + 1, right_high = high;

    int l_index = low, r_index =mid+1 , temp_index=0;
    
    while(l_index <= left_high && r_index <= right_high)
        {
            if(arr[l_index] < arr[r_index])
                temp_arr[temp_index++] = arr[l_index++];
            else
                temp_arr[temp_index++] = arr[r_index++];
        }

    while(l_index <= left_high)
        temp_arr[temp_index++] = arr[l_index++];
    
    while(r_index <= right_high)
        temp_arr[temp_index++] = arr[r_index++];

    for(int i = low, j = 0; i <= high; i++, j++)
        arr[i]  = temp_arr[j];

}

void mergeSort(int arr[],const int low,const int high)
{
    if(low >= high)
        return;
    int mid = low + ((high - low)/2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void display(int arr[],int size)
   {
		int j=0;
		cout<<endl;
      	for(int i=0;i<size;i++)
		{
        	cout<<"["<<i<<"] " <<setw(8)<<left<<arr[i]<<"\t";
			j++;
			if(j>=4)
			{
				cout<<endl;
				j=0;
			}
		}
   }

int main()
{
	int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827,  961};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\nUnsorted array:--------------------";
	display(arr,size);

	cout << "\nSorted array:--------------------";
	mergeSort(arr,0,(size-1));
	display(arr,size);
	
    return 0;
}
