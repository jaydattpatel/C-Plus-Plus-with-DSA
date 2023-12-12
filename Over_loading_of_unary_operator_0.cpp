/* author: jaydattpatel
 working of unary operator overloading

unary operators are - the increment (++) and decrement (--) operators, the unary minus (-) operator and the logical not (!) 
operator. 
In case of overloading of unary operators, the calling operand can be either 
left or right side of the operator as in case of increment and decrement 
operators. While defining the operator functionality for the class the keyword 
operator is used.
*/
#include <iostream>
using namespace std;

class counter 
    { 
        unsigned int c; 

        public: 
            counter() 
                {c=0;} 
            int getcount() 
                {return c;} 
            /*    
            void operator ++() 
                { c++;} 
            */
            counter operator ++() 
                { 
                    c++;
                    return counter(c);
                }
            counter(int num) 
                {c=num;}
    };
int main() 
{ 
    counter c1,c2;
    ++c1;
    ++c1;
    cout<<c1.getcount()<<endl;
    /*
    c1++;
    c2 = c1++;
    above c1++ gives error
    */
    c2 = ++c1;
    cout<<c1.getcount()<<endl; 
    cout<<c2.getcount(); 
    return 0;
}