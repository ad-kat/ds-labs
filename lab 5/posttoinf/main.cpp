#include <iostream>
#include <cstring>
using namespace std;
const int MAX=100;

class Stacks{
    int top;
    string arr[100];
    public:
    Stacks(){
        top=-1;
    }
    void push(string elem){
        if(top<MAX){
            arr[++top]=elem;
        }
        else
            cout<<" Overflow";
    }
    string pop(){
        if(top>=0)
            return arr[top--];
        cout<<"Underflow"<<endl;
    }
    string peek(){
        if(top>=0)
            return arr[top];
        cout<<"Underflow"<<endl;
    }
};

string postToInfix(string pre){
    Stacks s;
    string op;
    int l=pre.length();
    for(int i=0;i<l;i++){
        if(isdigit(pre[i])||isalpha(pre[i])){
            s.push(string(1,pre[i]));
        }
        else{
            string a=s.pop();
            string b=s.pop();
            string exp='('+b+pre[i]+a+')';
            s.push(exp);
        }
    }
    op=s.peek();
    return op;
}

int main(){
    string post;
    cout<<"Enter postfix:";
    cin>>post;
    cout<<postToInfix(post);
}
