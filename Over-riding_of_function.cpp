/* author: jaydattpatel
working of function overriding
If base class and its derived class has same name of functions then it is called function overriding. 
*/
#include<iostream>
using namespace std;

class base 
	{
	public:
		void fun() { cout << "access from base \n"; }
	};

class derived_1 : public base 
	{
	public:
		void fun() { cout << "access from derived_1\n"; }
	};

class derived_2 : public derived_1 
	{
	public:
		void fun() { cout << "access from derived_2\n"; }
	};	

int main()
{
	base obj1;
	derived_1 obj2;
	derived_2 obj3;

	cout<<"\naccess using obj1---------------\n";
    obj1.fun();

	cout<<"\naccess using obj2---------------\n";
    obj2.fun();
    obj2.base::fun();

	cout<<"\naccess using obj3---------------\n";
	obj3.fun();
    obj3.derived_1::fun();
    obj3.base::fun();
	
	return 0;
}
