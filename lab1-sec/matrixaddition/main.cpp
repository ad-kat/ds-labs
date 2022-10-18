#include <iostream>

using namespace std;

int main()
{
    int m,n,i,j;
    cout << "Enter the number of rows and columns of both matrices" << endl;
    cin>>m>>n;
    int a[m][n],b[m][n];
    cout<<"Enter Matrix A\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<"Enter Matrix B\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cin>>b[i][j];
    }
    cout<<"Matrix A\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"Matrix B\n";
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<b[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"Matrix A+B\n";
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<(a[i][j]+b[i][j])<<" ";
        cout<<"\n";
    }
    return 0;
}
