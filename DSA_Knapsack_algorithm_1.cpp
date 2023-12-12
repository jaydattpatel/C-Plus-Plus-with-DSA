/*
Knapsack algorithm:

Profit and loss can be divisible.

The knapsack problem is a problem in combinatorial optimization (finding an optimal object from a finite set of objects). Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. It derives its name from the problem faced by someone who is constrained by a fixed-size knapsack and must fill it with the most valuable items.

*/

#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

void knapsack(int n,float weight[],float profit[],float capacity)
{
    float profitByWeight[n], totalProfit=0.0,totalWeight = 0.0;
    bool added[n];

    cout<<"ProfitByWeight: ";
    for(int i=0; i<n; i++)
    {
        profitByWeight[i]= profit[i]/weight[i]; 
        cout<<"  "<<profitByWeight[i];
        added[i] = false;
    }
            
    int cap = capacity;
    for(int i=0; i<n; i++)
        {
            float max = -99999;
            int pos = -1; 
            for(int i=0; i<n; i++)
                {
                    if((!added[i]) && weight[i]<=cap && profitByWeight[i] > max)
                    {
                        max = profitByWeight[i];
                        pos = i;
                    }
                }
            if(pos>=0)    
            {
                added[pos] = true;
                totalProfit = totalProfit + profit[pos];
                cap = cap - weight[pos];
                totalWeight = totalWeight + weight[pos];
                cout<<"\n["<<pos<<"] Add Profit : "<<setw(8)<<left<<profit[pos] 
                    <<setw(8)<<left<<"\tAdd Weight : "<< weight[pos];
            }
        }

    if(cap != 0)
        {
            float max = -99999;
            int pos = -1; 
            for(int i=0; i<n; i++)
                {
                    if((!added[i]) && cap<capacity && profitByWeight[i] > max)
                    {
                        max = profitByWeight[i];
                        pos = i;
                    }
                }

            if(pos>=0)    
            {
                added[pos] = true;
                
                totalProfit = totalProfit + (profitByWeight[pos] * (cap));
                totalWeight = totalWeight + cap;
                cout<<"\n["<<pos<<"] Add Profit : "
                    <<setw(8)<<left<<(profitByWeight[pos] * (cap))
                    <<setw(8)<<left<<"\tAdd Weight : "<< cap;
            }
        }

        
    cout<<"\n\nTotal Profit : "<<totalProfit <<"\t\tTotal Weight : "<< totalWeight;
    
}

int main()
{
    float profit[] = { 50, 100, 60, 120};
    float weight[] = { 40, 20, 10, 30};
    int size = sizeof(weight)/sizeof(weight[0]);
    cout<<"size: "<<size<<endl;
    float capacity = 50;
    knapsack(size,weight,profit,capacity);
    return 0;
}
