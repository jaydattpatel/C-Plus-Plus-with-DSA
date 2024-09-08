// author: jaydattpatel
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

#define MAX 10

class queue
{
    private:
        int q[MAX],front,rear,x,result;
    public:
        queue()
        {
            front=-1;
            rear=-1;
        }
        void Enqueue();
        void Dequeue();
        void display();
    
};

void queue::Enqueue()
{
    if(rear>=(MAX-1))
        cout<<"\nQueue Overflow\n";
    else
    {
        if(front<0)
            front++;
        cout<<"\nEnter number to be inserted:";
        cin>>x;
        rear++;
        q[rear]=x;
        cout<<"\nNumber inserted in queue:"<<q[rear];
    }
}

void queue::Dequeue()
{
    if(rear<0)
        cout<<"\nQueue underflow!\n";
    else
    {
        if(front==rear)
        {
            q[front] = 0;;
            front=-1;
            rear=-1;
        }
        else
        {
            cout<<"\nDeleted: "<<q[front];
            q[front] = 0;
            front++;
        }
    };
}

void queue::display()
{
    if(front<0)
        cout<<"\nQueue underflow !\n";
    else
    {
        cout<<"\nContents of queue:";
        for(int i=front;i<=rear;i++)
            cout<<"\t"<<q[i];
    }
}

int main()
{
    int c;
    queue qu;
    while(1)
    {
        cout<<"\n\n\n-----------Queue using Array -------------";
        cout<<"\n1.Insertion\t2.Deletion\t3.Display\t4.Exit";
        cout<<"\nEnter your choice:";
        cin>>c;
        switch (c)
        {
            case 1: qu.Enqueue();
                    break;
            case 2: qu.Dequeue();
                    break;
            case 3: qu.display();
                    break;
            case 4: exit(0);
                    break;
            default:cout<<"Please enter valid number........";
                    break;
        }
    };
    return(0);
}