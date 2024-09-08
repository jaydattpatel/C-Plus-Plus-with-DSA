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

void heapify(int arr[], int n) 
    {
            int max = (int)((n/2)-1);
            for(int i = max; i >= 0 ; i--)
                {
                    int root = i;
                    int left = (i*2)+1;
                    int right = (i*2)+2;

                    if(left < n && arr[root] < arr[left])
                        swap(arr[root] , arr[left]);
    
                    if(right < n && arr[root] < arr[right])
                            swap(arr[root] , arr[right]);
                }
    }
  
// main function to do heap sort
void heapSort(int arr[], int n) 
  {
        // Build max heap
        heapify(arr, n);
    
        // Heap sort
        for (int i = n - 1; i >= 0; i--) 
            {
                swap(arr[0], arr[i]);
                heapify(arr, i); // Heapify root element to get highest element at root again
            }
  }
  
int main() 
{
    int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827, 961};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\n\nUnsorted array:--------------------";
	display(arr,size);
    
    cout << "\n\nSorted array:-------------------";
    heapSort(arr, size);
    display(arr,size);
    return 0;
}