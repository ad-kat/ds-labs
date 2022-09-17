#include <iostream>

using namespace std;
class Stack
{
private:
    int s[100];
    int top;
public:
    Stack()
    {
        top=-1;

    }
    void push(int r)
    {

        if(top>=99)
        {

            return;
        }
        top=top+1;

        s[top]=r;

    }
   int pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        int temp=s[top];
        top--;
        return temp;
    }
    bool isFull()
    {
        if(top==99)
    return true;
    else return false;
    }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
            return false;
    }
    void display()
    {
        int i;
        cout<<"Converted value:";
        for(i=top;i>=0;i--)
        {
            if(s[i]<10)
            cout<<pop();
            else
                cout<<(char)pop();
        }
    }
    void conversion(int,int);
};
void conversion(int n,int c)
{
    int rem,num=n;

    Stack converted;
    while(num>0)
    {
        rem=num%c;

        if(rem<10)
        {

            converted.push(rem);


        }

        else if(rem>=10)
        {
            rem+=55;
            converted.push(rem);

        }
        else{
            cout<<"out of scope"<<endl;
            return;
        }
        num/=c;
    }
    converted.display();
}
int main()
{
    int n,c;
    cout<<"enter number and base conversion to be performed:";
    cin>>n>>c;
  conversion(n,c);
    return 0;
}
