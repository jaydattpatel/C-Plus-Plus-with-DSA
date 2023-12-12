#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void display(vector<int> *int_list)
{
	cout << "\nVector int_list elements are: ";
	for (auto x : *int_list) //here loop will created x variable copy value of array one by one.
		cout << x << " ";
}
/*
void display(vector<char> *char_list)
{
	cout << "\nVector char_list elements are: ";
	for (auto x : *char_list) //here loop will created x variable copy value of array one by one.
		cout << x << " ";
}

void display(vector<structure> *structure_list)
{
	cout << "\nVector structure_list elements are: ";
	for (auto x : *structure_list) //here loop will created x variable copy value of array one by one.
		x.show();
}

void display(vector<class_c> *class_list)
{
	cout << "\nVector class_list elements are: ";
	for (auto x : *class_list) //here loop will created x variable copy value of array one by one.
		x.show();
}
*/
int main()
{
	vector<int> int_list;
    for (int i = 1; i <= 5; i++)
		int_list.push_back(i);
        
	cout << "\n\nloop for(auto x : int_list), you will not see any 99 value in array because x has copy of value of that element.";
	for (auto x : int_list) //here loop will created x variable copy value of all elements one by one.
		x = 99;  // this will not directly change the value of element because x has copy of value of that element.
	display(&int_list);

	cout << "\n\nloop for(auto &x : int_list), you will see all value become 99 in array because x has address of that element: ";
	for (auto &x : int_list) //here loop will created x variable copy address of all element one by one.
		x = 99;  // this will directly change the value of element because x has address of that element.
	display(&int_list);

	cout << "\n\nloop for(const auto &x : int_list), it doesn't make any temporary copies.They are read-only, because marked const ";
	for (const auto &x : int_list) //here loop will created x variable copy address of all element one by one.
	{
		//x = 99;   // This line would cause an error:
	};
	display(&int_list);
    return(0);
}