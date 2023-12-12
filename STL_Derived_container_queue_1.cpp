/*
Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front. Queues use an encapsulated object of deque or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.

Member functions:
(constructor)	Construct queue (public member function)
empty	Test whether container is empty (public member function)
size	Return size (public member function)
front	Access next element (public member function)
back	Access last element (public member function)
push	Insert element (public member function)
emplace	Construct and insert element (public member function)
pop	Remove next element (public member function)
swap	Swap contents (public member function)

Non-member function overloads:
relational operators	Relational operators for queue (function)
swap (queue)	Exchange contents of queues (public member function)

Non-member class specializations:
uses_allocator<queue>	Uses allocator for queue (class template)
*/

// CPP code to illustrate Queue operations in STL
#include <iostream>
#include <queue>
using namespace std;

void print_queue(queue<int> q)
{
	queue<int> temp = q;
	while (!temp.empty()) {
		cout << temp.front()<<" ";
		temp.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << "The first queue is : ";
	print_queue(q1);
	
	queue<int> q2;
	q2.push(4);
	q2.push(5);
	q2.push(6);
	cout << "The second queue is : ";
	print_queue(q2);
	
	
	q1.swap(q2);
		
	cout << "After swapping, the first queue is : ";
	print_queue(q1);
	cout << "After swapping the second queue is : ";
	print_queue(q2);

	
	q1.pop();
	q2.pop();
    cout << "After pop, the first queue is : ";
    print_queue(q1);
	cout << "After po, the second queue is : ";
    print_queue(q2);
	
	cout<<q1.empty(); //returns false since q1 is not empty

	return 0;
}
