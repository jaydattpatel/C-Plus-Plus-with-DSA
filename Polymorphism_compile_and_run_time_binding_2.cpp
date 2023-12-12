// author: jaydattpatel
//Compile and Run-time polymorphism.

// Compile-time Polymorphism - static binding - early binding 
// function overloading  and operator overloading
// Non-virtual function binded at compile time

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
			cout << "print- base class" <<endl;
		}
	void show()	
		{
			cout << "show- base class" <<endl;
		}
};

class derived : public base 
{
	public:

	void print()	
		{
			cout << "print- derived class" <<endl;
		}
	void show()	
		{
			cout << "show- derived class" <<endl;
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
	dptr->print();

	//Non-virtual function binded at compile time
	bptr->show();
	dptr->show();

	return 0;
}
