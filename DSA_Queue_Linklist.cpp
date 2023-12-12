// author: jaydattpatel
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node
{
	int info;
	struct node *next;
};

class queue
{
    private:
    node *rear;
    node *front;

    public:
    queue()
    {
        rear=NULL;
        front=NULL;
    }
    void Enqueue();
    void Dequeue();
    void display();
};

void queue::Enqueue()
{
    int data;
    node *temp=new node;
    cout<<"Enter the data to be inserted: ";
    cin>>data;
    temp->info=data;
    temp->next=NULL;
    if(front==NULL)
        front=temp;
    else
        rear->next=temp;
    rear=temp;
}

void queue::Dequeue()
{
    node *temp=new node;
    if(front==NULL)
        cout<<"Queue is empty\n";
    else
    {
        temp=front;
        front=front->next;
        cout<<"The data deleted from queue is "<<temp->info;
        delete temp;
    }
}

void queue::display()
{
    node *p=new node;
    p=front;
    if(front==NULL)
        cout<<"Queue is empty\n";
    else
    {
        cout<<"\nContents of queue:";
        while(p!=NULL)
        {  
            cout<<"\t"<<p->info;
            p=p->next;
        }
    }
}

int main()
{
    queue q;
    int choice;
    while(1)
    {
        cout<<"\n\n-----------Queue using Linkedlist -------------";
        cout<<"\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch (choice)
        {
            case 1: q.Enqueue();
                    break;
            case 2: q.Dequeue();
                    break;
            case 3: q.display();
                    break;
            case 4: exit(0);
                    break;
            default:cout<<"Please enter valid number";
                    break;
        }
    }
}