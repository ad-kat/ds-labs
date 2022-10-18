#include <iostream>

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
    void palindrome()
    {
        int n;
        cout<<"Enter a number\n";
        cin>>n;
        int b=n;
        while(b!=0)
        {
            push(b%10);
            b=b/10;
        }
        b=n;
        while(b!=0)
        {

            if(pop()!=(b%10))
            {
               cout<<"Not a palindrome";
               return;
            }
            b=b/10;

        }
        cout<<"Palindrome";

    }
};
int main()
{
    stk s1;
    s1.palindrome();
}
