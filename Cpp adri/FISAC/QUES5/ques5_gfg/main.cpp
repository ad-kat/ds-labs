#include <iostream>
#include <string.h>
using namespace std;
 int const MAX = 50;
class Queues
{
public:
    int q1[MAX];
    int q2[MAX];

    int f1,r1;
    int f2,r2;
    //  FUNCTION TO INITIALISE THE CLASS OBJECT
    Queues()
    {
        f1=-1;f2=-1;
        r1=-1;r2=-1;
    }
    int peek1()
        {
            if(f1==r1)
                return -999;
            return q1[f1];
        }
    int peek2()
        {
            if(f2==r2)
                return -999;
            return q2[f2];
        }
    int isempty1()
        {
            if(f1==r1)
            {
                f1=-1;
                r1=-1;
                return 1;
            }
            else return 0;
        }
    int isempty2()
        {
            if(f2==r2)
            {
                f2=-1;
                r2=-1;
                return 1;
            }
            else return 0;
        }
    //  FUNCTION TO POP AN ELEMENT AND RETURN IT
    int dequeue1()
    {
        if(f1==r1)
        {
            cout<<"Stack underflow"<<endl;
            return -999;
        }
        else{
            int ch=q1[f1];
            f1++;
            return ch;
        }
    }
    int dequeue2()
    {
        if(f2==r2)
        {
            cout<<"Stack underflow"<<endl;
            return -999;
        }
        else{
            int ch=q2[f2];
            f2++;
            return ch;
        }
    }
    void enqueue1(int k)
    {
        if(r1>=49)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            r1++;
            q1[r1]=k;
        }
    }
    void enqueue2(int k)
    {
        if(r2>=49)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            r2++;
            q2[r2]=k;
        }
    }
    //  FUNCTION TO DISPLAY ALL THE ELEMENTS IN THE STACK
    void display()
    {
        if(isempty1()==0)
        for(int i = f1+1; i<=r1; i++)
            cout<<q1[i]<<"\t";
    }
    void make_empty1()
    {
        f1=-1;
        r1=-1;
    }
    void make_empty2()
    {
        f2=-1;
        r2=-1;
    }
};

class Stacks{
    Queues obj;
public:
    void push(int k)
    {
        int pos=0;
        obj.enqueue2(k);
        for(int i=obj.f1+1;i<=obj.r1;i++)
        {
            if(obj.isempty1()==0)
            {
               obj.enqueue2(obj.dequeue1());
            }
        }
        obj.make_empty1();
        for(int i=obj.f2+1;i<=obj.r2;i++)
        {
            obj.enqueue1(obj.dequeue2());
        }
        obj.make_empty2();
    }
    void display()
    {
        obj.display();
        cout<<endl;
    }

    int pop()
    {
      int ch=obj.dequeue1();
      return ch;
    }
};
int main()
{
 Stacks s;
 cout<<endl<<"Enter choice\n 1.Push\n 2.Pop\n 3.Display\n any other number to exit";
 int flag=1;
 do{
    cout<<endl<<"Enter choice";
    int key;
    cin>>key;

    switch(key)
    {
        case 1:{cout<<"Enter integer to enqueue  ";
                int temp;
                cin>>temp;
                s.push(temp);
                break;}
        case 2:
            {
            cout<<"Deleted element is:"<<s.pop();
            break;}
        case 3:
            cout<<"stack contains:";
            s.display();
            cout<<endl;
            break;
        default:
            cout<<"Ending program"<<endl;
            flag=0;
            break;

    }
  }while(flag==1);
    return 0;
}







