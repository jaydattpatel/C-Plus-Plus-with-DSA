// author: jaydattpatel
/*
Modifiers: 

assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
*/

#include <iostream>
#include <vector>
#include <string.h>
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
	cout << "\nVector int_list elements are: ";
	for (auto x : *int_list) //here loop will created x variable copy value of array one by one.
		cout << x << " ";
}

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

int main()
{
	// Assign vector
	vector<int> int_list;
	vector<char> char_list;
	vector<structure> structure_list;
	vector<class_c> class_list;

	cout<<"\n\n---------------------------int_list---------------------------------------\n";

	// fill the array with 10 five times
	int_list.assign(5, 10);
	cout<<"\n\n\nAfter int_list.assign(5, 10) : ";
	display(&int_list);

	for(int i=0;i<int_list.size();i++)
		int_list[i] = int_list[i] + i;
	cout<<"\n\n\nAfter changing elements : ";
	display(&int_list);

	// inserts 15 to the last position
	int_list.push_back(15);
	cout << "\n\n\nAfter int_list.push_back(15): ";
	display(&int_list);

	// removes last element
	int_list.pop_back();
	cout<<"\n\n\nAfrer removes last element pop_back():";
	display(&int_list);

	int_list.insert(int_list.begin(), 9);	
	cout << "\n\n\nAfter insert element in begining int_list.insert(int_list.begin(), 9): "; 
	display(&int_list);

	int_list.insert((int_list.begin()+3), 50);	
	cout << "\n\n\nAfter insert element in 3rd position from begining int_list.insert((int_list.begin()+3), 50): "; 
	display(&int_list);

	int_list.insert(int_list.end(), 15);
	cout << "\n\n\nAfter insert element in endining int_list.insert(int_list.end(), 15): ";
	display(&int_list);
	
	int_list.erase(int_list.begin());	// removes the first element
	cout << "\n\n\nAfter erase element in begining int_list.erase(int_list.begin()): ";
	display(&int_list);

	int_list.erase((int_list.begin()+2));	// removes the first element
	cout << "\n\n\nAfter erase element in 2nd position from begining int_list.erase((int_list.begin()+2)): ";
	display(&int_list);

	int_list.emplace(int_list.begin(), 5);
	cout << "\n\n\nAfter emplace element in begining int_list.emplace(int_list.begin(), 5): ";
	display(&int_list);

	int_list.emplace((int_list.begin()+3), 4);
	cout << "\n\n\nAfter emplace element in 3rd position from begining int_list.emplace((int_list.begin()+3), 4): ";
	display(&int_list);

	// Inserts 20 at the end
	int_list.emplace_back(20);
	cout << "\n\n\nAfter emplace_back element in end  int_list.emplace_back(20): ";
	display(&int_list);

	// erases the vector
	int_list.clear();
	cout << "\n\n\nAfter clear(), Vector size after erase(): " << int_list.size();
	display(&int_list);

	// two vector to perform swap
	cout<<"\n\n----SWAP function-----\n";
	vector<int> int_v1, int_v2;
	for(int i=1; i<=5; i++)
		int_v1.push_back(i);
	for(int i=6; i<=10; i++)
		int_v2.push_back(i);

	cout<<"\nint_v1 vector:";
	display(&int_v1);
	cout<<"\nint_v2 vector:";
	display(&int_v2);

	// Swaps int_v1 and int_v2
	int_v1.swap(int_v2);

	cout << "\n\n\nAfter Swap int_v1.swap(int_v2) : ";
	cout<<"\nint_v1 vector:";
	display(&int_v1);
	cout<<"\nint_v2 vector:";
	display(&int_v2);

	cout<<"\n\n---------------------------char_list---------------------------------------\n";
	// fill the array with 'R' five times
	char_list.assign(5, 'R');
	cout<<"\n\n\nAfter char_list.assign(5, 'R') : ";
	display(&char_list);

	for(auto &x : char_list)
	{
		static int qq = 65;
		x = qq;
		qq++;
	}
	cout<<"\n\n\nAfter changing elements : ";
	display(&char_list);

	char_list.push_back('U');
	cout << "\n\n\nAfter char_list.push_back('U')";
	display(&char_list);

	// removes last element
	char_list.pop_back();
	cout<<"\n\n\nAfrer removes last element pop_back():";
	display(&char_list);

	char_list.insert(char_list.begin(), 'X');	
	cout << "\n\n\nAfter insert element in begining char_list.insert(char_list.begin(), 'X'): "; 
	display(&char_list);

	char_list.insert((char_list.begin()+3), 'Q');	
	cout << "\n\n\nAfter insert element in begining char_list.insert((char_list.begin()+3), 'Q'): "; 
	display(&char_list);

	char_list.insert(char_list.end(), 'V');
	cout << "\n\n\nAfter insert element in endining char_list.insert(char_list.end(), 'V'): ";
	display(&char_list);
	
	char_list.erase(char_list.begin());	// removes the first element
	cout << "\n\n\nAfter erase element in begining char_list.erase(char_list.begin()): ";
	display(&char_list);

	char_list.erase((char_list.begin()+2));	// removes the first element
	cout << "\n\n\nAfter erase element in 2nd position from begining char_list.erase((char_list.begin()+2)): ";
	display(&char_list);

	char_list.emplace(char_list.begin(), 'Y');
	cout << "\n\n\nAfter emplace element in begining char_list.emplace(char_list.begin(), 'Y'): ";
	display(&char_list);

	char_list.emplace((char_list.begin()+3), 'H');
	cout << "\n\n\nAfter emplace element in 3rd positon from begining char_list.emplace((char_list.begin()+3), 'H'): ";
	display(&char_list);


	char_list.emplace_back('Z');
	cout << "\n\n\nAfter emplace_back element in end  char_list.emplace_back('Z'): ";
	display(&char_list);

	// erases the vector
	char_list.clear();
	cout << "\n\n\nAfter clear(), Vector size after erase(): " << char_list.size();
	display(&char_list);

	// two vector to perform swap
	cout<<"\n\n----SWAP function-----\n";
	vector<char> char_v1, char_v2;
	for(int i=65; i<=70; i++)
		char_v1.push_back(i);
	for(int i=71; i<=75; i++)
		char_v2.push_back(i);

	cout<<"\nchar_v1 vector:";
	display(&char_v1);
	cout<<"\nchar_v2 vector:";
	display(&char_v2);

	// Swaps char_v1 and char_v2
	char_v1.swap(char_v2);

	cout << "\n\n\nAfter Swap char_v1.swap(char_v2) : ";
	cout<<"\nchar_v1 vector:";
	display(&char_v1);
	cout<<"\nchar_v2 vector:";
	display(&char_v2);

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

	cout<<"\n\n\nAfter changing elements : ";
	display(&structure_list);

	// removes last element
	structure_list.pop_back();
	cout<<"\n\n\nAfrer removes last element pop_back():";
	display(&structure_list);
	
	structure_list.erase(structure_list.begin());	// removes the first element
	cout << "\n\n\nAfter erase element in begining structure_list.erase(structure_list.begin()): ";
	display(&structure_list);

	// erases the vector
	structure_list.clear();
	cout << "\n\n\nAfter clear(), Vector size after erase(): " << structure_list.size();
	display(&structure_list);

	// two vector to perform swap
	cout<<"\n\n----SWAP function-----\n";
	vector<structure> structure_v1, structure_v2;
		for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			structure *st = new structure;
			structure *st1 = new structure;

			(*st).aa = num;
			(*st1).aa = num+10;
			sprintf((*st).bb,"struct-%d",(*st).aa);
			sprintf((*st1).bb,"struct-%d",(*st1).aa);

			structure_v1.push_back(*st);
			structure_v2.push_back(*st1);
		};

	cout<<"\n\nstructure_v1 vector:";
	display(&structure_v1);
	cout<<"\n\nstructure_v2 vector:";
	display(&structure_v2);

	// Swaps structure_v1 and structure_v2
	structure_v1.swap(structure_v2);

	cout << "\n\n\nAfter Swap structure_v1.swap(structure_v2) : ";
	cout<<"\n\nstructure_v1 vector:";
	display(&structure_v1);
	cout<<"\n\nstructure_v2 vector:";
	display(&structure_v2);

	cout<<"\n\n---------------------------class_list---------------------------------------\n";

	for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			class_c *cc = new class_c;
			(*cc).dd = num;
			sprintf((*cc).ee,"struct-%d",(*cc).dd);
			class_list.push_back(*cc);
		};

	cout<<"\n\n\nAfter changing elements : ";
	display(&class_list);

	// removes last element
	class_list.pop_back();
	cout<<"\n\n\nAfrer removes last element pop_back():";
	display(&class_list);
	
	class_list.erase(class_list.begin());	// removes the first element
	cout << "\n\n\nAfter erase element in begining class_list.erase(class_list.begin()): ";
	display(&class_list);

	// erases the vector
	class_list.clear();
	cout << "\n\n\nAfter clear(), Vector size after erase(): " << class_list.size();
	display(&class_list);

	// two vector to perform swap
	cout<<"\n\n----SWAP function-----\n";
	vector<class_c> class_v1, class_v2;
		for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			class_c *st = new class_c;
			class_c *st1 = new class_c;

			(*st).dd = num;
			(*st1).dd = num+10;
			sprintf((*st).ee,"class-%d",(*st).dd);
			sprintf((*st1).ee,"class-%d",(*st1).dd);

			class_v1.push_back(*st);
			class_v2.push_back(*st1);
		};

	cout<<"\n\nclass_v1 vector:";
	display(&class_v1);
	cout<<"\n\nclass_v2 vector:";
	display(&class_v2);

	// Swaps class_v1 and class_v2
	class_v1.swap(class_v2);

	cout << "\n\n\nAfter Swap class_v1.swap(class_v2) : ";
	cout<<"\n\nclass_v1 vector:";
	display(&class_v1);
	cout<<"\n\nclass_v2 vector:";
	display(&class_v2);
}
