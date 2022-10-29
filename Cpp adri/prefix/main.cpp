#include <iostream>
#include <string.h>
using namespace std;
class Stacks
{
    char arr[50];
    char str[50];
    char str2[50];
    char ans[50];
    char ans2[50];
    int top,t;
public:
    Stacks()
    {
        top=0;t=0;
        arr[0]='#';
    }
    void input()
    {
        cout<<"Input the string:"<<endl;
        cin.get(str,50);
        fflush(stdin);
    }
    void rev();
    void rev2();
    void push(char ch);
    int stprec(char ch);
    int inprec(char ch);
    void topost();
    char pop();
    char peek();
    void display();
    void change();

};
void Stacks::push(char ch)
{
    if(top>=49)
    {
        cout<<"stack full";
        return ;
    }
    else
        {
        top++;
        arr[top]=ch;
        }
}
void Stacks::rev()
{
    int i,k=0,len=strlen(str);
    for(i=(len-1);i>=0;i--)
    {
        str2[k]=str[i];
        k++;
    }
}
void Stacks::rev2()
{
    int i,k=0,len=strlen(ans);
    for(i=(len-1);i>=0;i--)
    {
        ans2[k]=ans[i];
        k++;
    }


}
void Stacks::change()
{
    int i,len=strlen(str2);

    for(i=0;i<len;i++)
    {
        if(str2[i]=='(')
            str2[i]=')';
        else if(str2[i]==')')
            str2[i]='(';
    }
}
char Stacks::pop()
{
    if(arr[top]=='#')
    {
        cout<<"Stack empty";
        return '@';
    }
    else
    {
        char ch=arr[top];
        top--;
        return ch;
    }
}
int Stacks::stprec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':return 2; break;
    case '*':
    case '/':return 4; break;
    case '^':return 5; break;
    case '(':return 0; break;
    case '#':return -1; break;
    default: return 8;break;
    }
}
int Stacks::inprec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':return 1; break;
    case '*':
    case '/':return 3; break;
    case '^':return 6; break;
    case '(':return 9; break;
    case ')':return 0; break;
    default: return 7;break;
    }
}
char Stacks::peek()
{
    return arr[top];
}
void Stacks::topost()
{
    int i;
    for(i=0;i<strlen(str2);i++)
    {
        char c=str2[i];
        int in=inprec(c);

            if(in>stprec(arr[top]))
            push(c);
            else
                {

                 while(stprec(arr[top])>in)
                {
                ans[t]=pop();
                t++;
                }
                push(c);
                }
    }
    while(peek()!='#')
    {
        ans[t]=pop();
        t++;
    }


}
void Stacks::display()
{
    int i;
    for(i=0;i<t;i++)
    {
       if(ans2[i]=='('||ans2[i]==')')
            continue;
        else
            cout<<ans2[i];
    }

}
int main()
{
    Stacks s;
    s.input();
    s.rev();
    s.change();
    s.topost();
    s.rev2();
    s.display();
    return 0;
}
