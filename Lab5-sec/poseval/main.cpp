#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
const int STACK_SIZE=100;
class Stack {
    private:
    int top;
    char arr[STACK_SIZE];
    public:
    Stack(){
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

int Cal( int a,char ch, int b){
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

int postEval(char post[]){
    Stack s; int op1,op2;
    int l=strlen(post);
    for(int i=0;i<l;i++){
       if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
       {
           op2=s.pop();
           op1=s.pop();
           s.push(Cal(op1,post[i],op2));
       }
       else{

        s.push((post[i]-'0'));
       }
    }
    return s.peek();
}

int main(){
    char s[100];
    cout<<"Enter expression:";
   gets(s);

    cout<<postEval(s);




    return 0;
}
