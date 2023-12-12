//programming for multiple inheritancea and its ambiguty
// author: jaydattpatel

#include<iostream>
using namespace std;

class A
{
    private: int x,xx;
    public:
        A() 
            { 
                x = 0; xx = 0;
                cout << "A() constructor called" << endl; 
            }
        A(int p, int q) 
            { 
                x = p; xx = q;
                cout << "A(int,int) constructor called" << endl;
            }
        virtual void show()
            {
                cout<<"x : "<<x<<"\txx :"<<xx<<endl;
            }
};

class B
{
    private: int y,yy;
    public:
        B() 
            {
                y = 0; yy = 0;
                cout << "B() constructor called" << endl;
            }
        B(int p, int q) 
            { 
                y = p; yy = q;
                cout << "B(int,int) constructor called" << endl;
            }
        virtual void show()
            {
                cout<<"y : "<<y<<"\tyy :"<<yy<<endl;
            }
};

class C: public A, public B // Note the order
{
    private: int z,zz;
    public:
        C() 
            { 
                z = 0; zz = 0;  
                cout << "C() constructor called" << endl; 
            }
        C(int p, int q): A(p,q) , B(p,q) //here A(int,int) and B(int,int) constructure also called 
            { 
                z = p; zz = q;
                cout << "C(int,int) constructor called" << endl;
            }
        virtual void show()
            {
                cout<<"z : "<<z<<"\tzz :"<<zz<<endl;
            }  
};

int main()
{
    cout<<"----------------------------------"<<endl;
    C C1;
    C1.A::show();
    C1.B::show();
    C1.show();

    cout<<"----------------------------------"<<endl;
    C C2(5,10);
    C2.A::show();
    C2.B::show();
    C2.show();

	return 0;
}
