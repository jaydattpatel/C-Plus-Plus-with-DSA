// author: jaydattpatel
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long int MaxPairwiseProduct(const vector<int>& numbers) 
{
    long int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) 
    {
        for (int second = first + 1; second < n; ++second) 
        {
            if((numbers[first] * numbers[second])>max_product)
                max_product = (long int)numbers[first] * (long int)numbers[second];
        }
    }

    return max_product;
}



int main() 
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
