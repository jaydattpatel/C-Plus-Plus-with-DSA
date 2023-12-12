// author: jaydattpatel
// Compile-time Polymorphism - static binding - early binding 
// function overloading  and operator overloading
// Non-virtual function binded at compile time


#include <iostream>
using namespace std;

class A 
{
	public:
	int i = 5;
	void func(int x)  //same name of function overloading
		{
			cout << "value of x is " <<x << endl;
		}
	void func(double x)	//same name of function overloading
		{
			cout << "value of x is " <<x << endl;
		}
	void func(int x, int y)	//same name of function overloading
		{
			cout << "value of x and y is " <<x << ", " << y << endl;
		}
	A operator +(A &p) 	//function overloading
	{
		this->i = this->i + p.i;
		return(*this);
	}
};


int main()
{
	A c1,c2,c3;
	c1.func(7);
	c1.func(9.132);
	c1.func(85, 64);

	c3 = c1 + c2;
	cout<<c3.i<<endl;


	return 0;
}
