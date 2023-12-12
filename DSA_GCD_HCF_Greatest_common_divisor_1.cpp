// author: jaydattpatel
//find greatest common divisor (GCD) or highest common factor (HCF)
#include <iostream>
using namespace std;

int gcd(int n1,int n2)
{
    // we have to work on smaller value so swapping variables n1 and n2.
    if (n2 > n1)
      swap(n1,n2);
    int d=0;
    for (int i = 1; i <=  n2; ++i) 
      {
        if (n1 % i == 0 && n2 % i ==0) 
            d = i;
      }
    return d;
}
int main() 
{
  int n1, n2, hcf;
  cout << "Enter two numbers: ";
  cin >> n1 >> n2;
  hcf = gcd(n1,n2);
  cout << "GCD or HCF = " << hcf;

  return 0;
}