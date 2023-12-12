#include <iostream>
using namespace std;

int main()
{

   int x = 31;
   int y = 79;
   cout<<"Values before swapping! \n";
   cout<<"x = "<< x<<"\ty = "<< y<<endl;
   x = x ^ y;
   y = y ^ x;
   x = x ^ y;
   cout<<"Values after swapping! \n";
   cout<<"x = "<< x<<"\ty = "<< y<<endl;

   return 0;
}