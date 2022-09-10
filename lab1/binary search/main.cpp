/*Write a program to search a given element in a list using
i.) Linear Search
ii.) Binary Search */

#include <iostream>
using namespace std;

int main()
{
    int arr1[30],arr2[30];
    int n,num,n2,i,num2,flag=0;
    cout<<"implementing BINARY SEARCH"<<endl;
    cout << "enter size of the array" << endl;
    cin>>n;
    int high=n-1,low=0,mid;
    cout<<"enter array elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"enter the number to be searched"<<endl;
    cin>>num;
    do
    {
        mid=(high+low)/2;
        if(num<arr1[mid])
            high=mid-1;
        else if(num>arr1[mid])
            low=mid+1;
    }while(num!=arr1[mid]&&high>=low);

    if(num==arr1[mid])
    {
        cout<<"element "<<num<<" found in "<<(mid+1)<<"th position in array"<<endl;
    }

        else cout<<"element not found"<<endl;
    cout<<"the array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr1[i]<<"\t";
    }
    cout<<"\n"<<"implementing LINEAR SEARCH"<<endl;
    cout << "enter size of the array" << endl;
    cin>>n2;
    cout<<"enter array elements"<<endl;
    for(i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    cout<<"enter the number to be searched"<<endl;
    cin>>num2;
    for(i=0;i<n;i++)
    {
        if(arr2[i]==num2)
        {
            cout<<"element "<<num2<<" found in "<<(i+1)<<"th position in array"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"element not found"<<endl;

    cout<<"the array is:"<<endl;
    for(i=0;i<n2;i++)
    {
        cout<<arr2[i]<<"\t";
    }
    return 0;
}
