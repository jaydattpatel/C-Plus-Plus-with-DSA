// fibonacii term with modulo
// author: jaydattpatel
/*
Given two number N and M. The task is to find the N-th fibonacci number mod M.
In general let FN be the N-th fibonacci number then the output should be FN % M.

However, for such values of N, a simple recursive approach to keep calculating N Fibonacci numbers with a time complexity of O(2N) should be avoided. Even an iterative or a Dynamic Programming approach with an algorithm looping for N iterations will not be time-efficient.
This problem can be solved using the properties of Pisano Period. 
For a given value of N and M >= 2, the series generated with Fi modulo M (for i in range(N)) is periodic. 
The period always starts with 01. The Pisano Period is defined as the length of the period of this series.

To understand it further, let’s see what happens when M is small:
i	        0	1	2	3	4	5	6	7	8	9	10	11
Fi	        0	1	1	2	3	5	8	13	21	34	55	89
Fi mod 2	0	1	1	0	1	1	0	1	1	0	1	1
Fi mod 3	0	1	1	2	0	2	2	1	0	1	1	2

For M = 2, the period is 011 and has length 3 while for M = 3 the sequence 01120221 repeats after 8 nos.
*/

#include <iostream>
using namespace std;

unsigned long long pisano(unsigned long long m)
{
    unsigned long long prev = 0;
    unsigned long long curr = 1;
    unsigned long long res = 0;
 
    for(int i = 0; i < m * m; i++)
    {
        cout<<i+1<<" IN : "<<"Prev: "<<prev<<"  "<<"curr: "<<curr<<"  "<<"res: "<<res<<"  "<<endl;
        unsigned long long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
 
        if (prev == 0 && curr == 1)
        {
            res = i + 1;    //frequency of sequence count
            cout<<"sequence repeat : "<<i+1<<endl;
        }
        cout<<i+1<<" OT : "<<"Prev: "<<prev<<"  "<<"curr: "<<curr<<"  "<<"res: "<<res<<"  "<<endl;
    }
    return res;
}

unsigned long long get_fibonacci_huge_naive(unsigned long long n, unsigned long long m) 
{
    long pisanoPeriod = pisano(m);
    cout<<"\npisanoPeriod = pisano(m) : "<<pisanoPeriod<<endl;

    cout<<"n = n % pisanoPeriod : "<<n<<" \% "<< pisanoPeriod << " = ";
    n = n % pisanoPeriod;
    cout<<n<<endl;

    if (n <= 1)
        return n;

    unsigned long long prev = 0, curr  = 1, next = 0;

    for (unsigned long long i = 0; i < n - 1; ++i) 
    {
        next = (prev + curr)%m;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() 
{
    unsigned long long out;
    cout<<"\n--------------get_fibonacci_huge_naive(9999999999999,2)-----------\n";
    out = get_fibonacci_huge_naive(9999999999999,2);
    cout <<"Output: "<<out << '\n';
    cout<<"\n--------------get_fibonacci_huge_naive(9999999999999,3)-----------\n";
    out = get_fibonacci_huge_naive(9999999999999,3);
    cout <<"Output: "<<out << '\n';

    return(0);
}
