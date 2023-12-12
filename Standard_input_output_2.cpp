//author: jaydattpatel
//file handling with stream buffer using standard input output of library
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream file;
	file.open("cout.txt", ios::out);
	string line;
	 
	streambuf* stream_buffer_cout = cout.rdbuf(); // streambuffers of cout
	streambuf* stream_buffer_cin = cin.rdbuf(); // streambuffers of cin

	streambuf* stream_buffer_file = file.rdbuf(); // Get the streambuffer of the file

	cout.rdbuf(stream_buffer_file); // Redirect cout to file
	cout << "This line written to file" << endl; //this will write string into the file

	cin.rdbuf(stream_buffer_file); // Redirect in to file
	cin>>line; //this will read string from the file
	
	cout.rdbuf(stream_buffer_cout); // Redirect cout back to screen
    cout<<"File:"<<line;
	cout << "This line is written to screen" << endl; //this string will be written to screen

	file.close();
	return 0;
}
