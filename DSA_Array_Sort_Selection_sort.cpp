// author: jaydattpatel
/*
Selection sort:
Selection sort is one of the sorting techniques that is typically used for sequencing small lists. It starts by comparing the entire list for the lowest item and moves it to the #1 position. It then compares the rest of the list for the next-lowest item and places it in the #2 position and so on until all items are in the required order. Selection sorts perform numerous comparisons, but fewer data movements than other methods.
Selection sort (A, n):
    For i = 0 to n-1 
    MIN <- i
    For j = i + 1 to n
    if (A[j] < A[i])
        MIN <- j
    End if
        Swap(A[j], A[i); // swap min to front
Return
*/
#include <iostream>
#include <iomanip>
using namespace std;

void selection_sort(int a[],int size)
{

	for(int postion=0; postion<size-1; postion++)
		{
            bool flag = false;
            int smallest = a[postion];
            int save_pos = 0;
            for(int j=postion+1; j<size; j++)
                {
                    if(a[j]<smallest)
                        {
                            save_pos = j;
                            smallest = a[j];
                            flag = true;
                        } 
                } 
            if(flag)
                swap(a[postion],a[save_pos]);
		}
}

void display(int arr[],int size)
   {
		int j=0;
		cout<<endl;
      	for(int i=0;i<size;i++)
		{
        	cout<<"["<<i<<"] "<<left<<setw(5)<<arr[i]<<"\t";
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
	selection_sort(arr,size);
	display(arr,size);
	
    return 0;
}
