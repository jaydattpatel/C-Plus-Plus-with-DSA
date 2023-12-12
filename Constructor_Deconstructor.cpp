/* constructor , operator constroctor and deconstructor

// author: jaydattpatel

I. Default constructor
II. Copy constructor
III. Operator Constructor
IV. Destructor

constructors block will executed one time whenever new object initialized and new object initialized by copy object, passing the object to function block, rerutning object from function block.

construction copy invocation when:
1.when passing object as arrgument
2.returning object from function
3.new object initialized by copying object which is returned from any functionblock

constructor and deconstructor block name must same as class name.

operator block execute when you use operator for operation.

*/

#include<iostream>
using namespace std;

class cube
    {
        private:
        double length;
        
        public:
        string cube_name;

        double getVolume(){
            return(length * length * length); 
        }
        double getSurfacearea(){
            return(6 * length * length); 
        }
        void setLength(double l){
            length = l;
        }
        void empty(){};
        /*  here constroctor declared and implimented later. 
         
        Here class cube so,
        countructor : cube(parameters){body}
        deconstructor : ~cube(parameters){body}           
        you can create multiple constructor       */

        cube();   //(Default constructor) 
        cube(double lt);   //(Customize constructor)
        cube(int lt);  //(Customize constructor)
        cube(const cube &obj); //(Copy constructor)
        ~cube(); //(Default Deconstructor)

        
    }; 

//constructor-1 implimentation (Default constructor) 
//contructor-1  (execute whenever new object initialized or new object initialized by copying object which is returned from any functionblock ) (note: it does not execute if you copy old object to old object)  
cube::cube()  
    {
        cout<<"\nInside   Default Constroctor:(cube::cube())\n";
        length = 2;
    }

//constructor-2 implimentation (Customize constructor)
cube::cube(double lt) //contructor-2 (execute when new object initialized by passing parameters)
    {
        cout<<"\nInside   Custom Constroctor:(cube::cube(double lt))\n";
        length = lt;
    }

cube::cube(int lt) 
    {
        cout<<"\nInside   Custom Constroctor:(cube::cube(int lt))\n";
        length = lt;
    }

//constructor-3 implimentation (Copy constructor)
//contructor-3 (execute when new object initialized by passing parameters, also when passing object of this class to function block as parameters)
cube::cube(const cube &obj) 
    {
        cout<<"\nInside   Copy Constroctor:(cube::cube(const cube &obj))\n";
        length = obj.length;
    }

//when you pass the object, the copy construction block will be executed then function
void foo(cube cc)
    { 
        cout<<"\nInside  Argument passed to (foo(cube cc))\n";
        cc.cube_name = "foo(cube cc)_temp_cube\0";
    }

//when you return object the class, default construction block will be executed
cube foo()
    {
        cout<<"\nInside   Return class from (foo())\n";
        cube c;
        c.cube_name = "foo()_temp_cube\0";
        return c;
    }

// Deconstructor implimentation 
cube::~cube() // (this will execute when object is going to be delete or release from scope or any function blocks)
    {
        cout<<"\nInside   Deconstructor:(cube::~cube())"<<"\t\tDeleted : "<<this->cube_name <<endl;
    }


int main()
    {
        cout<<"\n============================= 1 =============================\n";
        cube c0;
        c0.cube_name = "cube_c\0";
        double a = c0.getVolume();
        double b = c0.getSurfacearea();
        cout<<"Volume: "<<a<<"\nSurfacearea: "<<b<<"\n\n";

        cout<<"\n============================= 2 =============================\n";
        cube c1(5);
        c1.cube_name = "cube_c1\0";
        a = c1.getVolume();
        b = c1.getSurfacearea();
        cout<<"Volume: "<<a<<"\nSurfacearea: "<<b<<"\n\n";

        cout<<"\n============================= 3 =============================\n";
        cube c2(c1);
        c2.cube_name = "cube_c2\0";
        a = c2.getVolume();
        b = c2.getSurfacearea();
        cout<<"Volume: "<<a<<"\nSurfacearea: "<<b<<"\n\n";

        cout<<"\n============================= 4 =============================\n";
        foo(c2);    

        cout<<"\n============================= 5 =============================\n";
        cube c4 = foo();
        c4.cube_name = "cube_c4\0";

        cout<<"\n============================= 6 =============================\n";
        cube c5 = c4;
        c5.cube_name = "cube_c5\0";

        cout<<"\n....................All are now going to be deleted.....................\n";
        return 0;
    }