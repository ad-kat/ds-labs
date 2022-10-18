#include <iostream>
#include<string.h>
using namespace std;
class stk
{
    int top;
    char s[100];
    public:
    stk()
    {
        top=-1;
    }
    void push(char a)
    {
        if(top==99)
        {
            cout<<"Stack Overflow";
            return;
        }
        s[++top]=a;
    }
    char pop()
    {
        if(top==-1)
        {
            return '\0';
        }
        return s[top--];
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    void contoprefix(char infix[])
    {
        char prefix[50];
        int precedence,p;
        char e1,e2;
        p=0;

        for(int i=0;infix[i]!='\0';i++)
        {
            e1=infix[i];

            switch(e1)
            {
                case ')':
                       push(e1);
                       break;
                case '(':
                    while((e2=pop())!=')')
                            prefix[p++]=e2;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    if(!isempty())
                    {
                        precedence=prec(e1);
                        e2=pop();
                        while(precedence<=prec(e2))
                        {
                            prefix[p++]=e2;
                            if(!isempty())
                                e2=pop();
                            else
                                //push(e1);
                                break;
                        }
                        //push(e1);
                        if(precedence>prec(e2))
                        {
                            push(e2);
                            //push(e1);
                        }
                    }
                    push(e1);
                    break;
                default:
                    prefix[p++]=e1;
                    break;
            }
        }
        while(!isempty())
            prefix[p++]=pop();
        prefix[p]='\0';
        //strrev(prefix);
        cout<<"The prefix expression is: "<<strrev(prefix)<<endl;

    }
    int prec(char symbol)
    {
        switch(symbol)
        {
        case '/':
        case '*':return 3;
        case '+':
        case '-':return 2;
        case '(':return 0;
        default:return -1;
        }
    }
};
int main()
{
    stk s1;
    char pre[100];
    cout<<"Enter an infix expression"<<endl;
    gets(pre);
    strrev(pre);
    s1.contoprefix(pre);
    return 0;
}


