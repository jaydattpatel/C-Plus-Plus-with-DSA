/*
Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.

This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

Priority queues are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

Member functions:
(constructor)	Construct priority queue (public member function)
empty	Test whether container is empty (public member function)
size	Return size (public member function)
top	Access top element (public member function)
push	Insert element (public member function)
emplace	Construct and insert element (public member function)
pop	Remove top element (public member function)
swap	Swap contents (public member function)

Non-member function overloads:
swap (queue)	Exchange contents of priority queues (public member function)

Non-member class specializations:
uses_allocator<queue>	Uses allocator for priority queue (class template)

*/
// C++ program to demonstrate the use of priority_queue
// C++ Program to demonstrate various
// method/function in Priority Queue
#include <iostream>
#include <queue>
using namespace std;

// Implementation of priority queue
void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;
	while (!g.empty()) 
	{
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}


int main()
{
	priority_queue<int> gquiz;
	// used in inserting the element
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(1);
	gquiz.push(20);
	gquiz.push(5);

	cout << "The priority queue gquiz is : ";
	
	// used for highlighting the element
	showpq(gquiz);

	// used for identifying the size of the priority queue
	cout << "\ngquiz.size() : " <<gquiz.size();
	// used for telling the top element in priority queue
	cout << "\ngquiz.top() : " <<gquiz.top();

	// used for poping the element from a priority queue
	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}
