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

class base {
public:
	void fun_1() { cout << "base-1\n"; }
	virtual void fun_2() { cout << "base-2\n"; }
	virtual void fun_3() { cout << "base-3\n"; }
	virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
	void fun_1() { cout << "derived-1\n"; }
	void fun_2() { cout << "derived-2\n"; }
	void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
	base *bs;
	derived *dr;
	derived obj1;
	
	bs = &obj1;     //here pointer bs is class base pointer
    dr = &obj1;     //here pointer dr is derived class pointer
    
	//here pointer bs is class base pointer
	bs->fun_1(); 	
	bs->fun_2(); 
	bs->fun_3();
	bs->fun_4(); 
//	bs->fun_4(5); //error:here pointer bs is base class pointer and it is bind first with base class
	
	cout<<"\n\n";

	//here pointer dr is derived class pointer
	dr->fun_1();
	dr->base::fun_1();
	dr->fun_2();
	dr->base::fun_2();
	dr->fun_3();
	dr->base::fun_3();
	dr->fun_4(5);
	dr->base::fun_4(); //error:here pointer dr is derived class pointer and it is bind first with derived class
	
	//pointer is of base type and function is of derived class p->fun_4(5);
	
	return 0;
}
