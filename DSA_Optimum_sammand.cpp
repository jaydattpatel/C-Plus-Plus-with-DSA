
#include <iostream>
#include <vector>
using namespace std;

vector<int> optimal_summands(int n) 
{
    vector<int> summands;
    
    for (int i = 1; i <= n; i++) 
        {
            n -= i;
            cout<<"\nn: "<<n<<"\ti: "<<i;
            if (n <= i) 
                summands.push_back(n + i);
            else if (n == 0) 
                {
                    summands.push_back(i);
                    break;
                } 
            else 
                summands.push_back(i);
        }
    cout<<"\n";
    return summands;
}

int main() 
{
    int n;
    cout<<"Enter Integer: ";
    cin >> n;
    vector<int> summands = optimal_summands(n);

    cout <<"Total no.:" << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) 
        cout << summands[i] << ' ';

}
