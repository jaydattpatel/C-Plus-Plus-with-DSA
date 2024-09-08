// author: jaydattpatel
// C++ program to find the min and max element of Array using sort() in STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Get the array
	int arr[] = { 1, 45, 54, 71, 76, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Find the minimum element
	cout << "\nMin Element = "
		<< *min_element(arr, arr + n);

	// Find the maximum element
	cout << "\nMax Element = "
		<< *max_element(arr, arr + n);
	// Storing the pointer in an address
	int &min = *min_element(arr,arr+n );
	int &max = *max_element(arr,arr+n );
    
	cout<<"\nFinding the Element using address variable";
	cout<<"\nMin Element = "<<min;
	cout<<"\nMax Element = "<<max;
	return 0;
}
