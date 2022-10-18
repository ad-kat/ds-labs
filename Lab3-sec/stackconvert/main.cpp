#include <iostream>
#include <string.h>
using namespace std;

class stk
{
    public:
    int top;
    int s[100];
    stk()
    {
        top=-1;
    }
    void push(int a)
    {
        if(top==99)
        {
            cout<<"Stack Overflow";
            return;
        }
        s[++top]=a;
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow";
            return -999;
        }
        return s[top--];
    }
    void binary(int a)
    {
        int c=0;
        int b=0;
        while(a>1)
        {
            push(a%2);
            a=a/2;
            c++;
        }
        push(a);
        while(c>=0)
        {
            b=b*10+pop();
            c--;
        }
        cout<<"Binary: "<<b;

    }
    void octal(int a)

    {
        int c=0;
        int o=0;
        while(a>7)
        {
            push(a%8);
            a=a/8;
            c++;
        }
        push(a);
        while(c>=0)
        {
            o=o*10+pop();
            c--;
        }
        cout<<"\nOctal: "<<o;

    }
    void hexadecimal(int a)
    {
        int c=0,i=0,temp;
        char ch[20];
        while(a>15)
        {
            push(a%16);
            a=a/16;
            c++;
        }
        push(a);
        while(c>=0)
        {
            temp=(int)pop();
            if(temp<10)
                ch[i]=(char)(temp+48);
            else
                ch[i]=(char)(temp+55);
            i++;
            c--;
        }
        ch[i]='\0';
        cout<<"\nHexadecimal: ";
        puts(ch);
    }
};
int main()
{
    stk s1;int n;
    cout<<"Enter a number\n";
    cin>>n;
    s1.binary(n);
    s1.octal(n);
    s1.hexadecimal(n);
}
