//multi-threads programs

#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

class Thread_I
{
    thread &m_thread;
    public:
        Thread_I(thread  &threadObj) : m_thread(threadObj)
            {

            }
        ~Thread_I()
            {
                // Check if thread is joinable then detach the thread
                if(m_thread.joinable())
                {
                    m_thread.detach();
                }
            }
};
void thread_function()
{
    for(int i = 0; i < 10; i++)
        cout<<(i+1)<<". thread_function Executing"<<endl;
}
 
int main()  
{
    thread threadObj(thread_function);
    Thread_I wrapperObj(threadObj); // If we comment this Line, then program will crash
    sleep(2);

    return 0;
}