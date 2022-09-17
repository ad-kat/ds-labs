#include<iostream>
using namespace std;
class Student{
char name[20];
int rollno;
char grade[10];
public:
    void  input();
    void display();
    void sorting(int);
}s[100];
void Student::input(){
    cout<<"Enter name: ";
    fflush(stdin);
    cin.get(name,20);

    cout<< "Enter roll number: ";
    fflush(stdin);
    cin >> rollno;

    cout<<"Enter grade: ";
    fflush(stdin);
    cin.get(grade,10);


}
void Student::display(){


    cout << "\n"<< name << "\t" << rollno << "\t" << grade;
}
void Student::sorting(int n){
    int i, j;
    for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++)
            {
               if(s[j].rollno>s[j+1].rollno){
            Student temp = s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
            }

        }
    }

}
int main(){
int n, i;
cout<<"Enter number of students"<<endl;
cin>>n;

for(i=0;i<n;i++){
    cout<<"Enter Details of student " << i+1 << endl;
    s[i].input();
}
s[100].sorting(n);
cout<<"Details of student " << i+1 << endl;
for(i=0;i<n;i++){

    s[i].display();
    cout<<"\n";
}
}
