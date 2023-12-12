/*
author: jaydattpatel
Conversion from premitive basic to class type

Implicit Type Conversion: Also known as ‘automatic type conversion.
Done by the compiler on its own, without any external trigger from the user.

Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.

*/

#include <iostream>
using namespace std;

// Time Class
class Time {
	int hour;
	int mins;

public:
	// Default Constructor
	Time()
	{
		hour = 0;
		mins = 0;
	}

	//defination to convert int premitive to class type
	Time(int t)
	{
		hour = t / 60;
		mins = t % 60;
	}

	void Display()
	{
		cout << "Time = " << hour
			<< " hrs and "
			<< mins << " mins\n";
	}
};

int main()
{
	
	Time T1;
	int dur = 95;

	T1 = dur;   // Conversion of int type to class type

	T1.Display();

	return 0;
}
