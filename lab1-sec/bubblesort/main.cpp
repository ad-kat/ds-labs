#include <iostream>

using namespace std;

int main()
{
    int n,i,j,temp;
    cout << "Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Sorted Array\n";
    for(i=0;i<n;i++)
        cout<<" "<<a[i];
    return 0;
}
