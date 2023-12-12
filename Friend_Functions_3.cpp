// author: jaydattpatel
//friend function

#include <iostream>

class class_B;

class class_A 
    {
        public:
            void showB(class_B&);
    };

class class_B 
    {
        private:
            int b;

        public:
            class_B() { b = 5; }
            friend void class_A::showB(class_B  &x); // Friend function
    };

void class_A::showB(class_B &x)
{
	// Since showB() is friend of class_B, it can
	// access private members of class_B
	std::cout << "\nclass_B::b = " << x.b;
}

int main()
{
	class_A a;
	class_B x;
	a.showB(x);
	return 0;
}
