#include <iostream>
#include <string.h>
#define maxs 50
using namespace std;
class CQu{
private:
    int arr[maxs], front, rear;
public:
    CQu(){
        rear=-1;front=-1;
    }
    void addCQ(int );
    void queue_full()
    {
        rear=(rear+(maxs-1))%maxs;
        return;
    }
    int DeleteCQ();
    void display();
};
void CQu::addCQ(int item){
    rear=(rear+1)%maxs;
if(front==rear)
{
    queue_full();
    return;
    }

else{
    arr[rear]=item;
}
}
int CQu::DeleteCQ()
{
 if (front==rear)
    cout<<"CQ empty"<<endl;
else
    {
      front=(front+1)%maxs;
      return arr[front];
    }
}
void CQu::display()
{
    int i;
    for(i = front; i<=rear;i++)
        {
    cout<<arr[i]<<"\t";
    }
}

int main(){
CQu obj;
int choice=1,x;
while(choice<4&&choice>0)
{
    cout<<"1.Insert element"<<endl;
    cout<<"2.Delete element"<<endl;
    cout<<"3.Display elements"<<endl;
    cout<<"Input any other number to exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"Enter element to insert:";
        cin>>x;
        obj.addCQ(x);
        break;
        case 2:cout<<"Deleted element is:";
        cout<<obj.DeleteCQ()<<endl;
        break;
        case 3:cout<<"Circular Elements:";
        obj.display()
        cout<<endl;;
        break;
        default:cout<<"You have reached the end";
        break;
    }
}
return 0;
}



