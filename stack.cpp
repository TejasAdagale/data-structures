#include<iostream>
#include"Dinamic array.cpp"
#include<stdio.h>
using namespace std;


class stack:private array
{
public:
    stack(int);
    void push(int);
    int peek();
    void pop();
    ~stack();
    virtual bool isfull();
    virtual bool isempty();
    //void revsese
};
bool stack::isempty()
{
    return array::isempty();
}
bool stack::isfull()
{
    return array::isfull();
}
stack::~stack(){}
void stack::pop()
{
    if(isempty())
        cout<<"stack underflow"<<endl;
    else
        del(count()-1);
}
int stack::peek()
{
    if(!isempty())
        return get(count()-1);
    else
        cout<<"stack is empty"<<endl;
    return 0;
}
void stack::push(int data)
{
    if(isfull())
        cout<<"stack is overflowing "<<endl;
    else
        append(data);
}
stack::stack(int cap):array(cap){}

int main()
{
    stack o(5);
    o.push(10);
    o.push(20);
    o.push(30);
    o.push(40);

    cout<<o.peek()<<endl;
    o.pop();
    cout<<o.peek()endl;

    return 0;
}
