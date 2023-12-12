/*
Find Power Set
*/
#include <iostream>
#include <math.h>
using namespace std;

// Function to print all the power set
void printPowerSet(char* set, int set_size)
{
	// Set_size of power set of a set with set_size n is (2^n-1)
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	// Run from counter 000..0 to 111..1
	for (counter = 0; counter < pow_set_size; counter++) {
		for (j = 0; j < set_size; j++) {
			if (counter & (1 << j))
				cout << set[j];
		}
		cout << endl;
	}
}


int main()
{
	char set[] = { 'A', 'B', 'C' ,'D'};
	printPowerSet(set, 4);
	return 0;
}

