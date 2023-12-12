/*
In a multiset, the value of an element also identifies it (the value is itself the key, of type T). The value of the elements in a multiset cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

Internally, the elements in a multiset are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

multiset containers are generally slower than unordered_multiset containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

Multisets are typically implemented as binary search trees.

Member functions:
(constructor)	Construct multiset (public member function)
(destructor)	Multiset destructor (public member function)
operator=	Copy container content (public member function)

Iterators:
begin	Return iterator to beginning (public member function)
end	Return iterator to end (public member function)
rbegin	Return reverse iterator to reverse beginning (public member function)
rend	Return reverse iterator to reverse end (public member function)
cbegin	Return const_iterator to beginning (public member function)
cend	Return const_iterator to end (public member function)
crbegin	Return const_reverse_iterator to reverse beginning (public member function)
crend	Return const_reverse_iterator to reverse end (public member function)

Capacity:
empty	Test whether container is empty (public member function)
size	Return container size (public member function)
max_size	Return maximum size (public member function)

Modifiers:
insert	Insert element (public member function)
erase	Erase elements (public member function)
swap	Swap content (public member function)
clear	Clear content (public member function)
emplace	Construct and insert element (public member function)
emplace_hint	Construct and insert element with hint (public member function)

Observers:
key_comp	Return comparison object (public member function)
value_comp	Return comparison object (public member function)

Operations:
find	Get iterator to element (public member function)
count	Count elements with a specific key (public member function)
lower_bound	Return iterator to lower bound (public member function)
upper_bound	Return iterator to upper bound (public member function)
equal_range	Get range of equal elements (public member function)

Allocator:
get_allocator	Get allocator (public member function)

*/
// CPP Program to demonstrate the implementation of multiset
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// empty multiset container
	multiset<int, greater<int> > quiz1;

	// insert elements in random order
	quiz1.insert(40);
	quiz1.insert(30);
	quiz1.insert(60);
	quiz1.insert(20);
	quiz1.insert(50);

	// 50 will be added again to the multiset unlike set
	quiz1.insert(50);
	quiz1.insert(10);

	// printing multiset quiz1
	multiset<int, greater<int> >::iterator itr;
	cout << "\nThe multiset quiz1 is : \n";
	for (itr = quiz1.begin(); itr != quiz1.end(); ++itr) 
		cout << *itr << " ";
	cout << endl;

	// assigning the elements from quiz1 to quiz2
	multiset<int> quiz2(quiz1.begin(), quiz1.end());

	// print all elements of the multiset quiz2
	cout << "\nThe multiset quiz2 after assign from quiz1 is : \n";
	for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
		cout << *itr << " ";
	cout << endl;

	// remove all elements up to element with value 30 in quiz2
	cout << "\ngquiz2 after removal of elements less than 30 : \n";
	quiz2.erase(quiz2.begin(), quiz2.find(30));
	for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
		cout << *itr << " ";
	
	// remove all elements with value 50 in quiz2
	int num;
	num = quiz2.erase(50);
	cout << "\ngquiz2.erase(50) : "<< num << "elements removed \n";
	for (itr = quiz2.begin(); itr != quiz2.end(); ++itr) 
		cout << *itr << " ";
	cout << endl;

	// lower bound and upper bound for multiset quiz1
	cout << "\nquiz1.lower_bound(40) : "<< *quiz1.lower_bound(40) << endl;
	cout << "quiz1.upper_bound(40) : "<< *quiz1.upper_bound(40) << endl;

	// lower bound and upper bound for multiset quiz2
	cout << "\ngquiz2.lower_bound(40) : "<< *quiz2.lower_bound(40) << endl;
	cout << "quiz2.upper_bound(40) : "<< *quiz2.upper_bound(40) << endl;

	return 0;
}
