#include <iostream>

using namespace std;

int main()
{
    int n,i,j,key;
    cout << "Enter size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        key=a[i];

         for(j=i-1;j>=0&&a[j]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
    cout<<"Sorted Array\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
