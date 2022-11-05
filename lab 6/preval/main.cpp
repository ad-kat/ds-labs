#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
const int STACK_SIZE=100;
class Stk {
    private:
    int top;
    char arr[STACK_SIZE];
    public:
    Stk(){
        top=-1;
    }
    void push(char elem){
        if(top<STACK_SIZE){
            arr[++top]=elem;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }

    char pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Stack Underflow!"<<endl;
        return -1;
    }

    char peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

int Cal( int a,char ch,int b){
    switch(ch){
        case '*': return(a*b);break;
        case '+': return(a+b);break;
        case '-': return(a-b);break;
        case '/': return(a/b);break;

        case '^': return(a^b);break;
        default:
        return 0;
    }
}

int Eval(char pre[]){
    Stk s; int op1,op2;
    int l=strlen(pre);
    for(int i=l-1;i>=0;i--){
       if(pre[i]=='+'||pre[i]=='-'||pre[i]=='*'||pre[i]=='/'||pre[i]=='^')
       {
           op1=s.pop();
           op2=s.pop();
           s.push(Cal(op1,pre[i],op2));
       }
       else{

        s.push((pre[i]-'0'));
       }
    }
    return s.peek();
}

int main(){
    char s[100];
    cout<<"Enter prefix expression:";
   gets(s);

    cout<<Eval(s);




    return 0;
}
