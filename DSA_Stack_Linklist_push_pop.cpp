// author: jaydattpatel
#include <iostream>
using namespace std;
// Creating a node
struct node 
{
  int value;
  struct node *next;
};

typedef struct node NODE;

class linkedlist_stack
{
    private:
        NODE *start;
    public:
        linkedlist_stack()
        {
            start = NULL;
        }
        void push();
        void pop();
        void display();
};

void linkedlist_stack::push()
    {   
        int a;
        cout<<"\nEnter Value:";   
        cin>>a;
        NODE *newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->value = a;
        newnode->next = start;
        start = newnode;
    };

void linkedlist_stack::pop()
    {   
        NODE *top = start;
        if(start == NULL)
            {
                cout<<"\nStack is Empty !! Deletion not possible";
                return;
            }
        else
            {
                cout<<"The deleted elements: "<<start->value<<endl;
                start = top->next;
                free(top);
            }
    };

void linkedlist_stack::display()
    {
        NODE *top = start;
        if(start == NULL)
            {cout<<"\nStack is Empty !!";}
        else
            {
                cout<<"\nElements are: ";
                while(top != NULL)
                    {
                        cout<<"\t"<<top->value;    
                        top = top->next;
                    }  
            }
    };

int main()
{
    int value,choice;
    linkedlist_stack l_stk;
    while(1)
    {
        cout<<"\n\n\n-----------Stack using linkedlist -------------";
        cout<<"1.Push\t2.Pop\t3.Display\t4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:{l_stk.push();       break;}
            case 2:{l_stk.pop();        break;}
            case 3:{l_stk.display();    break;}
            case 4:{exit(0);}
            default:{cout<<"\nFunction Terminated.";  exit(0);}
        }
    } 
    return(0);
}