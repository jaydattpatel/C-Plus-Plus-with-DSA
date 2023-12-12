/* author: jaydattpatel
 working of Binary operator overloading

 The operators that require two operands for its operation are known as 
binary operators. The examples of some of the binary operators are 
arithmetic operators like +, *, /, etc. relational operators like <,>.
*/
#include <iostream>
using namespace std;

class Complex
{
    private:
        int real, img;

    public:
        Complex()
            {
                real = 0;
                img = 0;
            }
        
        Complex(int r, int i)
            {
                real = r;
                img = i;
            }
            
        void print()
            {
                int newImg = img < 0 ? -img : img;
                cout << real << (img < 0 ? " - ": " + ")  << "i" << newImg  << endl;
            }
        
        // overloading unary Minus (-) operator 
        Complex operator-()
            {
                return Complex(-(this->real), -(this->img) );
            }
        // overloading unary (+) operator
        void operator+() //prefix expression
            {
                this->real = this->real+1;
                this->img = this->img+1;
            } 
        void operator+(int a)   //postfix expression
            {
                this->real = this->real+a;
                this->img = this->img+a;
            }
};


int main()
{
    // instantiating a Complex object c1 with values
    Complex c1(-3, 4);
    
    // printing the c1 complex object in the output
    cout<<"c1 = ";
    c1.print();

    // invoking the overloaded unary minus (-) on c1 object and
    // storing the returned object in a new c2 Complex object
    Complex c2 = -c1;
    
    // printing the c2 complex object in the output
    cout<<"c2 = ";
    c2.print();

    +c1;
    cout<<"(+c1) = ";
    c1.print();

    c2+3;
    cout<<"(c2+3) = ";
    c2.print();
    
    return 0;
}
