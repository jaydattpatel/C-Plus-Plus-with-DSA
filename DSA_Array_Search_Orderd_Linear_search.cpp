// author: jaydattpatel
/*
Ordered Linear search data:
The given array is sorted. In this case, we need not necessarily search through the entire list to find a particular object or determine that it does not exist in the collection.

In ordered Linear search, We have to compare search data with every element of array which are less then or equal to data search. Firstl, we will compare search data of first elememt of array using for or while loop, if not match then check if current compating array element is greater than search data, then terminate loop  
*/
#include <iostream>
#include <iomanip>
using namespace std;

int ordered_Linear_Search(int arr[],int size,int search_data)
   {
    
      int loop_count=0; 
      bool flag = false;
      for(int i=0; i<size; i++)
      {
         if(arr[i] == search_data)
            {
               flag = true;
               break;
            }
         else if(arr[i] > search_data)
            {
               flag = false;
               break;
            };
        loop_count++; 
      }
      cout<<"\nLoop counts: "<<loop_count<<endl;
      if(flag)
         return (loop_count); 
      else 
         return (-999999);
   }

void display(int arr[],int size)
   {
      int j=0;
		cout<<endl;
      for(int i=0;i<size;i++)
         {
            cout<<"["<<i<<"] " <<left<<setw(7)<<arr[i]<<"\t\t";
            j++;
            if(j>=4)
               {
                  cout<<endl;
                  j=0;
               }
         }  
   }

int main( )
{
 
   int arr[] = {41, 145, 169, 281, 334, 358, 464, 467, 478, 500, 705, 724, 827, 961, 962};
   int data=0, loop_count, position;
   int size = sizeof(arr)/sizeof(arr[0]);
   display(arr,size);
   cout<<"\nEnter data to search position:";
   cin>>data;
   position = ordered_Linear_Search(arr,size,data);
   if(position != -999999)
        cout<<data<<" is at position "<<position;
   else
        cout<<data<<" is not found !!! ";
   
   return 0;
}