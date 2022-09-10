/*. Write a program to sort a given list of elements .Write the user defined functions to
sort using
i.) Bubble Sort
ii.) Selection Sort
iii.) Insertion Sort*/

#include <iostream>

using namespace std;


void bubsort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
         for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

}
void inSort(int arr[], int n)
{
    int i, num, j;
    for (i = 1; i < n; i++)
    {
        num = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
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
                int temp=arr[min_idx];
                arr[min_idx]=arr[i];
                arr[i]=temp;
            }
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";

}
int main()
{
    int arr[30],N,i;
    cout<<"Implementing BUBBLE sort"<<endl;
    cout<<"enter array length"<<endl;
    cin>>N;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<N;i++)
        cin>>arr[i];

    bubsort(arr, N);
    display(arr, N);

     int arr2[30],N2;
     cout<<"\n"<<"Implementing INSERTION sort"<<endl;
    cout<<"enter number of elements"<<endl;
    cin>>N2;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<N2;i++)
        cin>>arr2[i];

    inSort(arr2, N2);
    display(arr2, N2);

    int arr3[30],N3;
    cout<<"/n"<<"Implementing SELECTION sort"<<endl;
    cout<<"enter number of elements"<<endl;
    cin>>N3;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<N;i++)
        cin>>arr3[i];

    selsort(arr3, N3);
    display(arr3, N3);

    return 0;
}
