// author: jaydattpatel
/*
//find greatest common divisor (GCD) or hidhest common factor (HCF)

Euclid Algorithm GCD –  gdc(m, n)
Compute GCD (greatest common divisor) of two given positive integers.
In mathematics, the greatest common divisor (gcd), also known as the greatest common factor (gcf), of two non-zero integers, is the largest positive integer that divides the numbers without a remainder. For example,
the GCD of 8 and 12 is 4.
Algorithm GCD – Euclid (m, n)
 */
#include<iostream>
using namespace std;


//method-1 using iteration 
int gcd_1(int m,int n)
{
    int remainder;
    while(n!=0)
        {
            remainder =m % n;
            m = n;
            n = remainder;
        }
    return m;
}

//method-2 using recursive
int gcd_2(int m,int n)
{
    if(n==0)
        return(m);
    return gcd_2(n, m % n);   

}

int main()
{
    int x,y;
    cout<<"\n Enter two positive integers:\n";
    cin>>x>>y;
    cout<<"\nMethod-1 GDC(HCF) of two number ("<<x<<","<<y<<") = "<<gcd_1(x,y);
    cout<<"\nMethod-2 GDC(HCF) of two number ("<<x<<","<<y<<") = "<<gcd_2(x,y);
    return 0;
}