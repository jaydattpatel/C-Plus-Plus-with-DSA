//programming for multiple inheritancea and its ambiguty
// author: jaydattpatel

#include<iostream>
using namespace std;

class A
{
    public:
        A() { cout << "A's constructor called" << endl; }
};

class B
{
    public:
        B() { cout << "B's constructor called" << endl; }
};

class C: public A, public B // Note the order
{
    public:
        C() { cout << "C's constructor called" << endl; }
};

//--Ambiguty in multiple inheritance--------------------------------------------------
class X
{
    protected:
        int a=5;
    public:
        X() { cout << "X's constructor called" << endl; }
};

class Y: virtual public X
{
    public:
        Y() { cout << "Y's constructor called" << endl; }
};
class Z: virtual public X
{
    public:
        Z() { cout << "Z's constructor called" << endl; }
};

class P: public Y, public Z     //here Y and Z both is  derived from base class X so virtual key is used for clearity
{
    public:
        P() { cout << "P's constructor called" << endl; }
        int fun()
            {return a;}
};
//---------------------------------------------------
int main()
{
    cout<<"----------------------------\n";
    C c;
    cout<<"----------------------------\n";
    P p;
    cout<<"a: "<<p.fun();
	return 0;
}
