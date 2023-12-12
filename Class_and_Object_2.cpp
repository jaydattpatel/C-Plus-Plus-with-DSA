// author: jaydattpatel
#include<iostream>
using namespace std;    //std::cout<<"sample";  we do not require to use "std::" duting program 

class Employee
{
    public: 
    
    string name;    int salary;
    Employee(string n, int s, int sp)
        {   this->name = n;     this->salary = s;   this->secretPassword = sp;  }

    void printDetails()
        {   cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << " Dollars" << endl;  }

    void getSecretPassword()
        {   cout<<"The secret password of employee is "<<this->secretPassword;  }

    private:    
    
    int secretPassword;
};

class Programmer : public Employee
{   public: int errors;       };


int main()
{

    Employee rahul("Rahul Verma", 529, 324432);     // rahul.name = "Rahul Verma"; rahul.salary = 100;
    rahul.printDetails();
    rahul.getSecretPassword();
    
    /* cout<<rahul.secretPassword;  Private varible can not use in program so error will show*/

    return(0);
}