// author: jaydattpatel
#include <iostream>

#define MAXSTK 10
using namespace std;

class stack
    {   private:
            int stk[MAXSTK], top;

        public:
            stack()
                {
                    top = -1;
                }
            void push();
            void pop();
            void display();
    };


void stack::push()
    {
        if(top >= (MAXSTK-1))
            {cout<<"\nStack is Full !! Insertion not possible";}
        else
            {   int value;
                cout<<"\nEnter Value:";   
                cin>>value;
                top++;  
                stk[top] = value;   
                cout<<"\nInsertion Successfull !!";
            }
    };
void stack::pop()
    {   
        if(top == -1)   
            {cout<<"\nStack is Empty !! Deletion not possible";}
        else
            {
                cout<<"\nDeleted : "<<stk[top]; 
                stk[top] = 0;   
                top--;
            }
    };

void stack::display()
    {
        if(top == -1)   
            {cout<<"\nStack is Empty !!";}
        else
            {
                int i;
                cout<<"\nStack Elements are :\n ";
                for(i=top;i>=0;i--)
                    cout<<stk[i]<<"\t";      
            }
    };

int main()
{
    int value,choice;
    stack stk;
    while(1)
    {
        cout<<"\n\n\n-----------Stack using array -------------";
        cout<<"\n1.Push\t2.Pop\t3.Display\t4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:{stk.push();     break;}  
            case 2:{stk.pop();      break;}
            case 3:{stk.display();  break;}
            case 4:{exit(0);}
            default:{cout<<"\nFunction Terminated.";   exit(0);}
        }
    } 
    return(0);
}