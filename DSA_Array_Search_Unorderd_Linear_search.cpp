// author: jaydattpatel
/*
Unordered Linear search data:
Unordered linear search If the given array is not sorted while searching an element in the unordered 
list, we need to continue the search until we find the value or till the end of the array. 
This might correspond, for example, to collection exams which have not yet been sorted alphabetically. 
*/
#include <iostream>
#include <iomanip>
using namespace std;

int unordered_Linear_Search(int arr[],int size,int search_data)
   {
    
      int loop_count=0; 
      bool flag = false;
      for(int i=0; i<size; i++)
      {
        if(arr[i] == search_data)
         {
            flag = true;
            loop_count++;
            break;
         }
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
            cout<<"["<<i<<"] " <<left<<setw(7)<<arr[i]<<"\t";
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
 
   int arr[] = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464,  705, 145,  281, 827,  961};
   int data=0, loop_count, position;
   int size = sizeof(arr)/sizeof(arr[0]);
   display(arr,size);
   cout<<"\nEnter data to search position:";
   cin>>data;
   position = unordered_Linear_Search(arr,size,data);
   if(position != -999999)
        cout<<data<<" is at position "<<position;
   else
        cout<<data<<" is not found !!! ";
   
   return 0;
}