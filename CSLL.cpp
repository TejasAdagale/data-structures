//CSLL data structure

#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

struct node
{
	node *next;
	int item;
};

class CSLL
{
	private:
	node *last;
	int count;

	public:
	CSLL()
	{	last=NULL;	}

	void show();

	void infirst(int);
	void inend(int);
	void inafter(int,int);

	void delfirst();
	void delend();
	void delafter(int);

	int search_item(int );

	~CSLL()
	{
	    cout<<"deallocating memory ";
	    while(last)
            delfirst();
	}

};

int CSLL::search_item(int x)
{

    if(last==NULL)
        return -1;
    else
    {
        node *t=last->next;
        while(t!=last)
        {
            if(t->item==x)
                return 1;
            t=t->next;
        }
        return -1;
    }
}

void CSLL::delafter(int x)
{
    int flag=0;
    if(last==NULL)
        cout<<"deletion not possible"<<endl;
    else if(last->next==last)
    {
        if(last->item==x)
        {
            delete last;
            last=NULL;
        }
        else
            cout<<"deletion not possible"<<endl;
    }
    else
    {
        int flag =0;
        node *t=last;
        while(t->next!=last)
        {
            if(t->item==x)
            {
                node *p=t->next;
                t->next=p->next;
                delete p;
            }
            t=t->next;
        }

    }
}

void CSLL::delend()
{
    if(last==NULL)
        cout<<"deletion not possible :"<<endl;
    else if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else
    {
       node *t=last;
       int flag=0;
       while(t->next!=last)
       {
           flag=1;
           t=t->next;
       }
       if(flag==1)
       {
           t->next=last->next;
           delete last;
           last=t;
       }
    }

}

void CSLL::delfirst()
{
    if(last==NULL)
        cout<<"deletion not possible :"<<endl;
    else if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else
    {
        node *t=last->next;
        last->next=t->next;
        delete t;
    }
}

void CSLL::inafter(int after,int x)
{
    node *temp=new node;
    temp->item=x;
    if(last==NULL)
        cout<<"insertion not possible "<<endl;
    else
    {
        node *t=last->next;
        while(t!=last)
        {
            if(t->item==after)
            {
                temp->next=t->next;
                t->next=temp;
            }
            t=t->next;
        }
    }
}

void CSLL::inend(int x)
{
    node *temp=new node;
    temp->item=x;
    if(last==NULL)
    {
        last=temp;
        last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void CSLL::infirst(int x)
{
    node *temp=new node;
    temp->item=x;
    if(last==NULL)
    {
        last=temp;
        last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
    }
}

void CSLL::show()
{
   node *temp=last->next;
   if(last==NULL)
    cout<<"list is empty :";
   else
   {
        do
        {
           cout<<temp->item<<endl;
           temp=temp->next;
        }
        while(temp!=last);
        cout<<last->item;
   }
   cout<<endl<<endl;

}

int main()
{
    CSLL obj;
    cout<<"performing insertion at start "<<endl;
    obj.infirst(5);
    obj.infirst(9);
    obj.infirst(15);
    obj.infirst(35);
    obj.show();

    cout<<"performing insertion at end"<<endl;
    obj.inend(1);
    obj.inend(11);
    obj.show();

    cout<<"performing insertion after "<<endl;
    obj.inafter(35,136);
    obj.inafter(5,16);
    obj.show();

    cout<<"performing deletion at start"<<endl;
    obj.delfirst();
    obj.show();

    cout<<"performing deletion at end"<<endl;
    obj.delend();
    obj.show();

    cout<<"performing deletion after"<<endl;
    obj.delafter(5);
    obj.show();

    cout<<"performing search if element is not present "<<obj.search_item(16)<<endl;
    cout<<"performing search when element is present "<<obj.search_item(15)<<endl;
    return 0;
}
