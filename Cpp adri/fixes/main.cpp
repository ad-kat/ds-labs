#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Stacks{
    int top;
    char expr[50];
    char arr[50];
    char t;


public:

    Stacks()
    {
        top = -1;
    }
    void push(char);
    void input()
    {
        cout<<"enter statement:";
        cin.get(expr,50);
        fflush(stdin);
    }
    char pop();
    char peek();
    void topost();
    int inprec(char ch);
    int stprec(char ch);

};
void Stacks::topost();
{

}
int Stacks::inprec(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 1; break;
		case '*':
		case '/': return 3; break;
		case '^': return 6; break;
		case '(': return 9; break;
		case ')': return 0; break;
		default: return 7;
	}
}
int Stacks::stprec(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 2; break;
		case '*':
		case '/': return 4; break;
		case '^': return 5; break;
		case '(': return 0; break;
		case '#': return -1; break;
		default: return 8;
	}
}

void Stacks::push(char x) {
    if (top >= (50 - 1)) {
        cout << "Stack Overflow";
        return ;
    }
    else {
        top++;
        arr[top] = x;

    }
}
char Stacks::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return '@';
    }
    else {
        int x = arr[top];
        top--; return x;
    }
}
int main()
{
    Stacks s;
    s.input();
    return 0;
}
