#include <iostream>
#include <string.h>
using namespace std;
class SM
{
public:
    int row[10],col[10],val[10];
    int mat[10][10];
    int count;
    void get_mat(int r,int c)       //enter matrix
    {
        cout<<"Enter elements";
      for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)

       cin>>mat[i][j];
    }
    void create_sparse(int r,int c);
    void printsparse();
    int getByRow(int r,int c);
    int getNumElementsInColumn(int c);
};
void SM::printsparse()
{
   for(int i=0;i<=count;i++)
        cout<<row[i]<<"\t"<<col[i]<<"\t"<<val[i]<<endl;

    cout<<endl;
}

void SM::create_sparse(int r,int c)
{
    int c1=0,k=1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(mat[i][j]!=0)
    {
        c1++;
        row[k]=i;
        col[k]=j;
        val[k]=mat[i][j];
        k++;
    }
    row[0]=r;col[0]=c;
    val[0]=c1;count=c1;
}
int SM::getByRow(int r,int c)
{
    int flag=0;
    for(int i=1;i<=val[0];i++)
    {
        if(r==row[i])
        {
          if(col[i]==c)
          {
             flag=1;
             return val[i];
          }

        }
    }
    if(flag==0)
        return -1;
}
int SM::getNumElementsInColumn(int c)
{
    int count=0;
    for(int i=1;i<=val[0];i++)
    {
        if(col[i]==c)
            count++;
    }
    return count;
}
int main()
{
  SM a;
  int r,c;
  cout<<"Enter number of rows"<<endl;
cin>>r;
cout<<"Enter number of columns"<<endl;
cin>>c;
 a.get_mat(r,c);
a.create_sparse(r,c);
cout<<"Enter column to count:";
int co;cin>>co;
int total=a.getNumElementsInColumn(co);
cout<<total<<" non zero elements found";


  /*int ro,co;
  a.printsparse();
 cout<<"Enter r and c coordinates :";
cin>>ro>>co;
int res=a.getByRow(ro,co);
 cout<<res<<"found";*/
  /*SM a,b;
int r, c;
cout<<"Enter number of rows"<<endl;
cin>>r;
cout<<"Enter number of columns"<<endl;
cin>>c;
a.get_mat(r,c);
a.create_sparse(r,c);
a.fast_trans();
a.printsparse();
a.printtrans(); */
return 0;
}

