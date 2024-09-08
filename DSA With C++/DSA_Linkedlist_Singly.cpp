// author: jaydattpatel
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
    {
        int data;
        struct node *link;
    };

class linkedlist
{
    private:
    struct node *head_end;

    public:
    linkedlist()
    {
        head_end = NULL;
        cout<<"\nCreating new node. Do you want to enter data (y/n) ? ";

        char ch;
        cin>>ch;
        if(('y'== ch) || ('Y' == ch))
            {
                while(('y'== ch) || ('Y' == ch))
                {
                    insertAtRear_push();
                    cout<<"\n\nDo you want to enter more data (y/n) ? ";
                    cin>>ch;
                }
            }
    }
    void insertAtFront();
    void insertAtRear_push();
    void insertBefore(); 
    void insertAfter();
    void deleteAtFront();
    void deleteAtRear_pop();
    void deleteValue();
    void traversal();
};


void linkedlist::insertAtFront()
    {
        struct node *ptr = new struct node;
        
        if(ptr == NULL){
            cout<<"\n\nMemory Overflow !!!"<<endl;
            return;
        }
        int data;
        cout<<"Enter data: ";
        cin>>data;
        ptr->data = data;
        ptr->link = NULL;
        if(head_end == NULL)
        {
            head_end = ptr;
        }
        else
        {
            struct node *goFirst;
            goFirst = head_end;
            while(goFirst->link != NULL)
                goFirst = goFirst->link;
            goFirst->link = ptr;
        }
        traversal();

    }


void linkedlist::insertAtRear_push()
    {
        struct node *ptr = new struct node;
        if(ptr == NULL){
            cout<<"\n\nMemory Overflow !!!"<<endl;
            return;
        }
        int data;
        cout<<"Enter data: ";
        cin>>data;
        ptr->data = data;
        ptr->link = head_end;
        head_end = ptr;
        traversal();
    }

void linkedlist::insertBefore()
    {
        if(head_end == NULL)
        {
            cout<<"\n\nData undeflow !! please insert data !!\n";
            return;
        }
        struct node *newptr = new struct node;
        struct node *temp = NULL, *previous = NULL;
        if(newptr == NULL){
            cout<<"Memory Overflow !!!"<<endl;
            return;
        }
        int data,compare_value;
        cout<<"Enter value to compare to insert after: "<<endl;
        cin>>compare_value;

        temp = head_end;
        while(temp != NULL)
        {
            if(temp->data == compare_value)
                {
                    cout<<"Enter data to add: "<<endl;
                    cin>>data;
                    newptr->data = data;
                    newptr->link = temp;
                    if(previous != NULL)
                        previous->link = newptr;
                    else
                        head_end = newptr;
                    traversal();
                    return;
                }
            previous = temp;
            temp = temp->link;
            
        }
        cout<<"\n\nValue Not Found !! "<<endl;
    }


void linkedlist::insertAfter()
    {
        if(head_end == NULL)
        {
            cout<<"\n\nData undeflow !! please insert data !!\n";
            return;
        }
        struct node *ptr = new struct node;
        struct node *temp, *temp2;
        if(ptr == NULL){
            cout<<"\n\nMemory Overflow !!!"<<endl;
            return;
        }
        int data,compare_value;
        cout<<"Enter value to compare to insert after: "<<endl;
        cin>>compare_value;

        temp = head_end;
        while(temp != NULL)
        {
            if(temp->data == compare_value)
                {
                    cout<<"Enter data to add: "<<endl;
                    cin>>data;
                    ptr->data = data;
                    temp2 = temp->link;
                    ptr->link = temp2;
                    temp->link = ptr;
                    traversal();
                    return;
                }
            temp = temp->link;
            
        }
        cout<<"\n\nValue Not Found !! "<<endl;
    }

void linkedlist::deleteAtFront()
    {
        if(head_end == NULL)
            {
                cout<<"\n\nData underflow !! Nothing to delete !!\n";
                return;
            }
        if(head_end->link == NULL)
            {
                delete(head_end);
                head_end = NULL;
            }
        else
            {
                struct node *goFirst,*second;
                goFirst = head_end;    
                while(goFirst->link != NULL)
                    {
                        second = goFirst;
                        goFirst = goFirst->link;
                    }
                second->link = NULL;
                delete(goFirst);
            }
        traversal();
    }
void linkedlist::deleteAtRear_pop()
{
        if(head_end == NULL)
        {
            cout<<"\n\nData underflow !! Nothing to delete !!\n";
            return;
        }
        if(head_end->link == NULL)
            {
                delete(head_end);
                head_end = NULL;
            }
        else
            {
                struct node *temp;
                temp = head_end;
                head_end = head_end->link;    
                delete(temp);
            }
        traversal();
}

void linkedlist::deleteValue()
{
        if(head_end == NULL)
        {
            cout<<"\n\nData underflow !! Nothing to delete !!\n";
            return;
        }

        int compare_value;
        cout<<"Enter value to delete: "<<endl;
        cin>>compare_value;

        struct node *temp,*previous = NULL,*next = NULL;
        temp = head_end;
        while(temp != NULL)
        {
            if(temp->data == compare_value)
                { 
                    if(temp->link != NULL)
                            next = temp->link;
                    if(previous != NULL)
                        previous->link = next;
                    else
                        head_end = next;
                    delete(temp);
                    traversal();
                    return;
                }
            previous = temp;
            temp = temp->link;
            
        }
        cout<<"\n\nValue Not Found !! "<<endl;
        
}

void linkedlist::traversal()
    {
        struct node *ptr = head_end;
        cout<<"\n\nElement:"<<endl;
        cout<<"Rear <<\t";
        while (ptr != NULL)
        {
            cout<<ptr->data<<"\t";
            ptr = ptr->link;
        }
        cout<<" << Front";

    }


int main()
{

    int choice;
    linkedlist ll;
    while(1)
    {
        cout<<"\n--------------------Menu ---------------------------";
        cout<<"\n1.Insert At Front\t2.Insert At Rear_push\t3.Insert Before\t\t4.Inset After\n";
        cout<<"5.Delete At Front\t6.Delete At Rear_pop\t7.Delete Value\t\t8.Display\n";
        cout<<"\tEnter Other to termimane process\n";
        cout<<"----------------------------------------------------\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: { ll.insertAtFront();       break; }
            case 2: { ll.insertAtRear_push();       break; }
            case 3: { ll.insertBefore();      break; }
            case 4: { ll.insertAfter();    break;}
            case 5: { ll.deleteAtFront();       break; }
            case 6: { ll.deleteAtRear_pop();       break; }
            case 7: { ll.deleteValue();    break;}
            case 8: { ll.traversal();    break;}
            default:{printf("\nFunction Terminated.");   exit(0);}
        }
    }
     return 0;
}