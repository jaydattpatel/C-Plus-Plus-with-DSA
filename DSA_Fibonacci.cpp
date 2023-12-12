// fibonacii series or specific term
// author: jaydattpatel
#include <iostream>
#include <cassert>
using namespace std;

//method-1  this algoritham will work for large number
unsigned long long fib_fast(unsigned long long n) 
{
    if (n<= 1)
        return n;
    unsigned long long prev = 0, curr = 1, next = 0;
    for(int i =2; i <= n; i++)
        {
            next = prev + curr;
            prev = curr;
            curr = next;
        }
    return curr;
}


//method-2 recursive
unsigned long long int fib_naive(int n) 
{
    if (n <= 1)
        return n;

    return fib_naive(n - 1) + fib_naive(n - 2);
}

void test_solution() 
{
    assert(fib_fast(3) == 2);
    assert(fib_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fib_fast(n) == fib_naive(n));
}

int main() 
{
    int n = 0;
    cout<<"Enter value (1 - 80) : ";
    cin >> n;
    cout<< "\ntesting fast and naive......";
    test_solution();
    cout<<"Success.";
    cout<< "\nfib_fast: "<<fib_fast(n);
    cout<< "\nfib_naive: "<< fib_naive(n);
    
    return 0;
}
