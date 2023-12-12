// author: jaydattpatel
/*
Quick sort:
The QuickSort algorithm is based on the strategy of divide-and-conquer where an array is split into sub-arrays around a selected pivot element from the array. 

The pivot element should be positioned so that elements less than the pivot are on its left, and elements greater than the pivot, are on its right. The resulting sub-arrays are further divided using the same approach and this process continues until each sub-array contains a single element. 

At this point, we have the sorted elements at hand, which are then combined into a sorted array.  
*/

#include <iostream>
#include <iomanip>
using namespace std;

void display(int arr[],int size)
   {
		int j=0;
		cout<<endl;
      	for(int i=0;i<size;i++)
		{
        	cout<<"["<<i<<"] " <<setw(8)<<left<<arr[i]<<"\t";
			j++;
			if(j>4)
			{
				cout<<endl;
				j=0;
			}
		}
   }

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        
        while (arr[i] <= pivot)
            i++;
        
        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);

    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low > high)
        return;
    int partitionIndex; // Index of pivot after partition
    partitionIndex = partition(arr, low, high); 
    quickSort(arr, low, partitionIndex - 1);  // sort left subarray 
    quickSort(arr, partitionIndex + 1, high); // sort right subarray
}



int main()
{
	int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827,  961};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\nUnsorted array:--------------------";
	display(arr,size);

	cout << "\nSorted array:--------------------";
	quickSort(arr,0,(size-1));
	display(arr,size);
	
    return 0;
}
