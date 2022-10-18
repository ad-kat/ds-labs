#include<iostream>
using namespace std;

class time1
{
    int hr;
    int mnt;
    int sec;

    public:
    void read()
    {
        cout<<"Enter hours:";
        cin>>hr;
        cout<<"Enter minutes:";
        cin>>mnt;
        cout<<"Enter seconds:";
        cin>>sec;
    }
    void display()
    {
        cout<<hr<<"hours "<<mnt<<"minutes "<<sec<<"seconds\n ";
    }
    time1 add(time1 ta,time1 tb)
    {
        int addmnt=0;
        int addhour=0;
        time1 sum;
        sum.sec=tb.sec+ta.sec;
        if(sum.sec>=60)
        {
            sum.sec-=60;
            addmnt=1;
        }
        sum.mnt=ta.mnt+tb.mnt;
        if(addmnt==1)
            sum.mnt++;
        if(sum.mnt>=60)
        {
            sum.mnt-=60;
            addhour=1;
        }
        sum.hr=ta.hr+tb.hr;
        if(addhour==1)
            sum.hr++;
        return sum;
    }
    time1 subtract(time1 ta,time1 tb)
    {
        int addhour=0;
        int addmnt=0;
        time1 dif;
        dif.sec=ta.sec-tb.sec;
        if(dif.sec<0)
        {
            dif.sec+=60;
            addmnt=1;
        }
        dif.mnt=ta.mnt-tb.mnt;
        if(addmnt==1)
            dif.mnt--;
        if(dif.mnt<0)
        {
            dif.mnt+=60;
            addhour=1;
        }
        dif.hr=ta.hr-tb.hr;
        if(addhour==1)
            dif.hr--;
        return dif;
    }
};

int main()
{
    time1 t1;
    time1 t2;
    time1 t;
    cout<<"Enter 1st time\n";
    t1.read();
    cout<<"Enter 2nd time\n";
    t2.read();

    time1 t3=t.add(t1,t2);
    cout<<"The time after addition is: ";
    t3.display();

    time1 t4=t.subtract(t1,t2);
    cout<<"The time after subtraction is: ";
    t4.display();
}
