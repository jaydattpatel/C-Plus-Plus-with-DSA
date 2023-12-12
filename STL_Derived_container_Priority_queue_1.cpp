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
#include <iostream>
#include <queue>
using namespace std;

// driver code
int main()
{
	int arr[6] = { 10, 2, 4, 8, 6, 9 };
	// printing array
	cout << "Array: ";
	for (auto i : arr) 
		cout << i << ' ';
	cout << endl;

	// defining priority queue
	priority_queue<int> pq;

	// pushing array sequentially one by one
	for (int i = 0; i < 6; i++) 
		pq.push(arr[i]);
	

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) 
	{
		cout<< pq.top() << ' ';
		pq.pop();
		
	}

	return 0;
}
