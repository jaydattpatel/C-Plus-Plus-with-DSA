/*
LIFO stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall support the following operations:

The standard container classes vector, deque and list fulfill these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.

Member functions:
(constructor)	Construct stack (public member function)
empty	Test whether container is empty (public member function)
size	Return size (public member function)
top	Access next element (public member function)
push	Insert element (public member function)
emplace	Construct and insert element (public member function)
pop	Remove top element (public member function)
swap	Swap contents (public member function)

Non-member function overloads:
relational operators	Relational operators for stack (function)
swap (stack)	Exchange contents of stacks (public member function)

Non-member class specializations:
uses_allocator<stack>	Uses allocator for stack (class template)

*/
#include <iostream>  
#include <stack>  
using namespace std;  
void newstack(stack <int> ss)  
{  
    stack <int> sg = ss;  
    while (!sg.empty())  
    {  
        cout << '\t' << sg.top();  
        sg.pop();  
    }  
    cout << '\n';  
}  
int main ()  
{  
    stack <int> newst;  
    newst.push(55);  
    newst.push(44);  
    newst.push(33);  
    newst.push(22);  
    newst.push(11);  
  
    cout << "The stack newst is : ";  
    newstack(newst);  
    cout << "\n newst.size() : " << newst.size();  
    cout << "\n newst.top() : " << newst.top();  
    cout << "\n newst.pop() : ";  
    newst.pop();  
    newstack(newst);   
    return 0;  
}  