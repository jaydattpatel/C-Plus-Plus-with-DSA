// author: jaydattpatel
//Run-time polymorphism - late binding -dynamic binding
// Virtual Functions or function overriding
// Virtual function binded at runtime (Runtime polymorphism)

#include<iostream>
using namespace std;

class base 
{
	public:
	virtual void print()
	{
		cout << "print base class" <<endl;
	}
};

class derived : public base 
{
	public:
	void print()	
	{
		cout << "print derived class" <<endl;
	}
};


int main()
{
	base* bptr;
	derived *dptr;

	derived d;
	bptr = &d;
	dptr = &d;

	// Virtual function binded at runtime (Runtime polymorphism)
	bptr->print();

	// Virtual function binded at runtime (Runtime polymorphism)
	dptr->print();


	return 0;
}
