
/*Write a program to search a given element in a list using
i.) Linear Search
ii.) Binary Search */

#include <iostream>
using namespace std;

int main()
{
    int arr[30];
    int n,num;
    cout << "enter size of the array" << endl;
    cin>>n;
    int i,found=0,pos;
    cout<<"enter array elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the number to be searched";
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(num==arr[i])
        {
            found=1;
            pos=i+1;
            break;
        }
    }

    if(found==1)
    {
        cout<<"element "<<num<<" found in "<<pos<<"th position in array"<<endl;
    }

        else cout<<"element not found";
    cout<<"the array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}
