// author: jaydattpatel
#include <iostream>
using namespace std;    
/*std::cout<<"sample";  we do not require to use "std::" duting program and function
also we can define specific for pertical namespace for perticular function like
using std::cout;
using std::cin;
using std::endl;
For all "std::" not required if we use "using namespace std;"
*/

// first name space
namespace first_space
{
    void func()
    {
    	cout << "first_space" << endl;
    }
    // second name space
    namespace second_space
    {
    	void func()
    	{
    		cout << "second_space" << endl;
    	}
    }
}

// third name space
namespace third_space
{
    void func()
    {
    	cout << "third_space" << endl;
    }
}
namespace third_space::forth_space
{
    void func()
    {
    	cout << "forth_space" << endl;
    }
}

/*    
using namespace first_space;    //using this name func() work as first space name in main program
using namespace first_space::second_space;  //using this name func() work as second space name of first space name in main program
using namespace third_space;    //using this name func() work as third space name in main program
using namespace third_space::forth_space;   // using this name func() work as forth space name of third space name in main program

*/

// Creating a namespace
namespace ns
{
    void display()  // this function also can define outside by void ns::display(){code}
        {
            cout << "ns::display()\n";
        }
    class geek
        {
            public:
            void display()      // this function also can define outside by void ns::geek::display(){code}
            {
                cout << "ns::geek::display()\n";
            }
        };
}
//using namespace ns; If we use this we dont neet to write "ns::" in program. also it is possible to define that you want to write or not "ns::" for individual function and class of perticular namespace.
 
int main ()
{

    first_space::func();	// Calls function from first name space.
    first_space::second_space::func();   // Calls function from second name space.
    third_space::func();   // Calls function from third name space.
    third_space::forth_space::func();   // Calls function from third name space.
    
    //using namespace ns; If we use this we dont neet to write "ns::" in program

    ns::geek obj;   // defining object obj of class geek. 
    ns::display();  // call function display() of namespace ns
    obj.display();  // call function display() of class of namespace ns
	return 0;
}
