// CDLL data structure

#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct node
{
    int item;
    node *pre;
    node *next;
};

class CDLL
{
private:
    node *head;
public:
    CDLL()
    {
        head=NULL;
    }


    void show();
    void infirst(int);
    void inend(int);
    node* searchnode(int);
    void inafter(node *,int );

    void delhead();
    void delend();
    void delnode(node *);

    ~CDLL()
    {
        cout<<"deallocating memory"<<endl;
        while(head)
            delhead();
    }

};

void CDLL::delnode(node *t)
{
    if (t)
    {
        if(head->next==head)
            head=NULL;
        else{
            t->pre->next=t->next;
            t->next->pre=t->pre;
            if(head==t)
                head=t->next;
            }
            delete t;
    }
    else
        cout<<"deletion not possible "<<endl;
}

void CDLL::delend()
{
    if(head)
    {
        if(head->next==head)
        {
            delete head;
            head==NULL;
        }
        else
        {
            node *t=head->pre;
            head->pre=t->pre;
            t->pre->next=head;
            delete t;
        }
    }
    else
        cout<<"deletion not possible "<<endl;
}

void CDLL::delhead()
{
    if(head)
    {
        if(head->next==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            node *t=head;
            head=head->next;
            head->pre=t->pre;
            t->pre->next=head;
            delete t;
        }
    }
    else
        cout<<"deletion not not possible "<<endl;
}

void CDLL::inafter(node *t,int x)
{
    if(t)
    {
        node *temp=new node;
        temp->item=x;
        node *y=head;
        do
        {
            if(y->item==t->item)
            {
                temp->pre=y;
                temp->next=y->next;
                y->next->pre=temp;
                y->next=temp;
            }
            y=y->next;
        } while (y!=head);  
    }
    else
        cout<<"insertion not possible "<<endl;
}

node* CDLL::searchnode(int x)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *t=head;
        do
        {
            if(t->item==x)
                return t;
            t=t->next;
        } while (t!=head);
        return NULL;
    }
}

void CDLL::inend(int x)
{
    node *n=new node;
    n->item=x;
    if(head)
    {
        n->pre=head->pre;
        n->next=head;
        head->pre->next=n;
        head->pre=n;
    }
    else
    {
        n->next=n;
        n->pre=n;
    }
}

void CDLL::infirst(int x)
{
    node *n=new node;
    n->item=x;
    if(head)
    {
        n->pre=head->pre;
        n->next=head;
        head->pre->next=n;
        head->pre=n;
    }
    else
    {
        n->next=n;
        n->pre=n;
    }
     head=n;
}

void CDLL::show()
{
    node *t=head;
    do
    {
        cout<<t->item<<endl;
        t=t->next;
    }
    while(t!=head);
    cout<<endl;
}

int main()
{
    CDLL obj;
    cout<<"inserting elements at start"<<endl;
    obj.infirst(1);
    obj.infirst(2);
    obj.infirst(3);
    obj.show();
    cout<<"inserting elements at end"<<endl;
    obj.inend(4);
    obj.inend(5);
    obj.show();
    cout<<"searting a node and getting address "<<endl;
    cout<<obj.searchnode(4)<<endl;
    obj.show();
    cout<<"inserting element after a node "<<endl;
    obj.inafter(obj.searchnode(4),99);
    obj.show();
    cout<<"deleting node at start"<<endl;
    obj.delhead();
    obj.show();
    cout<<"deleting node at end"<<endl;
    obj.delend();
    obj.show();
    cout<<"deleting node"<<endl;
    obj.delnode(obj.searchnode(4));
    obj.show();
}
