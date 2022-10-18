#include <iostream>
#include <string.h>
using namespace std;
class student
{
    int roll_num;
    char name[100];
    char grade;
public:
    void read(student st[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<"Enter Roll Number\n";
            cin>>st[i].roll_num;
            fflush(stdin);
            cout<<"Enter Name\n";
            cin>>st[i].name;
            fflush(stdin);
            cout<<"Enter grade\n";
            cin>>st[i].grade;
        }
    }
    void display(student st[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
           cout<<st[i].roll_num<<"\t"<<st[i].name<<"\t"<<st[i].grade<<"\n";
        }
    }
    void sortar(student st[],int n)
    {
        int i,j,temp;
        char temps[100],tempc;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(st[i].roll_num<st[j].roll_num)
                {
                    temp=st[i].roll_num;
                    st[i].roll_num=st[j].roll_num;
                    st[j].roll_num=temp;
                    strcpy(temps,st[i].name);
                    strcpy(st[i].name,st[j].name);
                    strcpy(st[j].name,temps);
                    tempc=st[i].grade;
                    st[i].grade=st[j].grade;
                    st[j].grade=tempc;

                }

            }
        }
    }
};
int main()
{
    cout<<"Enter number of students\n";
    int n;
    cin>>n;
    student st[n],s;
    s.read(st,n);
    s.sortar(st,n);
    s.display(st,n);
}
