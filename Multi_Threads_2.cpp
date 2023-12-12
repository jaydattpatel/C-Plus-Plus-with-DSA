// CPP program to demonstrate multithreading using three different callables.
#include <iostream>
#include <thread>
using namespace std;

// A dummy function
void foo(int Z)
    {
        for (int i = 0; i < Z; i++) 
            cout << "Thread-1 : function pointer as callable\n";
    }

// A callable object
class thread_obj 
    {
        public:
            void operator()(int x)
            {
                for (int i = 0; i < x; i++)
                    cout << "Thread-2 : function object as callable\n";
            }
    };

int main()
{
	cout << "Threads 1 and 2 and 3 operating independently" << endl;
	thread th1(foo, 3); // This thread is launched by using function pointer as callable
	thread th2(thread_obj(), 3);    // This thread is launched by using function object as callable

	// Define a Lambda Expression
	auto f = [](int x) 
        {
		    for (int i = 0; i < x; i++)
			    cout << "Thread-3 : lambda expression as callable\n";
	    };

	thread th3(f, 3);   // This thread is launched by using lamda expression as callable

	th1.join(); // Wait for the threads to finish Wait for thread t1 to finish
	th2.join(); // Wait for thread t2 to finish
	th3.join(); // Wait for thread t3 to finish

	return 0;
}
