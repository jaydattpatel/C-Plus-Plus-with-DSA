// author: jaydattpatel
//find Least Common multiple (LCM)
#include <iostream>
using namespace std;

long long gcd(long long m,long long n)
{
    if(n==0)
        return(m);
    return gcd(n, m % n);   
}

//method-1 efficient algoritham
long long lcm_naive(int a, int b)
{
    return (long long)((a / gcd(a, b)) * b);
}

//method-2 more time consume
long long lcm(int a, int b) 
{
  long long n;
  n = (long long) a * b;
  for (long i = 1; i <= n; ++i)
      if (i % a == 0 && i % b == 0)
          return i;
  return (long long) a * b;
}

int main() 
{
  int a, b;
  cout<<"Enter two values: ";
  cin >> a >> b;
  cout << "LCM_naive: "<<lcm_naive(a,b) << endl;
  cout << "LCM: "<<lcm(a,b) << endl;
  return 0;
}


