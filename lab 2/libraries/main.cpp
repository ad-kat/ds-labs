/*Write a program to perform following string operations without using string handling
functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring*/
#include <iostream>
using namespace std;

int main()
{
char s[100];
int i,j,k=0,l=0;
cout<<"a.)Length of the string"<<endl;
cout << "\n"<<"Enter a string: ";
cin.get(s,100);
fflush(stdin);

for(i = 0; s[i] !='\0'; ++i);
cout << "\n"<<"Length of string : " << i;
cout << endl;

cout<<"b.) string concatenation"<<endl;
char s1[100], s2[100];

    cout << "Enter string s1: ";
    cin.get(s1,100);
    fflush(stdin);

    cout << "Enter string s2: ";
    cin.get(s2,100);
    fflush(stdin);

   while(s1[k]!='\0')
   k++;
   while(s2[l]!='\0')
   {
       s1[k]=s2[l];
       k++;
       l++;
   }
   s1[k]='\0';

    cout << "Resultant String = "<< s1;

   cout<<"\n"<<"d.) to insert a sub string"<<endl;
   char a[100],b[100],c[200];
   int alen=0,blen=0;

   cout << "Enter main string: "<<endl;
    cin.get(a,100);
    fflush(stdin);
    while(a[alen]!='\0')
        alen++;

    cout << "Enter the substring "<<endl;
    cin.get(b,100);
    fflush(stdin);
    while(b[blen]!='\0')
        blen++;

    cout<<"enter the position where to add the string:"<<endl;
    int pos;
    cin>>pos;
    for(i=0;i<pos;i++)
    {
        c[i]=a[i];
    }
    c[pos]=' ';

    int blen2=0;
    for(i=pos+1;i<pos+blen+1;i++)
    {
        c[i]=b[blen2];
        blen2++;
    }
    for(i=pos+blen+1;i<alen+blen+1;i++)
    {
        c[i]=a[i-pos];
        blen2++;
    }
    c[i]='\0';
        cout << "Resultant String = "<< c;

        cout<<"\n"<<"e.) to delete a substring"<<endl;
return 0;
}
