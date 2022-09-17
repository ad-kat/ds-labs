#include <iostream>

using namespace std;
class time
{
int hr,minute,sec;
public:
    void add(time x,time y);
    void subtract(time x,time y);
    void display();
    void read();


};
void time::read()
{
    cout<<"\n hours:";
    cin>>hr;
    cout<<"\n minutes:";
    cin>>minute;
    cout<<"\n seconds:";
    cin>>sec;
}
void time::display()
{
    cout<<"\n"<<hr<<" hours,"<<minute<<" minutes,"<<sec<<" seconds.";



}
void time::add(time x,time y)
{
    hr=x.hr+y.hr;
    minute=x.minute+y.minute;
    sec=x.sec+y.sec;

}
void time::subtract(time x,time y)
{
    hr=x.hr-y.hr;
    minute=x.minute-y.minute;
    sec=x.sec-y.sec;

}
int main()
{
    time a,b,c,d;
    a.read();
    b.read();
    c.add(a,b);
    d.subtract(a,b);
    a.display();
    b.display();
    c.display();
    d.display();
}
