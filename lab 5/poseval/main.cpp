#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
const int MAX=50;
class Stack {
    private:
    int top;
    char arr[MAX];
    public:
    Stack(){
        top=-1;
    }
    void push(char elem){
        if(top<MAX){
            arr[++top]=elem;return;
        }
            cout<<"Overflow"<<endl;
    }
    char pop(){
        if(top==-1)
        {
           cout<<"Stack Underflow!"<<endl;
        return -1;
        }
            return arr[top--];
    }
    char peek(){
        if(top>=0)
            return arr[top];
        else{
            cout<<"Underflow"<<endl;
            return -1;
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
        default:return 0;
    }
}
int postEval(char post[]){
    Stack s;
    int op1,op2;
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
    char s[50];
    cout<<"Enter expression:";
   gets(s);

    cout<<postEval(s);
    return 0;
}
