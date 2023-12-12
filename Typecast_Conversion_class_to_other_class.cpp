/*
author: jaydattpatel
Conversion from class to other class type

Implicit Type Conversion: Also known as ‘automatic type conversion.
Done by the compiler on its own, without any external trigger from the user.

Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.

*/
#include <iostream>
using namespace std;

class C1;
class C2;

class C1 
{
   public:
    int a = 10, copy_c1 = 0;
    void display()
        {cout <<"\nclass C1\ta: "<<a << "\tcopy_c1 :" <<copy_c1;}
    operator C2();

};

class C2 
{
   public:
    int b = 20, copy_c2 = 0;
    void display()
          {cout <<"\nclass C2\tb: "<<b << "\tcopy_c2 :" <<copy_c2;}
    operator C1();

};


C1::operator C2()
    {   cout<<" \n----Type cast from C1 to C2----";
        C2 temp;
        temp.copy_c2 = (a+2);
        return (temp);
    }

C2::operator C1()
    {   cout<<" \n----Type cast from C2 to C1----";
        C1 temp;
        temp.copy_c1 = (b+2);
        return (temp);
    }

int main()
{
    C1 P;
    C2 Q;
    cout<<"-------Default value--------";
    P.display();
    Q.display();
    Q = P;
    P.display();
    Q.display();
    P = Q;
    P.display();
    Q.display();

   return 0;
}