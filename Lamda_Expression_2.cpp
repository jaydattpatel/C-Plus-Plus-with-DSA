// author: jaydattpatel
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
#include <iostream>
using namespace std;

int main() 
{  
    auto sum = [](int x, int y) {return(x + y);};
    auto sub = [](int x, int y) {return(x - y);};
    auto mul = [](int x, int y) {return(x * y);};
    auto divd = [](int x, int y) {if (y != 0) return (x / y); else  return 0;};

    int x, y, choice, result;
    int (*ope[4])(int, int);    //create function pointer
    ope[0] = sum;   //sum(x,y)
    ope[1] = sub;   //sub(x,y)
    ope[2] = mul;   //mul(x,y)
    ope[3] = divd;  //divd(x,y)
    cout<<"Enter your choice:\n0.sum\n1.subtract\n2.multiply\n3.divide\n";
    cin>>choice;
    cout<<"Enter two integer numbers: ";
    cin>> x >> y;
    if(choice<4)
    {   
        result = ope[choice](x, y);
        cout<<"result: "<<result;
    }
    else cout<<"Invalid Input.";
    return 0;
    
}

