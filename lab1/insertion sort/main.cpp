#include <iostream>
using namespace std;

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

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";

}

int main()
{
    int arr2[30],N2,i;
    cout<<"enter number of elements"<<endl;
    cin>>N;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<N2;i++)
        cin>>arr2[i];

    inSort(arr2, N2);
    display(arr2, N2);

    return 0;
}
