#include <iostream>

using namespace std;

int main()
{
   int i,j=0;
   char x[100],y[100],z[100];
   int xlen=0,ylen=0,w=0;

   cout << "Enter main string: "<<endl;
    cin.get(x,100);
    fflush(stdin);
    while(x[xlen]!='\0')
        xlen++;

    cout << "Enter the substring "<<endl;
    cin.get(y,100);
    fflush(stdin);
    while(y[ylen]!='\0')
        ylen++;

        /*.......*/

        char sent[20][20];
        int col=0;

        for(i=0;i!='\0';i++)
        {
           if(x[i]==' ')
           {
               col++;
               j=0;
           }
           else
            {
            sent[j][col]=x[i];
            j++;
           }
        }
        for(i=0;i<col;i++)
        {
           cout<<"array";
        }
    return 0;
}
