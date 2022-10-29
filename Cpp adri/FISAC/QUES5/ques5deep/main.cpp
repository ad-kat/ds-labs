#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Queue{
    int arr[MAX_SIZE];
    int front,rear;
    public:
    Queue()
    {
        front=rear=-1;
    }
    void enqueue(int item)
    {
        if(rear>=MAX_SIZE)
        {
            cout<<"Queue is full";
            return;
        }
        rear=rear+1;
        arr[rear]=item;
    }
    int dequeue()
    {
        if(rear==front)
        {
            cout<<"Queue is empty";
            return -999;
        }
        return arr[++front];
    }
    int IsEmpty()
    {
        if (front==rear)
            return 1;
        return 0;
    }
    int Size()
    {
        return (rear-front);
    }
    void display()
    {
        int n=rear;
        while(n>front)
        {
            cout<<arr[n]<<"\t";
            n--;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q1,q2;
    char a;
    do{
        int op,ele;
        cout<<"Enter 1 to push, 2 to pop, 3 to display: ";
        cin>>op;
        switch(op){
            case 1:
                cout<<"Enter the element: ";
                cin>>ele;
                if(q1.IsEmpty())
                    q1.enqueue(ele);
                else{
                    int n=q1.Size();
                    for(int i=0;i<n;i++)
                    {
                        q2.enqueue(q1.dequeue());
                    }
                    q1.enqueue(ele);
                    for(int i=0;i<n;i++)
                    {
                        q1.enqueue(q2.dequeue());
                    }
                }
                break;
            case 2:
                ele=q1.dequeue();
                cout<<"The popped element is: "<<ele<<"\n";
                break;

            case 3:
                q1.display();
                break;
            default:
                cout<<"Enter correct value\n";

        }

        cout<<"Continue program y/n?:";
        cin>>a;
    }while(a!='n');

}
