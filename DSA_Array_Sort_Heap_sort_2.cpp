// author: jaydattpatel
/*
Heap sort
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Print an array
void display(int arr[],int size)
   {
		int j=0;
		cout<<endl;
      	for(int i=0;i<size;i++)
		{
        	cout<<"["<<i<<"] " <<left<<setw(7)<<arr[i]<<"\t";
			j++;
			if(j>=4)
			{
				cout<<endl;
				j=0;
			}
		}
   }

void heapify(int arr[], int n, int i) 
    {
        // Find root_largest among root, left child and right child
        int root_largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if (left < n && arr[left] > arr[root_largest])
            root_largest = left;
    
        if (right < n && arr[right] > arr[root_largest])
            root_largest = right;
    
        // Swap and continue heapifying if root is not root_largest
        if (root_largest != i) 
            {
                swap(arr[i], arr[root_largest]);
                heapify(arr, n, root_largest);
            }
    }
  
// main function to do heap sort
void heapSort(int arr[], int n) 
  {
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    
        // Heap sort
        for (int i = n - 1; i >= 0; i--) 
            {
                swap(arr[0], arr[i]);
                heapify(arr, i, 0); // Heapify root element to get highest element at root again
            }
  }
  
int main() 
{
    int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827,  961};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\n\nUnsorted array:--------------------";
	display(arr,size);
    
    cout << "\n\nSorted array:-------------------";
    heapSort(arr, size);
    display(arr,size);
    return 0;
}