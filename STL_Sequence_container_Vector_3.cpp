// author: jaydattpatel
/*
Element access:

reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
at(g) – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector
data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
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
		int_list.push_back(i * 10);
	display(&int_list);
	cout << "\n\nint_list[2] = " << int_list[2];
	cout << "\nint_list.at(4) = " << int_list.at(4);
	cout << "\nint_list.front() = " << int_list.front();
	cout << "\nint_list.back() = " << int_list.back();

	// pointer to the first element
	int* p_int = int_list.data();  // *(int_list.data()) you can also use this
	cout << "\n(int* p_int = int_list.data()) The first element: " << *p_int<<"\t\t*(int_list.data()) :"<<*(int_list.data());

	cout<<"\n\n---------------------------char_list---------------------------------------\n";
	for (int i = 65; i <=70; i++)
		char_list.push_back(i);
	display(&char_list);
	cout << "\n\nchar_list[2] = " << char_list[2];
	cout << "\nchar_list.at(4) = " << char_list.at(4);
	cout << "\nchar_list.front() = " << char_list.front();
	cout << "\nchar_list.back() = " << char_list.back();

	// pointer to the first element
	char* p_char = char_list.data();  // *(char_list.data()) you can also use this
	cout << "\n(char* p_char = char_list.data())  The first element is : " << *p_char<<"\t\t*(char_list.data()) :"<<*(char_list.data());

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

	display(&structure_list);
	cout << "\n\nstructure_list[2].aa = " << structure_list[2].aa<<", \tstructure_list[2].bb = "<<structure_list[2].bb;
	cout << "\nstructure_list.at(4).aa = " << structure_list.at(4).aa<<", \tstructure_list.at(4).bb = "<<structure_list.at(4).bb;
	cout << "\nstructure_list.front().aa = " << structure_list.front().aa<<", \tstructure_list.front().bb = "<<structure_list.front().bb;
	cout << "\nstructure_list.back() = " << structure_list.back().aa<<", \tstructure_list.back().bb = "<<structure_list.back().bb;

	// pointer to the first element
	structure *p_struct = structure_list.data();  // *(structure_list.data()) you can also use this
	cout << "\n(structure *p_struct = structure_list.data())  The first element is: ";
	cout<<"\n\t\tp_struct->aa :" << p_struct->aa<<"\t\t\t(structure_list.data()->aa) : "<<(structure_list.data()->aa);
	cout<<"\n\t\tp_struct->bb :" << p_struct->bb<<"\t\t(structure_list.data()->bb) : "<<(structure_list.data()->bb);


	cout<<"\n\n---------------------------class_list---------------------------------------\n";
	for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			class_c *cc = new class_c;
			(*cc).dd = num;
			sprintf((*cc).ee,"class-%d",(*cc).dd);
			class_list.push_back(*cc);
		};

	display(&class_list);
	cout << "\n\nclass_list[2].dd = " << class_list[2].dd<<", \tclass_list[2].ee = "<<class_list[2].ee;
	cout << "\nclass_list.at(4).dd = " << class_list.at(4).dd<<", \tclass_list.at(4).ee = "<<class_list.at(4).ee;
	cout << "\nclass_list.front().dd = " << class_list.front().dd<<", \tclass_list.front().ee = "<<class_list.front().ee;
	cout << "\nclass_list.back() = " << class_list.back().dd<<", \tclass_list.back().ee = "<<class_list.back().ee;

	// pointer to the first element
	class_c *p_class = class_list.data();  // *(class_list.data()) you can also use this
	cout << "\n(class_c *p_class = class_list.data())  The first element is: ";
	cout<<"\n\t\tp_class->dd :" << p_class->dd<<"\t\t\t(class_list.data()->dd) : "<<(class_list.data()->dd);
	cout<<"\n\t\tp_class->ee :" << p_class->ee<<"\t\t(class_list.data()->ee) : "<<(class_list.data()->ee);

	return 0;
}
