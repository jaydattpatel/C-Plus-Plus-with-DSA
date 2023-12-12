#include <iostream>
using namespace std; 

const int MAX = 3; 

template <class T> 
    class vector 
    { 
        
        public: 
            T* v; //type T vector 
            vector() 
            { 
                v = new T[MAX];
                for (int i=0; i<MAX; i++)
                    v[i] = 0; 
            } 
 
            void operator=(T *y) 
            {
              for (int i=0; i<MAX; i++) 
                    this->v[i] = y[i];  
            } 
            T operator*(vector &y) 
            {
                T sum = 0; 
                for (int i=0; i<MAX; i++) 
                {
                    sum = sum + this->v[i] * y.v[i]; 
                }
                return sum; 
            } 
    };

int main() 
{ 
    int x[MAX] = {1, 2, 3}; 
    int y[MAX] = {4, 5, 6}; 
    vector <int> v1; 
    vector <int> v2; 
    v1 = x; 
    v2 = y; 
    cout<<"\nVector v1: ";
    for(int i = 0; i<MAX ;i++)
        cout<<" "<<v1.v[i];

    cout<<"\nVector v2: ";
    for(int i = 0; i<MAX ;i++)
        cout<<" "<<v2.v[i];
        
    int R = v1 * v2; 
    cout << "\nR = " << R << "\n"; 
    return 0; 
} 