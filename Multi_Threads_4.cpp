//multi-threads programs temperature forecast

#include <iostream>
#include <thread>
#include <unistd.h>
#include <map>
using namespace std;


void refreshForcast(map<string,int> forcast)
{
    while(true)
        {
            cout<<endl;
            for(auto &item : forcast)
                {
                    cout<<item.first<<": "<<item.second<<endl;
                    item.second++;
                }
                this_thread::sleep_for(3000ms);
        }
}
 
int main()  
{
    map<string,int> forcast;
    forcast = {
        {"Delhi",15},
        {"Ahmedabad",30},
        {"Mumbai",40},
        };
    thread t(refreshForcast,forcast);
    sleep(10);      //system sleep to keep run threads
    t.detach();     //detach threads after sleep
}