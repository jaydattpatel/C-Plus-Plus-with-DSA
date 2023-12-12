// author: jaydattpatel
/*
Ordered Binary search data:
Binary search is one of the fastest ways to search the element in a sorted array. The idea is to look at 
the element in the middle. If the key is equal to that element, then the search is finished. If the key is less than the middle element, do a binary search on the first half. If it's greater than the middle element, do a binary search of the second half. 

The advantage of a binary search over a linear search is, amazing when you apply binary search for large numbers. For an array of a million elements, binary search, O(log N), will find the target element with a worst case of only 20 comparisons. Linear search, O(N), on average will take 500,000 comparisons to find the element. But to apply binary search on a particular array, it must be sorted first.
*/
#include <iostream>
#include <iomanip>
using namespace std;

void sortArray(int arr[],int size)
   {
      int  i = 0 ;
      while(i<(size-1))
         {
            if(arr[i] > arr[i+1])
               {
                  int temp = arr[i];
                  arr[i] = arr[i+1];
                  arr[i+1] = temp;
                  i = -1;
               }
            i++;
         };
   }

int isdataExist(int arr[],int used,int data)
   {
         for(int i=0;i<used;i++)
            if(arr[i] == data)
                  return 1;
         return 0;
   }

void getArrayData(int arr[],int size)
   {
      int data;
      for(int i=0;i<size;i++)
            do{
               arr[i] = rand()%1000;
               data = arr[i];
            } while(arr[i] == 0 || (isdataExist(arr,i,data)));
   }

void display(int arr[],int size)
   {
      int j=0;
		cout<<endl;
      for(int i=0;i<size;i++)
         {
            cout<<"["<<i<<"] "<<left<<setw(7)<<arr[i]<<"\t";
            j++;
            if(j>=4)
               {
                  cout<<endl;
                  j=0;
               }
         }  
   }

int binarySearch(int arr[],int size,int search_data)
   {
      int low=0, high=size-1,mid;
      int loop_count=0;
      
      while(low<=high)
      {
         loop_count++;
         mid = (high+low)/2; // or mid = low + (high-low)/2

         cout<<loop_count<<") low: "<<left<<setw(5)<<low
                         <<" high: "<<left<<setw(5)<<high
                         <<" mid: "<<left<<setw(5)<<mid
                         <<" arr[low] : "<<left<<setw(7)<< arr[low]
                         <<" arr[high] : "<<left<<setw(7)<< arr[high]
                         <<" arr[mid] : "<<left<<setw(7)<< arr[mid]<<endl;

         if(arr[low] == search_data)
               return (low);
            
         if(arr[high] == search_data)
               return (high);
            
         if(arr[mid] == search_data)
               return (mid);

         if(arr[mid] > search_data)
               high = mid-1;
         if(arr[mid] < search_data)
               low = mid+1;
      }
      cout<<"\nBinary Loop counts: "<<loop_count<<endl;
      return (-999999);

   }

int main( )
{
 
   int arr[15];
   int data=0, loop_count, position;
   int size = sizeof(arr)/sizeof(arr[0]);
   getArrayData(arr,size);
   sortArray(arr,size);
   display(arr,size);
   cout<<"\nEnter data to search position:";
   cin>>data;
   position = binarySearch(arr,size,data);
   if(position != -999999)
        cout<<data<<" is at position "<<position;
   else
        cout<<data<<" is not found !!! ";
   
   return 0;
}