/*
 A Naive recursive implementation of 0-1 Knapsack problem 
 Profit and loss can not divisible.
*/
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity capacity
int knapSack(int capacity, int weight[], int val[], int n)
{

	if (n == 0 || capacity == 0)
	{
		cout<<"return \n";
		return 0;
	}
	// If weight of the nth item is more than Knapsack capacity capacity, then this item cannot be included in the optimal solution
	cout<<"knapSack ( "<< capacity <<" ,\t "<< weight[n-1]<<" ,\t "<< val[n-1] <<" ,\t "<< n-1<<" ) \n";
	if (weight[n - 1] > capacity)
	{
		cout<<"If: \n";
		return knapSack(capacity, weight, val, n - 1);
	}

	// Return the maximum of two cases: (1) nth item included (2) not included
	else
	{
		cout<<"else: \n";
		return max(val[n - 1] + (knapSack(capacity - weight[n - 1], weight, val, n - 1)),(knapSack(capacity, weight, val, n - 1)));
	}
}

int main()
{
	int capacity = 50;
	int value[] = { 50, 100, 60, 120};
	int weight[] = { 40, 20, 10, 30};
	int n = sizeof(value) / sizeof(value[0]);
	cout <<"knapSack ( capacity, weight, val, n ) \n" <<knapSack(capacity, weight, value, n);
	return 0;
}

