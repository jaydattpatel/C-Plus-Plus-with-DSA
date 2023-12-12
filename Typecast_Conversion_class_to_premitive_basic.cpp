/*
author: jaydattpatel
Conversion from class to premitive basic type

Implicit Type Conversion: Also known as ‘automatic type conversion.
Done by the compiler on its own, without any external trigger from the user.

Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.

*/
#include <iostream>
using namespace std;
 
class A 
{
    int x, y;
 
    public:
        // Constructor
        A(int a, int b)
            {
                x = a;
                y = b;
            }
     
        // Casting operator
        operator int()
            {
                return (x + y);
            }

};
 
 
int main()
{
   
    int a, y;
    a = 2;
    y = 25;

    int d_int;
 
    // Create A Class  object
    A obj(a, y);

    cout << "--------Method-1 operator------"<<endl;
    d_int = obj;
    cout << "Total Minutes are "<< d_int << endl;

    cout << "--------Method-2 operator------"<<endl;
    d_int = (int)(obj);
    cout << "Total Minutes are "<< d_int << endl;

    cout << "--------Method-3 operator------"<<endl;
    d_int = int(obj);
    cout << "Total Minutes are "<< d_int << endl;

    cout << "--------Method-4 operator------"<< endl;
    d_int = obj.operator int();
    cout << "Total Minutes are "<< d_int << endl;
 
    return 0;
}