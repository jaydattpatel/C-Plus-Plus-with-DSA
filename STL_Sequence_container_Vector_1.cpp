// author: jaydattpatel
/*
begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/

// iterators in vector
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


int main()
{
	vector<int> int_list;
	vector<char> char_list;
	vector<structure> structure_list;
	vector<class_c> class_list;


	cout<<"\n\n---------------------------int_list---------------------------------------\n";

	for (int i = 1; i <= 5; i++)
		int_list.push_back(i);

	cout << "\nint_list Output of begin and end: ";
	for (auto i = int_list.begin(); i != int_list.end(); ++i)
		cout << *i << " ";

	cout << "\n\nint_list Output of cbegin and cend: ";
	for (auto i = int_list.cbegin(); i != int_list.cend(); ++i)
		cout << *i << " ";

	cout << "\n\nint_list Output of rbegin and rend: ";
	for (auto i = int_list.rbegin(); i != int_list.rend(); ++i)
		cout << *i << " ";

	cout << "\n\nint_list Output of crbegin and crend : ";
	for (auto i = int_list.crbegin(); i != int_list.crend(); ++i)
		cout << *i << " ";

	
	cout<<"\n\n---------------------------char_list---------------------------------------\n";

	for (int i = 65; i <= 70; i++)
		char_list.push_back(i);

	cout << "\nchar_list Output of begin and end: ";
	for (auto i = char_list.begin(); i != char_list.end(); ++i)
		cout << *i << " ";

	cout << "\n\nchar_list Output of cbegin and cend: ";
	for (auto i = char_list.cbegin(); i != char_list.cend(); ++i)
		cout << *i << " ";

	cout << "\n\nchar_list Output of rbegin and rend: ";
	for (auto i = char_list.rbegin(); i != char_list.rend(); ++i)
		cout << *i << " ";

	cout << "\n\nchar_list Output of crbegin and crend : ";
	for (auto i = char_list.crbegin(); i != char_list.crend(); ++i)
		cout << *i << " ";



	cout<<"\n\n---------------------------structure_list---------------------------------------\n";

	for (int i = 1; i <= 5; i++)
		{
			static int num = 0;
			num++;
			structure *st = new structure;
			(*st).aa = num;
			sprintf((*st).bb,"struct-%d",(*st).aa);
			structure_list.push_back(*st);
		}

	cout << "\nstructure_list Output of begin and end: ";
	for (auto i = structure_list.begin(); i != structure_list.end(); ++i)
		cout <<"\naa: "<<(*i).aa <<"\tbb: "<<(*i).bb<<"";

	cout << "\n\nstructure_list Output of cbegin and cend: ";
	for (auto i = structure_list.cbegin(); i != structure_list.cend(); ++i)
		cout <<"\naa: "<<(*i).aa <<"\tbb: "<<(*i).bb<<"";

	cout << "\n\nstructure_list Output of rbegin and rend: ";
	for (auto i = structure_list.rbegin(); i != structure_list.rend(); ++i)
		cout <<"\naa: "<<(*i).aa <<"\tbb: "<<(*i).bb<<"";

	cout << "\n\nstructure_list Output of crbegin and crend : ";
	for (auto i = structure_list.crbegin(); i != structure_list.crend(); ++i)
		cout <<"\naa: "<<(*i).aa <<"\tbb: "<<(*i).bb<<"";


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

		cout << "\nclass_list Output of begin and end: ";
	for (auto i = class_list.begin(); i != class_list.end(); ++i)
		cout <<"\naa: "<<(*i).dd <<"\tbb: "<<(*i).ee<<"";

	cout << "\n\nclass_list Output of cbegin and cend: ";
	for (auto i = class_list.cbegin(); i != class_list.cend(); ++i)
		cout <<"\naa: "<<(*i).dd <<"\tbb: "<<(*i).ee<<"";

	cout << "\n\nclass_list Output of rbegin and rend: ";
	for (auto i = class_list.rbegin(); i != class_list.rend(); ++i)
		cout <<"\naa: "<<(*i).dd <<"\tbb: "<<(*i).ee<<"";

	cout << "\n\nclass_list Output of crbegin and crend : ";
	for (auto i = class_list.crbegin(); i != class_list.crend(); ++i)
		cout <<"\naa: "<<(*i).dd <<"\tbb: "<<(*i).ee<<"";

	return 0;
}
