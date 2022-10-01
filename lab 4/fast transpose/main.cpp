#include <iostream>
#include <string.h>
using namespace std;
class SM
{
public:
    int row[10],col[10],val[10];
    int trow[10],tcol[10],tval[10];
    int mat[10][10];
    int count;
    void get_mat(int r,int c)
    {
      for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
       cin>>mat[i][j];

    }

    }
    void create_sparse(int r,int c);
    void fast_trans();
    void printsparse();
    void printtrans();
};
void SM::printsparse()
{
   for(int i=0;i<=count;i++)
        cout<<row[i]<<"\t"<<col[i]<<"\t"<<val[i]<<endl;

    cout<<endl;
}
void SM::printtrans()
{
   for(int i=0;i<=count;i++)
        cout<<trow[i]<<"\t"<<tcol[i]<<"\t"<<tval[i]<<endl;

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

void SM::fast_trans()
{
    int i,j,start=0,k=1;
    int num_terms=val[0];
     trow[0]=col[0];
     tval[0]=val[0];
     tcol[0]=row[0];
for(i=1;i<=num_terms;i++)
        {
            for(j=1;j<=num_terms;j++)
            {
                if(col[j]==start)
                {
                    trow[k]=col[j];
                    tcol[k]=row[j];
                    tval[k]=val[j];
                    k++;
                }
                else
                    continue;
            }

           start++;
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


