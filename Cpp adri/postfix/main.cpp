#include <iostream>
#include <string.h>
using namespace std;
class Stacks
{
    char arr[50];
    char exp[50];
    char ans[50];
    int top;
public:
    Stacks()
    {
        top=0;
        arr[0]='#';
    }
    void input()
    {
        cout<<"Input the string:"<<endl;
        cin.get(exp,50);
        fflush(stdin);
    }
    void push(char ch);
    int stprec(char ch);
    int inprec(char ch);
    void topost();
    char pop();
    char peek();


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
    for(i=0;i<strlen(exp);i++)
    {
        char c=exp[i];
        int in=inprec(c);

            if(in>stprec(arr[top]))
            push(c);
            else
                {

                 while(stprec(arr[top])>in)
                {
                cout<<pop();
                }
                push(c);
                }
    }
    while(arr[top]!='#')
    {
        cout<<pop();
    }
}

int main()
{
    Stacks s;
    s.input();
    s.topost();
    return 0;
}
