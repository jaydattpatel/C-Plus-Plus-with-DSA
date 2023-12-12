// author: jaydattpatel
#include<iostream>
using namespace std;

class distance_feet_inches
{
    private:
        int feet;
        float inches;
    public:
        void getdist() //input length from user
            {
                cout<< "enter feet:";
                cin>>feet;
                cout<<"enter inches:";
                cin>>inches;
            }
        void printdist() // print the distance_feet_inches
            {
                cout<< feet << "\' "<< inches <<"\" "<<endl;
            }
};

int main()
{
    distance_feet_inches D; //define a named distance_feet_inches object
    D.getdist();
    D.printdist();
    distance_feet_inches *dptr; //pointer to distance_feet_inches class
    dptr = new distance_feet_inches; //points to new distance_feet_inches object
    dptr->getdist(); // points to new distance_feet_inches object
    dptr->printdist(); //access object members with -> operator
    return 0;
} 