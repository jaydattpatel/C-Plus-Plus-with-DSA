/*
CPP program to show the implementation of List
List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations.

(constructor)	Construct list (public member function)
(destructor)	List destructor (public member function)
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
empty	Test whether container is empty (public member function)
size	Return size (public member function)
max_size	Return maximum size (public member function)

Element access:
front	Access first element (public member function)
back	Access last element (public member function)

Modifiers:
assign	Assign new content to container (public member function)
emplace_front	Construct and insert element at beginning (public member function)
push_front	Insert element at beginning (public member function)
pop_front	Delete first element (public member function)
emplace_back	Construct and insert element at the end (public member function)
push_back	Add element at the end (public member function)
pop_back	Delete last element (public member function)
emplace	Construct and insert element (public member function)
insert	Insert elements (public member function)
erase	Erase elements (public member function)
swap	Swap content (public member function)
resize	Change size (public member function)
clear	Clear content (public member function)

Operations:
splice	Transfer elements from list to list (public member function)
remove	Remove elements with specific value (public member function)
remove_if	Remove elements fulfilling condition (public member function template)
unique	Remove duplicate values (public member function)
merge	Merge sorted lists (public member function)
sort	Sort elements in container (public member function)
reverse	Reverse the order of elements (public member function)

Observers:
get_allocator	Get allocator (public member function)
*/


#include <iostream> 
#include <list> 
#include <iterator>
#include <algorithm>
using namespace std; 

int main( int argc, char *argv[] ) 
{ 
    string things[] = { "JAF", "ROB", "PHIL", "ELLIOTT", "ANDRZEJ" }; 
    const int N = sizeof(things)/sizeof(things[0]); 

    list<string> ll; 
    list<string>::iterator iter; 

    for ( int i = 0; i < N; ++i) 
        ll.push_back( things[i] ); 
    

    for ( iter = ll.begin(); iter != ll.end(); ++iter ) 
        cout << *iter << endl; 
    // Find "ELLIOTT" 
    cout << "\nNow look for ELLIOTT" << endl; 
    iter = find( ll.begin(), ll.end(), "ELLIOTT" ); 
    // Mary should be ahead of Elliott 
    if ( iter != ll.end() )
        { 
            cout << "\nInsert MARY before ELLIOTT" << endl; 
            ll.insert( iter, "MARY" ); 
        } 
    else 
        { 
            cout << "\nCouldn't find ELLIOTT" << endl; 
        } 
    for ( iter = ll.begin(); iter != ll.end(); ++iter ) 
        cout << *iter << endl; 
    return( EXIT_SUCCESS ); 
} 