/*
Calculate postfix expression XY+Z*  = (X+Y)*Z answer
23+6* = (2+3)*6 = 30 
*/

#include<iostream>
#include<stdlib.h>
#include<conio.h>

#include<math.h>
#include<ctype.h>

const int MAX=50;
using namespace std;


class postfix
    {
        private:
            int stack[MAX];
            int top,m;
            char *s;

        public:
            postfix()
                { top=-1;};
            
            int evalute(char *str);
            void push(int item);
            int pop();
            void calculate();
            int show();
    };

int postfix::evalute(char *str)
{
    s = str;
    calculate();
    int result = show();
    return(result);
}


void postfix::push(int item)
{
    if(top==MAX-1)
        cout<<"Stack is full.";
    else
        {
            top++;
            stack[top]=item;
        }
}

int postfix::pop()
{
    if(top==-1)
        {
            cout<<"stack is empty.";
            return 0;
        }
    int data = stack[top];
    top--;
    return data;
}

void postfix::calculate()
{
    int n1,n2,n3;
    while(*s)
    {
        if(*s==' '|| *s=='\t')
            {
                s++;
                continue;
            }
        if(isdigit(*s))
            {
                m=*s-'0';
                cout<<"\npush() : "<<m;
                push(m);
            }
        else
            {
                n1=pop();
                n2=pop();
                switch(*s)
                {
                    case '+':   {n3=n2+n1;  break;}          
                    case '-':   {n3=n2-n1;   break;}
                    case '*':   {n3=n2*n1;   break;}        
                    case '/':   {n3=n2/n1;   break;}       
                    default:    {cout<<"Unknown operator";  exit(1);}                 
                }
                cout<<"\npop(n1) : "<<n1<<"\npop(n2) : "<<n2;
                cout<<"\n(n3=n1"<<*s<<"n2) : ("<<n3<<"="<<n1<<*s<<n2<<")";
                cout<<"\npush(n3) : "<<n3<<"\n";

                push(n3);
            }
        s++;
    }
}

int postfix::show()
    {
        m=pop();
        return(m);
    }

int main()
{
    char postfix_expression[MAX];
    cout<<"\nEnter the postfix expression to be evaluated:";
    cin.getline(postfix_expression,MAX);    //this function is used to get string from user with max length 
    postfix _postfix;
    cout<<"Result : "<< _postfix.evalute(postfix_expression);
    
}

