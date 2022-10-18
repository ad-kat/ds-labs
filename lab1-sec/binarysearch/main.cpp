#include <iostream>

using namespace std;

int main()
{
    int n,i,key,up,lo,mid,flag=0;
    cout << "Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to be searched for\n";
    cin>>key;
    lo=0;
    up=n-1;
    mid=(lo+up)/2;
    while(lo<=up)
    {
        if(a[mid]==key)
        {
            cout<<"Element is present";
            flag=1;
            break;
        }
        else if(key>a[mid])
        {
            lo=mid+1;
            mid=lo+(up-lo)/2;
        }
        else
        {
            up=mid-1;
            mid=lo+(up-lo)/2;
        }
    }
    if(flag==0)
        cout<<"Element is not present";
    return 0;
}
