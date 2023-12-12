// fibonacii series upto 10000
// author: jaydattpatel
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define MAXDIGIT 5000
inline unsigned short int Q[MAXDIGIT];

ofstream file("Fibonacci-10000.txt");

inline void Add(unsigned short int *n, unsigned short int *p, unsigned short int *c, int &max)
{
    if(max == MAXDIGIT-1)
        {
            cout<<"\n Please increase MAXDIGIT..... !";
            exit(2);
        }
    for(int i = 0; i <(max + 2) ;i++)
        Q[i] = 0;

    for(int i = 0; i <= max ;i++)
        {
            n[i] = p[i] + c[i] + Q[i];
    
            if(n[i] > 9 )
            {
                if(i == max)
                    max++;
                Q[i+1] = n[i] / 10;
                n[i] = n[i] % 10;
            }
        }
    return;
    
}

inline void show(const unsigned short int *x,const int &max)
{
        for(int j = max; j>=0 ; j--)
        {
                cout<<x[j];
                file<<x[j];
        }
        cout<<"\t max: "<<max;
}


inline void fib_long(int n) 
{
    unsigned short int p[MAXDIGIT], c[MAXDIGIT], nx[MAXDIGIT], 
                            *prev = &p[0], *curr = &c[0], *next = &nx[0], *temp;
    for(int j = 0; j <MAXDIGIT ;j++)
        next[j] = curr[j] = prev[j] = 0;
                
    prev[0] = 0, curr[0] = 1, next[0] = 0;

    int max = 0;
    cout<<"\n     0 : "<<prev[0]<<"\n     1 : "<<curr[0];
    file<<"\n     0 : "<<prev[0]<<"\n     1 : "<<curr[0];
    for(int i =2; i <= n; i++)
        {
            Add(next,prev,curr,max);
            cout<<"\n"<<right<<setw(6)<<i<<" : ";
            file<<"\n"<<right<<setw(6)<<i<<" : ";
            show(next,max);
            for(int j = 0; j <(max+2) ;j++)
                prev[j] = 0;
            temp = prev;
            prev = curr;
            curr = next;
            next = temp;
        }
}

int main() 
{
    int n = 0;
    if(file.is_open()) //if(!file) can also use to check open file error
        cout<<"File opened successfully to write\n";
    else 
    	{
			cout<<"Error to Open File !!!";
			exit(1);
		}
    cout<<"Enter value : ";
    cin >> n;
    cout<< "\nfib_long: ";
    fib_long(n);

    file.close();
    return 0;
}
