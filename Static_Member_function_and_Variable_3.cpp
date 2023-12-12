//author: jaydtatpatel
//static member function and variable
/*
objects counts using static member variable
*/
#include <iostream>
using namespace std;

class Box 
{
   public:
      static int objectCount;
      
      // Constructor definition, variable declare in constructor for abstraction
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      static int getCount() {
         return objectCount;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) 
{
    // Print total number of objects before creating object.
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box0;
    Box Box1(3.3, 1.2, 1.5);    // Declare box1
    Box Box2(1.7, 2.0, 4.3);    // Declare box2

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << Box::getCount() << endl;

    cout<<"\nBox0 volume: "<<Box0.Volume()<<"\nBox1 volume: "<<Box1.Volume()<<"\nBox2 volume: "<<Box2.Volume(); 
    cout<<"\nBox0 ObjectCount: "<<Box0.getCount()<<"\nBox1 ObjectCount: "<<Box1.getCount()<<"\nBox2 ObjectCount: "<<Box2.getCount(); 


    return 0;
}