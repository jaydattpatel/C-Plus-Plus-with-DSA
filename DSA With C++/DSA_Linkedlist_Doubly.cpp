// author: jaydattpatel
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
    {
        int data;
        struct node *previous;
        struct node *next;
    };
class linkedlist
{
    private:
        struct node *head;

    public:
        linkedlist()        //when new object created head of that object make NULL. this is called constructor
        {
            head = NULL;
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
        ptr->previous = NULL;
        ptr->next = NULL;
        if(head == NULL)
            head = ptr;
        else
        {
            struct node *goFirst;
            goFirst = head;
            while(goFirst->next != NULL)
                goFirst = goFirst->next;
            goFirst->next = ptr;
            ptr->previous = goFirst;
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
        ptr->previous = NULL;
        ptr->next = NULL;
        cout<<"Enter data: ";
        cin>>data;
        ptr->data = data;
        if(head == NULL)
                head = ptr;
        else
            {
                ptr->next = head;
                head->previous = ptr;
                head = ptr;
            }
        traversal();
    }

void linkedlist::insertBefore()
    {
        if(head == NULL)
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
        newptr->previous = NULL;
        newptr->next = NULL;
        cout<<"Enter value to compare to insert after: "<<endl;
        cin>>compare_value;

        temp = head;
        while(temp != NULL)
        {
            if(temp->data == compare_value)
                {
                    cout<<"Enter data to add: "<<endl;
                    cin>>data;
                    newptr->data = data;
                    
                    newptr->next = temp;
                    temp->previous = newptr;
                    if(previous != NULL)
                    {
                        previous->next = newptr;
                        newptr->previous = previous;
                    }
                    else
                        head = newptr;
                    traversal();
                    return;
                }
            previous = temp;
            temp = temp->next;  
        }
        cout<<"\n\nValue Not Found !! "<<endl;
    }


void linkedlist::insertAfter()
    {
        if(head == NULL)
        {
            cout<<"\n\nData undeflow !! please insert data !!\n";
            return;
        }
        struct node *ptr = new struct node;
        struct node *temp, *next;
        if(ptr == NULL){
            cout<<"\n\nMemory Overflow !!!"<<endl;
            return;
        }
        int data,compare_value;
        cout<<"Enter value to compare to insert after: "<<endl;
        cin>>compare_value;

        temp = head;
        while(temp != NULL)
        {
            if(temp->data == compare_value)
                {
                    cout<<"Enter data to add: "<<endl;
                    cin>>data;
                    ptr->data = data;

                    ptr->previous = temp;
                    if(temp->next != NULL)
                    {
                        next = temp->next;
                        ptr->next = next; 
                        temp->next = next->previous = ptr;
                    }
                    else
                    {
                       temp->next = ptr; 
                       ptr->next = NULL; 
                    }
                    traversal();
                    return;
                }
            temp = temp->next;  
        }
        cout<<"\n\nValue Not Found !! "<<endl;
    }

void linkedlist::deleteAtFront()
    {
        if(head == NULL)
            {
                cout<<"\n\nData underflow !! Nothing to delete !!\n";
                return;
            }
        if(head->next == NULL && head->previous == NULL)
            {
                delete(head);
                head = NULL;
            }
        else
            {
                struct node *goFirst,*previous;
                goFirst = head;    
                while(goFirst->next != NULL)
                    {
                        previous = goFirst;
                        goFirst = goFirst->next;
                    }
                previous->next = NULL;
                delete(goFirst);
            }
        traversal();
    }
void linkedlist::deleteAtRear_pop()
    {
            if(head == NULL)
            {
                cout<<"\n\nData underflow !! Nothing to delete !!\n";
                return;
            }
            if(head->next == NULL && head->previous == NULL)
                {
                    delete(head);
                    head = NULL;
                }
            else
                {
                    struct node *temp;
                    temp = head;
                    head = head->next;
                    head->previous = NULL;    
                    delete(temp);
                }
            traversal();
    }

void linkedlist::deleteValue()
    {
            if(head == NULL)
            {
                cout<<"\n\nData underflow !! Nothing to delete !!\n";
                return;
            }

            int compare_value;
            cout<<"Enter value to delete: "<<endl;
            cin>>compare_value;

            struct node *temp,*previous = NULL,*next = NULL;
            temp = head;
            while(temp != NULL)
            {
                if(temp->data == compare_value)
                    { 
                        next = temp->next;
                        previous = temp->previous;
                        if(next != NULL)
                            {
                                if(previous != NULL)
                                {
                                    previous->next = next;
                                    next->previous = previous;
                                }
                                else
                                {
                                    next->previous = NULL;
                                    head = next;
                                }
                            }
                        else
                            {
                                if(previous != NULL)
                                    previous->next = NULL; 
                                else
                                    head = NULL;
                            }
                        
                        delete(temp);
                        traversal();
                        return;  
                    }
                temp = temp->next;    
            }
            cout<<"\n\nValue Not Found !! "<<endl;
            
    }

void linkedlist::traversal()
    {
        struct node *ptr = head;
        cout<<"\nElement:"<<endl;
        cout<<"Forward: ";
        cout<<"Rear << \t";
        while (ptr != NULL)
        {
            cout<<ptr->data<<"\t";
            if(ptr->next == NULL)
                break;
            ptr = ptr->next;
        }
        cout<<" << Front";

        cout<<"\nReverse: ";
        cout<<"Front <<\t";
        while (ptr != NULL)
        {
            cout<<ptr->data<<"\t";
            if(ptr->previous == NULL)
                break;
            ptr = ptr->previous;
        }
        cout<<" << Rear";

    }


int main()
{

    int choice;
    linkedlist ll;
    while(1)
    {
        cout<<"\n\n--------------------Menu ---------------------------";
        cout<<"\n1.Insert At Front\t2.Insert At Rear_push\t3.Insert Before\t\t4.Inset After\n";
        cout<<"5.Delete At Front\t6.Delete At Rear_pop\t7.Delete Value\t\t8.Display\n";
        cout<<"Enter Other to termimane process\n";
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