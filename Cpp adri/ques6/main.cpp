#include<iostream>
#include<string.h>
class Task{
public:

    char username[100];
    char Taskname[100];
    int Tasksize;
    int arrivaltime;
    int priority;
    Task *next;
    Task(int p)
        {
            priority = p;
            next = NULL;
        }

    void setdata(char user[], char Task[], char tsize, char atime)
        {
            strcpy(username, user);
            strcpy(Taskname, Task);
            Tasksize = tsize;
            arrivaltime = atime;
        }
};
class Priority_Q
{
public:
    Task *head;
    Priority_Q { head = NULL; }
    void enqueue(int p){
        Task *T = new Task(p);
        if(head == NULL)
        {
            head = T;
            return;
        }

        else{
            Task *curr = head;
            while(curr->priority > p && curr->next != NULL)
            {
                curr = curr->next;
            }
            T->next = curr->next;
            curr->next = T;
        }
    }
    Task *dequeue()
    {
        Task *temp = head;
        head = head->next;
        return temp;
    }
    void display()
    {

    }




};
