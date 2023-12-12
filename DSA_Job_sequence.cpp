// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit earned if job is completed before
				// deadline
};

// Custom sorting helper struct which is used for sorting all jobs according to profit
struct jobProfit {
	bool operator()(Job const& a, Job const& b)
	{
		return ((a.profit/a.dead) > (b.profit/b.dead));
	}
};

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
	vector<Job> result;
	sort(arr, arr + n, [](Job a, Job b) { return ((a.profit/a.dead) > (b.profit/b.dead)); });

	// set a custom priority queue
	priority_queue<Job, vector<Job>, jobProfit> pq;

	for (int i = n - 1; i >= 0; i--) 
    {
		int slot_available;
	
		// we count the slots available between two jobs
		if (i == 0) 
			slot_available = arr[i].dead;
		else 
			slot_available = arr[i].dead - arr[i - 1].dead;
	
		// include the profit of job(as priority), deadline and job_id in maxHeap
		pq.push(arr[i]);
		while (slot_available > 0 && pq.size() > 0) 
        {
			Job job = pq.top(); // get the job with the most profit
			pq.pop();
			slot_available--;   // reduce the slots
			result.push_back(job);  // add it to the answer
		}
	}

	// sort the result based on the deadline
	sort(result.begin(), result.end(), [&](Job a, Job b) { return (a.profit/a.dead) > (b.profit/b.dead); });

	// print the result
	for (int i = 0; i < result.size(); i++)
		cout << result[i].id << ' ';
	cout << endl;
}

// Driver's code
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs \n";

	// Function call
	printJobScheduling(arr, n);
	return 0;
}
