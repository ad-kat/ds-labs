#include <iostream>
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
    void contopfix(char infix[])
    {
        char pfix[50];
        int precedence,p;
        char e1,e2;
        p=0;
        for(int i=0;infix[i]!='\0';i++)
        {
            e1=infix[i];
            switch(e1)
            {
                case '(':
                       push(e1);
                       break;
                case ')':
                    while((e2=pop())!='(')
                            pfix[p++]=e2;
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
                            pfix[p++]=e2;
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
                    pfix[p++]=e1;
                    break;
            }
        }
        while(!isempty())
            pfix[p++]=pop();
        pfix[p]='\0';
        cout<<"The postfix expression is: "<<pfix<<endl;

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
    char inf[50];
    cout<<"Enter an infix expression"<<endl;
    gets(inf);
    s1.contopfix(inf);
}
