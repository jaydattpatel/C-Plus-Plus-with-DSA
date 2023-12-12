// author: jaydattpatel
#include <iostream>
using namespace std;

int main() 
{
   int len;
   int arr[5] = {8, 8, 1, 3, 6};

   //method-1
   len = *(&arr + 1) - arr;  // int len = (&arr)[1] - arr;
   cout << "The length of the array is: " << len<<endl;

   //method-2
   len = (&arr)[1] - arr;  // int len = (&arr)[1] - arr;
   cout << "The length of the array is: " << len<<endl;

   //method-3
   len = (&arr)[1] - (&arr)[0];  // int len = (&arr)[1] - arr;
   cout << "The length of the array is: " << len<<endl;

   return 0;
}