#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int a,i,j;
    cout << "Enter \n 1.length of the string\n 2.string concatenation\n 3.string comparison\n 4.to insert a sub string\n 5.to delete a substring\n";
    cin>>a;
    fflush(stdin);
    cout<<"Enter a string\n";
    char s[100];
    char s2[100];
    gets(s);
    switch(a)
    {
    case 1:
        {
            for(i=0;s[i]!='\0';i++);
            cout<<"Length is "<<i;
            break;
        }
    case 2:
        {
            cout<<"Enter another string\n";
            gets(s2);
            for(i=0;s[i]!='\0';i++);
            for(j=0;s2[j]!='\0';j++,i++)
                s[i]=s2[j];
            s[i]='\0';
            cout<<"The concatenated array is\n";
            puts(s);
            break;
        }
    case 3:
        {
            cout<<"Enter another string\n";
            gets(s2);
            for(i=0;s[i]!='\0';i++);
            for(j=0;s2[j]!='\0';j++);
            int x,dif=0;
            for(x=0;s[x]!='\0'&&s2[x]!='\0';x++)
                dif= dif+((int)s[x]-(int)s2[x]);
            if(dif>0)
                cout<<s<<" is alphabetically below "<<s2;
            else if(dif<0)
                cout<<s2<<" is alphabetically below "<<s;
            else
                cout<<"Same word";
            break;
        }
    case 4:
        {
            cout<<"Enter another string\n";
            gets(s2);
            for(i=0;s[i]!='\0';i++);
            for(j=0;s2[j]!='\0';j++);
            int x,y,pos;
            cout<<"Enter position to insert\n";
            cin>>pos;
            for(x=i;x>pos-2;x--)
                s[x+j]=s[x];
            x++;
            for(y=0;y<=strlen(s2)&&s2[y]!='\0';y++,x++)
                s[x]=s2[y];
            cout<<"New string is\n";
            puts(s);
        }
    case 5:

            cout<<"Enter substring to be removed\n";
            gets(s2);
            int x,flag=0,n=0;
            char neww[100];
            for(i=0,j=0;s[i]!='\0';i++)
                {
                    x=i;
                    while(s[i] == s2[j])
                    {
                        i++,j++;
                        if(j == strlen(s2))
                        {
                            flag = 1;
                            break;
                        }
                    }
                j=0;
                if(flag == 0)
                    i=x;
                else
                    flag = 0;
                neww[n++]=s[i];
                }
                neww[n]='\0';
                cout<<"After Removing Word From String: "<<neww;




    }

}
