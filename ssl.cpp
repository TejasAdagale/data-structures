#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
    int no;
    string name;
    node *next;
};

class sll
{
public:
    node *start;

    sll();
    void create(int);
    void president(int ,string);
    void display();
};
void sll::display()
{
    node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->no<<endl;
        cout<<temp->name<<endl;
        temp=temp->next;
    }
}
void sll::president(int x,string n)
{
    node *temp=new node;
    temp->no=x;
    temp->name=n;
    temp->next=start;
    start=temp;
}
void sll::create(int size)
{
    int i=1;
    node *temp=new node;
    start=temp;
    cout<<"enter value of prn no := ";
    cin>>temp->no;
    cout<<"enter the name of member := ";
    cin>>temp->name;
    temp->next=NULL;
    while(i<size)
    {
        node *t=new node;
        cout<<"enter value of prn no := ";
        cin>>t->no;
        cout<<"enter the name of member := ";
        cin>>t->name;
        temp->next=t;
        temp=t;
        i++;
    }
    temp->next=NULL;
}
sll::sll()
{
    start=NULL;
}

int main()
{
    sll obj;
    obj.create(6);
    obj.president(1,"tejas");
    obj.display();
    return 0;


}

