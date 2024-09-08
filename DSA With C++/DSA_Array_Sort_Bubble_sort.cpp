// author: jaydattpatel
/*
Bubble sort is a straightforward and simplistic method of sorting data that is used very commonly. The algorithm starts at the beginning of the data set. It compares the first two elements, and if the first is greater than the second, then it swaps them. It continues doing this for each pair of adjacent elements to the end of the data set. It then starts again with the first two elements, repeating until no swaps have occurred on the last pass. This algorithm is highly inefficient, and is rarely used except as a simplistic example.

if only one element is not in order, bubble sort will only take 2n time. If two elements are not in order, bubble sort will only take at most 3n time. Bubble sort average case and worst case are both O(n²).
*/
#include <iostream>
#include <iomanip>
using namespace std;


void bubble_sort(int a[],int size)
{
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i=0;i<size-1;i++)
			{
				if(a[i]>a[i+1])
				{
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
					flag = true;	
				}
			}
	}
}

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
   
int main()
{
	int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827,  961};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\n\nUnsorted array:--------------------";
	display(arr,size);

	cout << "\n\nSorted array:--------------------";
	bubble_sort(arr,size);
	display(arr,size);
	

    return 0;
}
