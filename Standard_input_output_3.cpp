//author: jaydattpatel
/*
Types of Manipulators There are various types of manipulators:

Manipulators without arguments: The most important manipulators defined by the IOStream library are provided below.
endl: It is defined in ostream. It is used to enter a new line and after entering a new line it flushes (i.e. it forces all the output written on the screen or in the file) the output stream.

ws: It is defined in istream and is used to ignore the whitespaces in the string sequence.

ends: It is also defined in ostream and it inserts a null character into the output stream. It typically works with std::ostrstream, when the associated output buffer needs to be null-terminated to be processed as a C string.

flush: It is also defined in ostream and it flushes the output stream, i.e. it forces all the output written on the screen or in the file. Without flush, the output would be the same, but may not appear in real-time.

*/

#include <iostream>
#include <istream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	istringstream str("		 Programmer");
	string line;
	// Ignore all the whitespace in string str before the first word.
	getline(str >> std::ws, line);

	// you can also write str>>ws
	//After printing the output it will automatically write a new line in the output stream.
	cout << line << endl;

	// without flush, the output will be the same.
	cout << "only a test" << flush;

	// Use of ends Manipulator
	cout << "\na";

	// NULL character will be added in the Output
	cout << "b" << ends;
	cout << "c" << endl;

	return 0;
}
