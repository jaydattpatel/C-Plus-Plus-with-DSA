// C++ program to demonstrate lambda expression in C++
/*
A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from the enclosing scope in three ways : 
      Capture by reference 
      Capture by value 
      Capture by both (mixed capture)
Syntax used for capturing variables : 
      [&] : capture all external variables by reference 
      [=] : capture all external variables by value 
      [a, &b] : capture a by value and b by reference
A lambda with an empty capture clause [ ] can only access variables which are local to it. 

struct S { void f(int i); };
void S::f(int i) 
{
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}
*/

/*
Mutable specification
Typically, a lambda's function call operator is const-by-value, but use of the mutable keyword cancels this out. It doesn't produce mutable data members. The mutable specification enables the body of a lambda expression to modify variables that are captured by value.
*/
#include <iostream>
using namespace std;

int main()
{
   int m = 0;
   int n = 0;
   [&, n] (int a) mutable { m = ++n + a; }(4);
   cout <<"m: "<< m <<"\nn: " << n << endl;

   int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);
    // Print the result.
    cout <<"timestwoplusthree : "<<timestwoplusthree << endl;
}