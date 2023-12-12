/* author: jaydattpatel
 working of function overloading
If The class has same name of different function with different arguments in same scope then it is called function overloading.
*/
#include<iostream> 
#include<math.h>
using namespace std;
#define pi 3.14 

class Areacalculate 
{ 
 public: 
    void area(float a)
        { 
        cout<<"Area of Circle:"<<pi*a*a; 
        } 
    void area(float a,float b) 
        { 
        cout<<"Area of rectangle:"<<a*b; 
        } 
    void area(float a,float b,float c) 
        { 
            float area;
            float s = (a+b+c)/2;
            area = sqrt((s*(s-a)*(s-b)*(s-c)));
            cout<<"Area of triangle:"<<area; 
        } 
};

 int main() 
    { 
    int ch; 
    float a,b,c,r;
    Areacalculate Area;
    cout<<"\n\t\tFunction Overloading"; 
    while(1)
    {
            cout<<"\n\n1.Area of Circle\t2.Area of Rectangle\t3.Area of Triangle\t4.Exit\n";
            cout<<"Enter your Choice:";
            cin>>ch; 
            switch(ch) 
                { 
                    case 1: 
                        cout<<"\nEnter Radious of the Circle:"; 
                        cin>>r; 
                        Area.area(r); 
                        break; 
                    case 2: 
                        cout<<"\nEnter Two Sides of the Rectangle:";
                        cin>>a>>b; 
                        Area.area(a,b); 
                        break; 
                    case 3: 
                        cout<<"\nEnter Three Sides of the Triangle:"; 
                        cin>>a>>b>>c; 
                        Area.area(a,b,c); 
                        break; 
                    case 4: 
                        exit(0); 
                } 
    }
    return 0; 
    }