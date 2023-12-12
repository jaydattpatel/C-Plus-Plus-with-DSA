
#include <iostream>
using namespace std;    
/*
A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries. All identifiers at namespace scope are visible to one another without qualification. 
Code in header files should always use the fully qualified namespace name.


using fully qualified name for each identifier : (std::vector<std::string> vec;)
using Declaration for a single identifier (using std::string) 
using Directive for all the identifiers : (using namespace std;). 
*/

namespace Domain
{
    class class_A
    {
    public:
        void Do() {}
    };
    void Func(class_A) {}
}


int main ()
{

    //Use a using fully qualified name for each identifier:
    Domain::class_A obj1;
    obj1.Do();
    Domain::Func(obj1);

    //Use a using declaration to bring one identifier into scope:
    using Domain::class_A;
    class_A obj2;
    obj2.Do();

    //Use a using directive to bring everything in the namespace into scope:
    using namespace Domain;
    class_A obj3;
    obj3.Do();
    Func(obj3);

	return 0;
}
