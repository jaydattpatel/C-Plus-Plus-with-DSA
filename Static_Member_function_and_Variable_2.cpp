//author: jaydtatpatel
//static member function and variable
/*
static member function can not be declare as virtual and friend function.
static member function can not be declared const, volatile, or const volatile. 
static member function can not be same as other function name
*/
#include <iostream>
using namespace std;

class class_A
    {
        int x;

        public:
            class_A() { cout << "\nclass_A's Constructor Called " << endl; }
    };

class class_B
    {
            static class_A a;

        public:
            class_B() { cout << "\nclass_B's Constructor Called " << endl; }
            static class_A getA() 
                { return a; }
    };

class_A class_B::a;  // defination of a (so constri=uctor will execute of class_a when program starts)

int main()
    {
        cout<<"\n1.------------\n";
        class_A a = class_B::getA();
        cout<<"\n2.------------\n";
        class_B b1, b2, b3;
        cout<<"\n3.------------\n";
        class_A a1;
        cout<<"\n4.------------\n";
        class_A a2 = b1.getA();
        return 0;
    }
