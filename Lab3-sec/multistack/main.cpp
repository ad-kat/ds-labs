#include <iostream>
#include <string.h>
using namespace std;

class stk
{
    public:
    int top1,top2;
    int s[100];
    stk()
    {
        top1=-1;
        top2=100;
    }
    void push1(int a)
    {
        if(top1==top2-1)
        {
            cout<<"Stack Overflow";
            return;
        }
        s[++top1]=a;
    }
    int pop1()
    {
        if(top1==-1)
        {
            return -999;
        }
        return s[top1--];
    }
    void push2(int a)
    {
        if(top2-1==top1)
            cout<<"Stack Overflow";
        s[--top2]=a;
    }
    int pop2()
    {
        if(top2==100)
        {
           cout<<"Underflow";
           return -999;
        }
        return s[top2++];

    }
    void display1()
    {
        int i;
        if(top1==-1)
            cout<<"Stack A is empty";
        else
        {
            for(i=top1;i>=0;i--)
                cout<<" "<<s[i];
        }
    }
    void display2()
    {
        int i;
        if(top2==-1)
            cout<<"Stack B is empty";
        else
        {
            for(i=top2;i>=0;i--)
                cout<<" "<<s[i];
        }
    }
};
int main()
{
    int n,a;
    stk s1;
    do
    {
        cout<<"\n 1. PUSH into Stack A";
        cout<<"\n 2. PUSH into Stack B";
        cout<<"\n 3. POP from Stack A";
        cout<<"\n 4. POP from Stack B";
        cout<<"\n 5. Display Stack A";
        cout<<"\n 6. Display Stack B";
        cout<<"\n 7. Exit";
        cout<<"\n Enter your choice\n";
        cin>>n;
        switch(n)
        {
            case 1:
            cout<<"\n Enter the value to push on stack A :\n";
            cin>>a;
            s1.push1(a);
            break;
            case 2:
            cout<<"\n Enter the value to push on stack B:\n";
            cin>>a;
            s1.push2(a);
            break;
            case 3:
            if(a != -999)
            cout<<"\n The value popped from Stack A = "<<s1.pop1()<<"\n";
            break;
            case 4:
            if(a != -999)
            cout<<"\n The value popped from Stack B = "<<s1.pop2()<<"\n";
            break;
            case 5:
            cout<<"\n The contents of Stack A are :\n";
            s1.display1();
            break;
            case 6:
            cout<<"\n The contents of Stack B are :\n";
            s1.display2();
            break;
        }
    }while(n != 7);
    return 0;
}
