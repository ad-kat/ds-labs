#include <iostream>

using namespace std;

class que
{
    public:
    int frnt,rear;
    int q[20];
    que()
    {
        frnt=0,rear=-1;
    }
public:
    void enQueue(int a)
    {
        if(rear==19)
        {
            cout<<"Queue Overflow";
            return;
        }
        q[++rear]=a;
    }
    int deQueue()
    {
        if(frnt>rear)
            return -1;
        return q[frnt++];
    }
    void display()
    {
        int i;
        if(frnt>rear)
        {
          cout<<"Empty Queue\n";
          return;
        }
        for(i=frnt;i<=rear;i++)
            cout<<q[i]<<", ";
    }
};
int main()
{
    int n;
    que q1;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"Enter elements\n";
    int i,x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        q1.enQueue(x);
    }
    q1.display();
}
