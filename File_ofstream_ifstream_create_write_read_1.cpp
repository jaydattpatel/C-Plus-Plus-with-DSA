// author: jaydattpatel
/* File Handling with C++ using fstream class object To write the Content in File Then to read the content of file
-----------------------------------------------------------------
fstream:	It is used to create files, write information to files, and read information from files.
ifstream:	It is used to read information from files.
ofstream:	It is used to create files and write information to the files.
----------------------------------------------------------------
ios::in - 	    (Open for input operations.)
ios::out -	(Open for output operations.)
ios::binary -	(Open in binary mode.)
ios::ate -	(Set the initial position at the end of the file. If this flag is not set, the initial position is the beginning of the file.)
ios::app -	(All output operations are performed at the end of the file, appending the content to the current content of the file.)
ios::trunc -	(If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.)
---------------------------------------------------------------
class       default mode parameter
ofstream	ios::out
ifstream	ios::in
fstream	    ios::in | ios::out
*/
#include <iostream>
#include <fstream> //fstream header file for ifstream, ofstream, fstream classes
using namespace std;

int main()
{
	string line;
	ofstream file_out_obj; // Creation of ofstream class object

	file_out_obj.open("sample.txt");	//file_out_obj.open("sample.txt",ios::out)
	// file_out_obj.open("sample.txt")by default ios::out mode, automatically deletes
	// file_out_obj.open("sample.txt", ios::app) the content of file. To append the content

	if(file_out_obj.is_open()) //if(!file_out_obj) can also use to check open file error
        cout<<"File opened successfully to write\n";
    else 
		{
			cout<<"Error to Open File !!!";
			exit(1);
		}
	cout<<"write multiple string and -1 to terminate:\n";
	while (file_out_obj) 
		{
			getline(cin, line); // Read a Line from standard input
			if (line == "-1") // Press -1 to exit
				break;
			file_out_obj << line << endl;
		}
	file_out_obj.close();

	
	ifstream file_in_obj; // Creation of ifstream class object to read the file
	
	file_in_obj.open("sample.txt"); //file_in_obj.open("sample.txt",ios::in)
	//file_in_obj.open("sample.txt") by default open mode = ios::in mode
    if(file_in_obj.is_open())
        cout<<"File opened successfully to read\n";
    else 
    	{
			cout<<"Error to Open File !!!";
			exit(1);
		}

	int i;
	while (getline(file_in_obj, line))// Execute a loop until EOF (End of File)
		{
			i++;
			cout<<i <<". "<< line << endl;
		}
	file_in_obj.close();

	return 0;
}
