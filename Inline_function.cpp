// author: jaydattpatel
/*
inline function in c++

When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the arguments of the function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns control to the calling function. This can become overhead if the execution time of function is less than the switching time from the caller function to called function (callee). For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less than the switching time.

C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.
The syntax for defining the function inline is:

inline return-type function-name(parameters)
{
    // function code
} 
Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement doesn’t exist in function body.
5) If a function contains switch or goto statement.

Inline functions provide following advantages:
1) Function call overhead doesn’t occur.
2) It also saves the overhead of push/pop variables on the stack when function is called.
3) It also saves overhead of a return call from a function.
4) When you inline a function, you may enable compiler to perform context specific optimization on the body of function. Such optimizations are not possible for normal function calls. Other optimizations can be obtained by considering the flows of calling context and the called context.
5) Inline function may be useful (if it is small) for embedded systems because inline can yield less code than the function call preamble and return.
*/

#include <iostream>
using namespace std;



class operation
{
    private:
        int a,b,add,sub,mul;
        float div;
    public:
        void get(int, int);
        void sum();
        void difference();
        void product();
        void division();
        friend void cube(operation &s);
};

inline void operation :: get(int x, int y)
{
    a = x;
    b = y;
}

inline void operation :: sum()
{
	add = a+b;
	cout << "Addition : " << a+b << "\n";
}

inline void operation :: difference()
{
	sub = a-b;
	cout << "Difference : " << a-b << "\n";
}

inline void operation :: product()
{
	mul = a*b;
	cout << "Product : " << a*b << "\n";
}

inline void operation ::division()
{
	div=a/b;
	cout<<"Division : "<<a/b<<"\n" ;
}

inline void cube(operation &s)
{
	int cube;
    cube = (s.a)*(s.a)*(s.a);
    cout << "The cube is: "<< cube<< "\n";
}

int main()
{
	cout << "Program using inline function\n";
	operation s;
	s.get(10,5);
	s.sum();
	s.difference();
	s.product();
	s.division();
    cube(s);
	return 0;
}
