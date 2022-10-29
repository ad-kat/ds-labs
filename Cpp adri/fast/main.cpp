
#include <iostream>
#include <string.h>
using namespace std;
class SM
{
public:
    int arow[10],acol[10],aval[10];
    int brow[10],bcol[10],bval[10];
    int mat[10][10];
    int count;
    void get_mat(int r,int c)
    {
        cout<<"Enter elements";
      for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)

       cin>>mat[i][j];
    }
    void create_sparse(int r,int c);
    void fast_trans();
    void printsparse();
    void printtrans();
};
void SM::printsparse()
{
   for(int i=0;i<=count;i++)
        cout<<arow[i]<<"\t"<<acol[i]<<"\t"<<aval[i]<<endl;

    cout<<endl;
}
void SM::printtrans()
{
   for(int i=0;i<=count;i++)
        cout<<brow[i]<<"\t"<<bcol[i]<<"\t"<<bval[i]<<endl;

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
        arow[k]=i;
        acol[k]=j;
        aval[k]=mat[i][j];
        k++;
    }
    arow[0]=r;acol[0]=c;
    aval[0]=c1;count=c1;
}

void SM::fast_trans()
{
    int colen=acol[0];
    int column[colen],i,j,c1;
     brow[0]=acol[0];
     bval[0]=aval[0];
     bcol[0]=arow[0];
    for(i=0;i<colen;i++)
        {
            c1=0;
            for(j=1;j<=aval[0];j++)
            {
                if(acol[j]==i)
                    c1++;
            }
            column[i]=c1;
        }
    int rowindex[colen];
    rowindex[0]=1;
    for(i=1;i<colen;i++)
        {
          rowindex[i]=rowindex[i-1]+column[i-1];
        }
      for(i=1;i<=aval[0];i++)
        {
            int k=acol[i];
            int pos=rowindex[k];
            brow[pos]=acol[i];
            bval[pos]=aval[i];
            bcol[pos]=arow[i];
            rowindex[k]++;
        }

}

int main()
{
  SM a,b;
int r, c;
cout<<"Enter number of rows"<<endl;
cin>>r;
cout<<"Enter number of columns"<<endl;
cin>>c;
a.get_mat(r,c);
a.create_sparse(r,c);
a.fast_trans();
a.printsparse();
a.printtrans();
return 0;
}


