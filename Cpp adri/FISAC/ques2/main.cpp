#include <iostream>
using namespace std;

void strCal(char *p)
{
   int  v=0,c=0;
   while(*p!='\0')
    {
        if(*p=='A' ||*p=='E' ||*p=='I' ||*p=='O' ||*p=='U'
        		||*p=='a' ||*p=='e' ||*p=='i' ||*p=='o' ||*p=='u')
            v++;
        else if(*p!=' ')
            c++;
        //increase the pointer, to point next character
        p++;
    }

    cout<<"Number of Vowels in String: "<<v<<endl;
    cout<<"Number of Consonants in String:"<<c<<endl;
}
int main()
{
    char str[100];
    char *p;
    int  v=0,c=0;

    cout<<"Enter string: ";
    cin.get(str, 100);
    fflush(stdin);

    //assigning base address of array to pointer
    strCal(str);
    return 0;
}
