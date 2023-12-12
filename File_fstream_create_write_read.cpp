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
#include <fstream>

using namespace std;

int main()
{

	fstream file_obj;  // Creation of fstream class object

	string line;

	// file_obj.open("sample.txt") by default openmode = ios::in|ios::out mode
	// Automatically overwrites the content of file, 
    //To append the content, open in ios:app file_obj.open("sample.txt", ios::in | ios::out | sios::app)
	// ios::trunc mode delete all content before open
	file_obj.open("sample.txt", ios::trunc | ios::out | ios::in);

	if(file_obj.is_open()) //if(!file_obj) can also use to check open file error
        cout<<"File opened successfully to write and read\n";
    else
		{
			cout<<"Error to Open File !!!";
			exit(1);
		}

	while(file_obj) //
    {
		getline(cin, line);
		if (line == "-1")
			break;
		file_obj << line << endl;
	}
	
	file_obj.seekg(0, ios::beg);// point read pointer at beginning of file
    int i;
	while (file_obj) 
    {
        i++;
		getline(file_obj, line);    // Read a Line from File
		cout <<i <<". " << line << endl;   // Print line in Console
	}
	file_obj.close();

	return 0;
}
