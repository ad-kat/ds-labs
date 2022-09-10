/* Write a program to read two matrices A & B, create and display a third matrix C such
that C(i, j) = max ( A(i, j) , B(i, j))*/

#include <iostream>

using namespace std;

int main()
{
    int r,c,i,j;
    cout << "enter dimensions r and c for the three matrices:" << endl;
    cin>>r>>c;
    int A[30][30],B[30][30],C[30][30];

    cout<<"enter matrix elements for A"<<endl;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>A[i][j];
    cout<<"enter matrix elements for B"<<endl;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>B[i][j];

    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           C[i][j]=(A[i][j]>B[i][j])?A[i][j]:B[i][j];
       }

    }

    cout<<endl<<"Matrix A"<<endl;

     for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           cout<<A[i][j]<<"\t";
       }
       cout<<endl;

    }
     cout<<endl<<"Matrix B"<<endl;

     for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           cout<<B[i][j]<<"\t";
       }
       cout<<endl;

    }
     cout<<endl<<"Matrix C"<<endl;;

     for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           cout<<C[i][j]<<"\t";
       }
       cout<<endl;

    }
    return 0;
}
