#include <iostream>
#include <string.h>
#define MAX 50
using namespace std;
class Stack
{
private:
    char data[MAX],str[MAX];
    int top,length,count;
public:
    void push(char);
    char pop();
    Stack()
    {
        top==-1;
        length=0;count=0;
    }
    void get();
    void check();
    void extract();
    void rev();
};
void Stack::get() {
  cout<<"\n Enter a String: ";
  cin.getline(str,MAX);

  length=strlen(str);
}
void Stack::extract()
{
char temp[MAX];
int i,j;
for(i=0;i<length;i++)
    {
        temp[i]=str[i];
    }
    j=0;
    for(i=0;i<length;i++)
    {
        if(isalpha(temp[i]))
        {
            str[j]=tolower(temp[i]);
            j++;
        }
    }
    length=j;

}
void Stack::check()
{

    for(int i=0;i<length;i++)
        push(str[i]);
    for(int i=0;i<length;i++)
    {
        if(str[i]==pop())
            count++;
    }
    if(count==length)
        cout<<"PALINDROME"<<endl;
    else
        cout<<"NOT Palindrome"<<endl;

}
void Stack::push(char temp)
{
    if(top==MAX-1)\
    {

        cout<<"\n Stack Overflow";
        return;
    }
    top++;
    data[top]=temp;
}
char Stack::pop()
{
    if(top==-1)
    {
        cout<<"\nStack Underflow";
        char ch='\n';return ch;
    }
    char temp=data[top];top--;
    return temp;
}
void Stack::rev()
{
    for(int i=length-1;i>=0;i--)
    {
        cout<<str[i];
    }
}
int main()
{
    Stack obj;
    obj.get();
    obj.extract();
    cout<<"Reverse of entered string:";
    obj.rev();
    obj.check();
    return 0;
}
