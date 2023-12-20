#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int item;
    node*next;
};

class linkedlist
{
    int  count;
    node *start;
    public:
    linkedlist()
    {
        start=NULL;
    }

	void create(int);

    void insertatstart(int);
    void insertatend(int);
    void searchat(int);
    void insertafter(int,int);

    void deleteatstart();
    void deleteatend();
    void deleteafter(int);

    void display()
    {
        
        node *temp=start;
        while(temp!=NULL)
        {
            cout<<temp->item<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    ~linkedlist()
    {
    	cout<<endl;
        cout<<"delocating";
        delete start;
    }

    int countnode();
    void reverse();
    node* mid();

};

node *linkedlist::mid()
{
	if(start)
	{
		if(count%2!=0)
		{
			node *t=start;
			int x=count/2;
			int i=1;
			while(i!=x)
			{
				t=t->next;
				i++;
			}
			return t;
		}
		return NULL;
	}
	return NULL;
}

void linkedlist::reverse()
{
    node *p=start;
    node *q=p->next;
    node *r=q->next;
    while(q->next!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    start->next=NULL;
    start=q;
    //cout<<q->item<<endl;
}

int linkedlist::countnode()
{
    node *t=start;
    count =0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}

void linkedlist::deleteafter(int data)
{
    cout<<endl<<"delete after";
    if(start==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
    node *x=start;
    while(x!=NULL)
    {
        if(x->item==data)
            break;
        x=x->next;
    }
    }
}
void linkedlist::deleteatend()
{
    cout<<endl<<"delete at end";
    node *x=start;
    if(start==NULL)
    {
        cout<<"list is empty";
    }
    else
    {while(x->next->next!=NULL)
    {
        x=x->next;
    }
    delete x->next;
    x->next=NULL;
    }
}
void linkedlist::deleteatstart()
{
    cout<<endl<<"delete at start";
    node *temp=start;
    start=start->next;
    delete temp;
}
void linkedlist::insertafter(int d,int data )
{
    cout<<endl<<"insert after";
    node *x=start;
    node *temp =new node;
     while(x!=NULL)
    {
        if(x->item==d)
        {
            break;
        }
        x=x->next;
    }
    temp->item=data;
    temp->next=x->next;
    x->next=temp;
}

void linkedlist::searchat(int data)
{
    cout<<endl<<"search at";
    node *x=start;
    int k=0;
    while(x!=NULL)
    {
        if(x->item==data)
        {
            k=1;
            cout<<"element found at index "<<x;
            break;
        }
        x=x->next;
    }
    if(k==0)
        cout<<"element not found";
}

void linkedlist::insertatend(int data)
{
    node *temp=new node;
        temp->item=data;
        temp->next=NULL;

    if (start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        node *x=start;
        while(x!=NULL)
        {
            x=x->next;
        }
        x->next=temp;
    }
    cout<<endl<<"insert at end";
}
void linkedlist::insertatstart(int data)
{
    cout<<endl<<"insert at start";
    node *temp=new node;
    temp->item=data;
    if (start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

void linkedlist::create(int size)
{
	   int i=1;
        node*n=new node;
        start=n;
        cout<<"enter item "<<endl;
        cin>>n->item;
        	n->next=NULL;
        while(i<size)
        {
            node *t=new node;
            cout<<"enter item"<<endl;
            cin>>t->item;
            n->next=t;
            n=n->next;
            t=t->next;
            i++;
        }
}

int main()
{
    linkedlist obj;
    obj.insertatstart(3);
    obj.insertatstart(2);
    obj.insertatstart(1);
    obj.insertatstart(10);
    obj.insertatstart(-1);
    obj.display();
    obj.reverse();
    obj.display();
    cout<<obj.countnode()<<endl;
	cout<<obj.mid();
    return 0;
}














