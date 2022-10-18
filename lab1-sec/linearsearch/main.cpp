#include <iostream>

using namespace std;

int main()
{
    int n,i,key,flag=0;
    cout << "Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to be searched for\n";
    cin>>key;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
            {
                flag=1;
                break;
            }
    }
    if(flag==0)
        cout<<"Element is not present";
    else
        cout<<"Element is present at index "<<i;
    return 0;
}
