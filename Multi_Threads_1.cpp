//multi-threads programs

#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;


void fun1()
    {
        for (int i = 0; i < 50; i++) 
            cout << " + ";
    }

void fun2()
    {
        for (int i = 0; i < 50; i++) 
            cout << " - ";
    }

void fun3(int x)
    {
        for (int i = 0; i < x; i++) 
            cout <<" "<<i<<" ";
    }

void fun4(string msg)
{
  cout << "fun3: " << msg;
}


int main()
{
    thread t3(fun3,25);
	thread t1(fun1);
    thread t2(fun2);
    thread t4(fun4, "hello"); 

    sleep(2); //wait so that few time to be completed all task 

    //now all threads are removed using detach.
    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
   
	return 0;
}
