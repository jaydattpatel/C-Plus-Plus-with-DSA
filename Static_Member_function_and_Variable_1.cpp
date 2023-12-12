//author: jaydtatpatel
//static member function and variable
#include <iostream>
using namespace std;

class class_A
    {
        public:
            class_A() { cout << "class_A's Constructor Called " << endl; }
    };

class class_B
    {
            static class_A a;
        public:
            class_B() { cout << "class_B's Constructor Called " << endl; }
    };

int main()
    {
        class_B b;
        /*B’s constructor, it doesn’t call A’s constructor. The reason for this is simple, static members are only declared in a class declaration, not defined. They must be explicitly defined outside the class using the scope resolution operator. 
        If we try to access static member ‘a’ without an explicit definition of it, we will get a compilation error.*/
        return 0;
    }
