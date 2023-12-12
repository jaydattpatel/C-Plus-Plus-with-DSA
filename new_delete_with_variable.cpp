// author: jaydattpatel
#include<iostream>
using namespace std;


int main()
    {
        // new key word is used to allocate memory in Heap and return pointer
        //pointer-variable = new data-type[size];

        int *ip = new int ;
        char *cp = new char;
        float *fp = new float;

        

        *ip = 10;
        *cp = 'C';
        *fp = 3.14;
        cout<<"*ip: "<<*ip<<endl;
        cout<<"*cp: "<<*cp<<endl;
        cout<<"*fp: "<<*fp<<endl;

        int *ip1 = new int(15) ;
        char *cp1 = new char('H');
        float *fp1 = new float(23.55);
        cout<<"*ip1: "<<*ip1<<endl;
        cout<<"*cp1: "<<*cp1<<endl;
        cout<<"*fp1: "<<*fp1<<endl;

        delete(ip);delete(ip1);
        delete(cp);delete(cp1);
        delete(fp);delete(fp1);

        return 0;
    }