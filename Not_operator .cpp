// author: jaydattpatel
#include <iostream>
using namespace std;

int isnull(int *a)
{
    return (!a);
}

int main()
{
    int x = 10, *a ,*b = NULL;
    a = &x;
    if(isnull(a))
            cout<<"\n a is null ";
    else
            cout<<"\n a is not null";
    cout<<"\n a :"<<a<<"\n !a :"<<!a;

    if(isnull(b))
            cout<<"\n b is null";
    else
            cout<<"\n b is not null";
    cout<<"\n b :"<<b<<"\n !b :"<<!b;
    return 0;
}
