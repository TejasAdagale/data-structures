#include<iostream>
using namespace std;

class Dynarray
{
    int capacity,lastindex;
    int *start=new int [capacity];


public:
    Dynarray(int s)
    {
        int i=0;
        capacity=s;
        for(i;i<capacity;i++)
        {
            cin>>start[i];
            lastindex=i;
        }
    }

    void dublearray();
    void display();
    void halfarray();
    int capacity1();
    bool Empty();
    void append(int);
    void insert_e(int ,int);
    void edit(int,int);
    int countno();
    int finde(int);
     ~Dynarray();
    bool isfull();
    void del(int );



};
void Dynarray::del(int index)
{
    if(Empty())
        cout<<"array is underflowing: "<<endl;
    else if(index<0||index>lastindex)
        cout<<"invalid index"<<endl;
    else
    {
        int i;
        for(i=index;i<lastindex;i++)
            start[i]=start[i+1];
        lastindex--;
    }
}
bool Dynarray::isfull()
{
    return lastindex==capacity-1;
}

int Dynarray::finde(int data)
{
    int i;
    for(i=0;i<=capacity;i++)
    {
        if(start[i]==data)
            {
                return i;
            }

    }
    return -1;
}
Dynarray::~Dynarray()
{
    cout<<"deallocating dynamic array ";
    delete []start;
}

int Dynarray::countno()
{
    int countx=0;
    if(start<0)
        return -1;
    else
    {
        int i;
        for(i=0;i<lastindex;i++)
            countx++;
    }
    return countx;
}

void Dynarray::edit(int index ,int data)
{
    if(index>lastindex||lastindex<0)
        cout<<"cant perform edit "<<endl;
    else
        {
            int i;
            for(i=0;i<=capacity;i++)
            {
                if(i==index)
                    start[index]=data;
            }
        }
}
void Dynarray:: insert_e(int index,int data)
{
    int i;
    if(index>lastindex)
        dublearray();
     for(i=index;i<=lastindex;i--)
        {
            start[i+1]=start[i];
        }
        start[index]=data;

}
void Dynarray::append(int data)
{
    if(lastindex==capacity-1)
        dublearray();
    lastindex++;
    start[lastindex]=data;
}
bool Dynarray::Empty()
{
    return lastindex==-1;
}
int Dynarray::capacity1()
{
    return capacity;
}
void Dynarray::halfarray()
{
    int sizeb=capacity/2;
    int *head=new int [sizeb];
    int i=0;
    for (i;i<sizeb;i++)
    {
        head[i]=start[i];
        lastindex=i;
    }
    capacity=sizeb;
    delete[]start;
    start=head;
    cout<<endl;
}
void Dynarray::display()
{
    cout<<endl;
    int i;
    for(i=0;i<capacity;i++)
        {
            cout<<start[i]<<endl;
        }
        cout<<endl;
}
void Dynarray::dublearray()
{
    int sizea=capacity*2;
    int *head=new int [sizea];
    int i=0;
    for (i;i<sizea;i++)
    {
        head[i]=start[i];
    }
    capacity=sizea;
    delete[]start;
    start=head;
    cout<<endl;
}

int main()
{
    Dynarray o(5);
    o.append(6);
    o.append(7);
    o.display();

    cout<<"size of array"<< o.capacity1()<<endl;
    cout<<"no. of elements "<<o.countno()<<endl;

    cout<<"is empty"<<o.Empty()<<endl;
    cout<<"is full"<<o.isfull()<<endl;

    cout<<"find element at index"<<o.finde(5)<<endl;



}
