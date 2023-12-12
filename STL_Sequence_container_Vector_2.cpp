// author: jaydattpatel
/*
size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the container so that i contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct structure
{
	public:
		int aa;
		char bb[20];
		void show()
		{
			cout<<"\naa: "<<aa<<"\t\tbb : "<<bb; 
		}
}; 

class class_c
{
	public:
		int dd;
		char ee[20];
		void show()
		{
			cout<<"\ndd: "<<dd<<"\t\tee : "<<ee;
		}
}; 

void display(vector<int> *int_list)
{
	cout << "\nSize : "<<(*int_list).size()<<"\tCapacity : "<<(*int_list).capacity()<<"\tMax_Size : " << (*int_list).max_size();
	cout << "\nVector int_list elements are: ";
	for (auto x : *int_list) //here loop will created x variable copy value of array one by one.
		cout << x << " ";
}

void display(vector<char> *char_list)
{
	cout << "\nSize : "<<(*char_list).size()<<"\tCapacity : "<<(*char_list).capacity()<<"\tMax_Size : " << (*char_list).max_size();
	cout << "\nVector char_list elements are: ";
	for (auto x : *char_list) //here loop will created x variable copy value of array one by one.
		cout << x << " ";
}

void display(vector<structure> *structure_list)
{
	cout << "\nSize : "<<(*structure_list).size()<<"\tCapacity : "<<(*structure_list).capacity()<<"\tMax_Size : " << (*structure_list).max_size();
	cout << "\nVector structure_list elements are: ";
	for (auto x : *structure_list) //here loop will created x variable copy value of array one by one.
		x.show();
}

void display(vector<class_c> *class_list)
{
	cout << "\nSize : "<<(*class_list).size()<<"\tCapacity : "<<(*class_list).capacity()<<"\tMax_Size : " << (*class_list).max_size();
	cout << "\nVector class_list elements are: ";
	for (auto x : *class_list) //here loop will created x variable copy value of array one by one.
		x.show();
}


int main()
{
	vector<int> int_list;
	vector<char> char_list;
	vector<structure> structure_list;
	vector<class_c> class_list;

	cout<<"\n\n---------------------------int_list---------------------------------------\n";
	for (int i = 1; i <= 5; i++)
		int_list.push_back(i);

	// checks if the vector is empty or not
	if (int_list.empty() == false)
		cout << "\nint_list Vector is not empty\n";
	else
		cout << "\nint_list Vector is empty\n";
	display(&int_list);

	// Shrinks the vector
	int_list.shrink_to_fit();
	cout << "\n\n\nint_list After Shrink_to_fit():";
	display(&int_list);

	// resizes the vector size to 3
	int_list.resize(3);
	cout << "\n\n\nint_list After resize(3):";
	display(&int_list);

	cout<<"\n\n---------------------------char_list---------------------------------------\n";
	for (int i = 65; i <= 70; i++)
		char_list.push_back(i);

	// checks if the vector is empty or not
	if (char_list.empty() == false)
		cout << "\nchar_list Vector is not empty\n";
	else
		cout << "\nchar_list Vector is empty\n";
	display(&char_list);

	// Shrinks the vector
	char_list.shrink_to_fit();
	cout << "\n\n\nchar_list After Shrink_to_fit():";
	display(&char_list);

	// resizes the vector size to 3
	char_list.resize(3);
	cout << "\n\n\nchar_list After resize(3):";
	display(&char_list);

	cout<<"\n\n---------------------------structure_list---------------------------------------\n";
	for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			structure *st = new structure;
			(*st).aa = num;
			sprintf((*st).bb,"struct-%d",(*st).aa);
			structure_list.push_back(*st);
		};

	// checks if the vector is empty or not
	if (structure_list.empty() == false)
		cout << "\nstructure_list Vector is not empty\n";
	else
		cout << "\nstructure_list Vector is empty\n";
	display(&structure_list);

	// Shrinks the vector
	structure_list.shrink_to_fit();
	cout << "\n\n\nstructure_list After Shrink_to_fit():";
	display(&structure_list);

	// resizes the vector size to 3
	structure_list.resize(3);
	cout << "\n\n\nstructure_list After resize(3):";
	display(&structure_list);

	cout<<"\n\n---------------------------class_list---------------------------------------\n";
	for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			class_c *cc = new class_c;
			cc->dd = num;
			sprintf((*cc).ee,"class-%d",(*cc).dd);
			class_list.push_back(*cc);
		}

	// checks if the vector is empty or not
	if (class_list.empty() == false)
		cout << "\nclass_list Vector is not empty\n";
	else
		cout << "\nclass_list Vector is empty\n";
	display(&class_list);

	// Shrinks the vector
	class_list.shrink_to_fit();
	cout << "\n\n\nclass_list After Shrink_to_fit():";
	display(&class_list);

	// resizes the vector size to 3
	class_list.resize(3);
	cout << "\n\n\nclass_list After resize(3):";
	display(&class_list);

	return 0;
}
