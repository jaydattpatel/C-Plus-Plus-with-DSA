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
            virtual int getarea()
            {
                cout<<"\ngetarea() acceced from Base class: shape\n";
                    return 0;
            };

    };
 
class rectangle: public shape       // Derived classes
    {
        public:
            int getarea()
            {
                cout<<"\ngetarea() acceced from derived class : rectangle\n";
                return (length * breadth);
            } 
    };
class square: public shape      // Derived classes
    {
        public:
            int getarea()
            {
                cout<<"\ngetarea() acceced from derived class : square\n";
                return (length*length);
            }
    };

int main()
{
    shape S;
    S.getarea();

    rectangle rect;
    rect.setbreadth(5);
    rect.setlength(7);
    cout << "\nArea of rectangle is: " << rect.getarea() << endl;    // Print the area of the object.

    square sq;
    sq.setlength(3);
    cout << "\nArea of square is: " << sq.getarea() << endl;  // Print the area of square.
    return 0;
} 