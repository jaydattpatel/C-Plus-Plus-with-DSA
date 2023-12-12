// author: jaydattpatel
#include<iostream>
using namespace std;


class shape // Base class
    {
        protected:          // protected data can be access within class and derived class
            int length;
            int breadth;

        public:
            void setlength(int l)
                {
                    length = l;
                }
            void setbreadth(int b)
                {
                    breadth = b;
                }

    };
 
class rectangle: public shape       // Derived classes
    {
        public:
            int getarea()
            {
                return (length * breadth);
            } 
    };
class square: public shape      // Derived classes
    {
        public:
            int getarea()
            {
                return (length*length);
            }
    };
int main()
{
    rectangle rect;
    square sq;
    rect.setbreadth(5);
    rect.setlength(7);
    cout << "Area of rectangle is: " << rect.getarea() << endl;    // Print the area of the object.
    sq.setlength(5);
    cout << "Area of square is: " << sq.getarea() << endl;  // Print the area of square.
    return 0;
} 