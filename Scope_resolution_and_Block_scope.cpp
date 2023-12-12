// author: jaydattpatel
#include<iostream>
using namespace std;

int glob = 7;
void print()
{
    cout<<"print() :"<<glob<<endl;
}

class X
{
public:
      static int count;
};
int X::count = 10;                // define static data member count of class X.

int main()
    {
        cout<<"-------\"::\" Globle scope resolution --------------\n";

        int glob = 5;
        cout<<"Local glob : "<<glob<<endl;       // "first find "glob" variable in Local if it is found then it will take local varibale otherwise it will take globle variable 
        print();

        cout<<"(::globe) : "<<::glob<<endl; // "::" you can use scope resolution to use globle varible due to same name of variables.

        int X = 0;                  // hides class type X
        cout << "X::count : "<<X::count << endl;   // use static member of class X
        cout << X << endl;


        int m = 123;
        cout<<"-------\"{}\" Block scope --------------\n";
        cout << "main m: " << m << endl;
        {
            int m = 1;
            cout << "{inner m}: " << m << endl;
            {
                int m = 2;
                cout << "{{inner of inner m}}: " << m << endl;            
            }
            cout << "{inner m}: " << m << endl;
        }
        cout << "main m: " << m << endl;


        cout<<"-------\"{}\" Block scope (If or If else if else ) --------------\n";
        cout << "main m: " << m << endl;
        if(1)
        {
            int m = 3;
            cout << "{inner m}: " << m << endl;
            {
                int m = 4;
                cout << "{{inner of inner m}}: " << m << endl;            
            }
            cout << "{inner m}: " << m << endl;
        }
        else
        {
            int m = 5;
            cout << "{inner m}: " << m << endl;
            {
                int m = 6;
                cout << "{{inner of inner m}}: " << m << endl;            
            }
            cout << "{inner m}: " << m << endl;
        }
        cout << "main m: " << m << endl;


        cout<<"-------\"{}\" Block scope(for loop) --------------\n";
        cout << "main m: " << m << endl;
        {
            int m = 7;
            cout << "{inner m}: " << m << endl;
            {   
                int m=8;
                cout << "{{inner of inner m}}: " << m << endl; 
                for(int m=0;m<2;m++)
                            {
                                cout<<"{{{inner of inner of inner m}}}: "<<m<<endl;
                            }
                cout << "{{inner of inner m}}: " << m << endl;            
            }
            cout << "{inner m}: " << m << endl;
        }
        cout << "main m: " << m << endl;
        

        cout<<"-------\"{}\" Block scope(while or do while loop) --------------\n";
        cout << "main m: " << m << endl;
        {
            int m = 9;
            cout << "{inner m}: " << m << endl;
            {
                int m=0;
                while(m<10)
                        m++;
                cout << "{{inner of inner m}}: " << m << endl;            
            }
            cout << "{inner m}: " << m << endl;
        }
        cout << "main m: " << m << endl;





        
        return 0;
    }