//author: jaydattpatel
/*
iostream: iostream stands for standard input-output stream. This header file contains definitions of objects like cin, cout, cerr, etc.

iomanip: iomanip stands for input-output manipulators. The methods declared in these files are used for manipulating streams. This file contains definitions of setw, setprecision, etc.

fstream: This header file mainly describes the file stream. This header file is used to handle the data being read from a file as input or data being written into the file as output.

bits/stdc++: This header file includes every standard library. In programming contests, using this file is a good idea, when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive.
*/
#include <iostream>
using namespace std;

int main()
{
	char sample[] = "c++";
	cout << sample << " programs"<<endl;

    int age;
    cout << "Enter your age:";
    cin >> age;
    cout << "\nYour age is: " << age;

    cerr << "An error occurred\n";

    clog << "An logged statements\n";

    char ch[80];
	cin.getline(ch,80);
	cout << ch << endl;
	
	char c;
    while ((getchar()) != '\n')
	{
    	c = getchar();
    	printf("%c", c);
	}

	return 0;
}
