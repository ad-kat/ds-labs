#include <iostream>
using namespace std;

void sortarray(int n, int* p)
{
    int  temp;

    // Sort the numbers using pointers
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (*(p + i) > *(p + j))
            {

                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

}
void display(int n, int* p)
{
    for (int i = 0; i < n; i++)
        cout<< (*(p + i))<<"\t";
}

// Driver code
int main()
{
    int n;
    int arr[20];
    cout<<"enter length of the array:";
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sortarray(n, arr);
    display(n,arr);

    return 0;
}
