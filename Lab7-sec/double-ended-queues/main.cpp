#include <iostream>
#include <string.h>
using namespace std;

class Queues
{
    int front,rear;
    int arr[50];
public:
    Queues()
    {
        front=-1;rear=-1;
    }
    void insert_front(int ch);
    void insert_rear(int ch);
    int delete_front();
    int delete_rear();
    void display();
};
void Queues::insert_front(int ch)
{
    if(rear==-1&&front==-1)
    {
        rear++;
        arr[rear]=ch;
    }
    else if(front!=-1)
    {
        arr[front]=ch;
        front--;
    }
    else if(front==-1)
    {
        cout<<"Front insertion is not possible;try rear insertion"<<endl;
    }
}
int Queues::delete_rear()
{
    if(front==rear)
    {
        cout<<"Queue is empty";
        front=-1;
        rear=-1;
        return -999;
    }
    else
    {
        int ch=arr[rear];
        rear--;
        return ch;
    }
}
void Queues::insert_rear(int ch)
{
    if(rear>=49)
    {
        cout<<"queue full";
    }
    else
    {
        rear++;
        arr[rear]=ch;
    }
}
int Queues::delete_front()
{
    if(front==rear)
    {
        cout<<"Queue is empty";
        front=-1;
        rear=-1;
        return -999;
    }
    else
    {
        int ch=arr[front];
        front++;
        return ch;
    }
}
void Queues::display()
{
    if(front==rear)
    {
        cout<<"Queue is empty";
        front=-1;
        rear=-1;
    }
    else
    {
       int i;
        for(i=front;i<=rear;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
}
int main()
{
    int choice,item,exit=1;
    Queues obj;
    cout<<"1. Insert at front."<< "\n"<< "2. Insert at rear."<< endl;
    cout<< "3. delete from front."<< "\n"<< "4. delete from rear."<< endl;
    cout<<"5. display queue"<< "\n"<< "Enter any other number to exit"<<endl;
    do
    {

        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:cout<<"Insert item to insert:";
                cin>>item;
                obj.insert_front(item);
                break;
        case 2:cout<<"Insert item to insert:";
                cin>>item;
                obj.insert_rear(item);
                break;
        case 3:cout<<"deleted item:"<<obj.delete_front()<<endl;
                break;
        case 4:cout<<"deleted item:"<<obj.delete_rear()<<endl;
                break;
        case 5:cout<<"Displaying elements:"<<"\t";
                obj.display();
                break;
        default:exit=0;break;
        }
    }while(exit==1);
    return 0;
}
