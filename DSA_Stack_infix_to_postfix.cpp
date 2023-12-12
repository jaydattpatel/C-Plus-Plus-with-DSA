#include<iostream>
#include<string.h>
using namespace std;

#define NULL 0

int top=-1;
char stack[100]={NULL};

void push(const char symbol)
{
    if(top==99)
    cout<<"Stack is full.\n";
    else
    {
        top++;
        stack[top]=symbol;
    }
}

const char pop()
{
    char symbol = NULL;
    if(top==-1)
    cout<<"Stack is empty\n";
    else
    {
        symbol=stack[top];
        stack[top]=NULL;
        top--;
    }
    return symbol;
}
void infix_to_postfix(const char *Infix)
{
    char in_exp[100]={NULL};
    char post_exp[100]={NULL};
    strcpy(in_exp,"(");
    strcat(in_exp,Infix);
    strcat(in_exp,")");
    char symbol[5]={NULL};
    char temp[5]={NULL};
    for(int count=0;count<strlen(in_exp);count++)
    {
        symbol[0] = in_exp[count];
        if(symbol[0]=='(')
            push(symbol[0]);
        else if(symbol[0]==')')
            {
                symbol[0]=pop();
                while(symbol[0]!='(')
                {
                    strcat(post_exp,symbol);
                    symbol[0]=pop();
                }
            }
        else if(symbol[0]=='*' || symbol[0]=='/' || symbol[0]=='+' || symbol[0]=='-')
            {
                if(symbol[0]=='*' || symbol[0]=='/')
                    {
                        temp[0]=pop();
                        while(temp[0]=='*' || temp[0]=='/')
                            {
                                strcat(post_exp,temp);
                                temp[0]=pop();
                            }
                            push(temp[0]);
                    }

                else if(symbol[0]=='+' || symbol[0]=='-')
                    {
                        temp[0]=pop();
                        while(temp[0] != '(')
                            {
                                strcat(post_exp,temp);
                                temp[0]=pop();
                            }
                            push(temp[0]);
                    }
                push(symbol[0]);
            }
        else
            {
                strcat(post_exp,symbol);
            }
    }
    cout<<"\n\nPostfix Expression :"<<post_exp<<endl;
}

int main()
{
    char in_exp[100]={NULL};
    cout<<"\n\nEnter the Infix Expression:";
    cin.getline(in_exp,80);
    infix_to_postfix(in_exp);
    return 0;
}
