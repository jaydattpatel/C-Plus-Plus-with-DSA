// author: jaydattpatel
#include<iostream> 
using namespace std; 

template< class T1, class T2> 
class A
    { 
        T1 a; 
        T2 b; 
        
        public: 
            A(T1 x, T2 y) 
            { 
                a=x; 
                b=y; 
            } 
            void show() 
            { 
                cout << a << " and " << b << "\n";
            } 
            void swap()
            { 
                T1 temp = a;
                a = static_cast<T1>(b);
                b = static_cast<T2>(temp);
            } 
    };

int main() 
{ 
    int i1 = 56,i2 = 67;
    float f= 1.11;
    char c = 'A';
    A <float, int> d1 (f, i1); 
    A <int, char> d2 (i2, c);
    d1.show(); 
    d2.show(); 

    cout<<"After swap:\n";
    d1.swap();
    d2.swap();
    d1.show(); 
    d2.show(); 
    return 0; 
}