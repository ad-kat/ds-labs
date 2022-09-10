/*. Write a program to sort a given list of elements .Write the user defined functions to
sort using
i.) Bubble Sort
ii.) Selection Sort
iii.) Insertion Sort*/
#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";

}

int main()
{
    int arr[30],N,i;
    cout<<"enter number of elements"<<endl;
    cin>>N;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<N;i++)
        cin>>arr[i];

    selsort(arr, N);
    display(arr, N);

    return 0;
}

void selsort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {


        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;


        if(min_idx!=i)
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    }
}
