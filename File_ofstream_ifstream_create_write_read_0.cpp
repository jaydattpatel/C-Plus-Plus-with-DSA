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
#include<iostream>
#include<fstream> 
#include<string.h>
using namespace std;

int main() 
{ 
    ofstream file_out_obj("sample.txt");
    char str[]= "Hello world";

    if(file_out_obj.is_open())
        cout<<"File opened successfully to write\n";
    else 
    	{
			cout<<"Error to Open File !!!";
			exit(1);
		}
    
    file_out_obj.write(str,strlen(str));    //write string
    file_out_obj.close();

//---------------------------------------------------------------
    ifstream file_in_obj("sample.txt");

    if(file_in_obj.is_open())
        cout<<"File opened successfully to read\n";
    else 
    	{
			cout<<"Error to Open File !!!";
			exit(1);
		}
    char c[100];

    file_in_obj.read(c,100);    //to read string as per length
    cout<<c;
    
    file_in_obj.close();

    return(0);

}

