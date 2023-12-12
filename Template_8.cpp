#include <iostream>
using namespace std;

template <class I=int, class C = char, class F = float >  
//here default type class is defined so if not metioned in main program then it will take as default.
class A 
{
	public:
		I x;
		C y;
		F z;	
};

int main()
{

	//this will call A<type,default,default>
	A<> s0; 

	//this will call A<type,default,default>
	A<int> s1; 
	A<char> s2; 
	A<float> s3; 

	//this will call A<type,type,default>
	A<int,int> s4; 
	A<char,char> s5; 
	A<float,float> s6; 

	//this will call as per mention A<type,type,type>
	A<int,char,float> s7; 
	A<char,int,float> s8; 
	A<int,float,char> s9; 
	A<float,char,int> s10; 
	return 0;
}
