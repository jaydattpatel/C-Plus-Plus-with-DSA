/*
// CPP Program to implement Deque in STL

deque (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

Specific libraries may implement deques in different ways, generally as some form of dynamic array. But in any case, they allow for the individual elements to be accessed directly through random access iterators, with storage handled automatically by expanding and contracting the container as needed.

(constructor)	Construct deque container (public member function)
(destructor)	Deque destructor (public member function)
operator=	Assign content (public member function)

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
size	Return size (public member function)
max_size	Return maximum size (public member function)
resize	Change size (public member function)
empty	Test whether container is empty (public member function)
shrink_to_fit	Shrink to fit (public member function)

Element access:
operator[]	Access element (public member function)
at	Access element (public member function)
front	Access first element (public member function)
back	Access last element (public member function)

Modifiers:
assign	Assign container content (public member function)
push_back	Add element at the end (public member function)
push_front	Insert element at beginning (public member function)
pop_back	Delete last element (public member function)
pop_front	Delete first element (public member function)
insert	Insert elements (public member function)
erase	Erase elements (public member function)
swap	Swap content (public member function)
clear	Clear content (public member function)
emplace	Construct and insert element (public member function)
emplace_front	Construct and insert element at beginning (public member function)
emplace_back	Construct and insert element at the end (public member function)

Allocator:
get_allocator	Get allocator (public member function)

*/
#include <iostream>
#include <deque>
using namespace std;

class A{
	public:
		int x;
};

void showdq(deque<A> g)
{
	deque<A>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << it->x;
	cout << '\n';
}

int main()
{
	deque<A> dq1,dq2;
	A obj_A;
	obj_A.x = 10;	dq1.push_front(obj_A);
	obj_A.x = 20;	dq1.push_front(obj_A);
	obj_A.x = 30;	dq1.push_back(obj_A);
	obj_A.x = 15;	dq1.push_back(obj_A);
	cout << "The deque dq1 is : ";
	showdq(dq1);

	cout << "dq2.erase(dq1.begin()+2) : ";
	dq1.erase(dq1.begin()+2);
	showdq(dq1);

	cout << "\ndq1.size() : " << dq1.size();
	cout << "\ndq1.max_size() : " << dq1.max_size();
	obj_A.x = 30;
	cout << "\ndq1.front() : " << dq1.front().x;
	cout << "\ndq1.back() : " << dq1.back().x;
	
	obj_A.x = 45;	dq2.push_front(obj_A);
	obj_A.x = 70;	dq2.push_front(obj_A);
	obj_A.x = 90;	dq2.push_back(obj_A);
	obj_A.x = 50;	dq2.push_back(obj_A);
	
	dq2.erase(dq2.begin()+2);

	cout << "The deque dq2 is : ";
	showdq(dq2);


	cout<<"\n-----After swap:\n";
	dq1.swap(dq2);
	cout << "The deque dq1 is : ";
	showdq(dq1);
	cout << "The deque dq2 is : "; 
	showdq(dq2);


	cout << "\ndq1.pop_front() : ";
	dq1.pop_front();
	showdq(dq1);

	cout << "\ndq1.pop_back() : ";
	dq1.pop_back();
	showdq(dq1);
	obj_A.x = 9999;
	dq1.insert((dq1.begin()+1),obj_A);
	cout << "\ndq1.insert((dq1.begin()+1),12) : ";
	showdq(dq1);

	cout<<"\nDeque with pair of objects :\n";
	deque<pair<A,A>> Dq_pairA;
	pair<A,A> P;

	A a1,a2;
	for(int i = 0; i<3; i++ )
	{
		a1.x = i+1;
		a2.x = (i+1)*10;
		P.first = a1;
		P.second = a2;
		Dq_pairA.push_back(P);
	}

	for(int i = 0; i<3; i++ )
	{
		cout<<"\t("<<Dq_pairA[i].first.x<<", "<<Dq_pairA[i].second.x<<")";
	}
	return 0;
}
