// fibonacii series with specific digits
// author: jaydattpatel
#include <iostream>
#include <cassert>
using namespace std;

unsigned long long int fib_last_digit(unsigned long long int n) 
{
    if (n<= 1)
        return n;
    unsigned long long int prev = 0, curr = 1, next = 0;
    for(int i =2; i <= n; i++)
        {
            next = (prev + curr)%10;
            prev = curr;
            curr = next;
        }
    return curr;
}

int main() 
{

    cout<< "fib_last_digit: "<<fib_last_digit(239);

    return 0;
}
