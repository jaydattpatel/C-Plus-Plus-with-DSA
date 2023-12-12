// author: jaydattpatel
#include <iostream>
using namespace std;


template <class T> 
class info 
{
    public:
    	info(T A) // constructor of type template
    	{
    		cout << "\n"
    			<< "A = " << A
    			<< " size of data in bytes:" << sizeof(A);
    	} 
}; 

int main()
{

	info<int> q(22);
	info<float> r(2.25);
	info<char> p('x');

	return 0;
}
