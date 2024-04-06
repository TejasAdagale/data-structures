#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class queue
{
    int capacity;
    int front, rear;
    int *ptr;

public:
    queue(int);
    void insert(int);
    void show();
    void deletee();
    int view_rear();
    int view_front();
    ~queue();
    bool full();
    bool empty();
    int count();
};
int queue::count()
{
    int i = front;
    int count = 1;
    if (front != -1)
        {for (i; i != rear; i++)
        {
            if (i == capacity - 1)
                i = 0;
            count++;
        }
        return count;
        }
    return 0;
}
bool queue::empty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}
bool queue::full()
{

    // or we can check the condition if( front==0&&rear==capacity-1||rear+1==front) then return true;
    int count = 0;
    int i = front;
    for (i; i != rear; i++)
    {
        if (i == capacity - 1)
            i = 0;
        count++;
    }

    if (count == capacity - 1)
        return true;

    return false;
}
queue::~queue()
{
    cout << "dellocating memory " << endl;
    delete[] ptr;
}
int queue::view_front()
{
    if (front == -1)
        return -1;
    else
        return ptr[front];
}
int queue::view_rear()
{
    if (rear == -1)
        return -1;
    else
        return ptr[rear];
}
void queue::deletee()
{
    if (rear == -1 && front == -1)
        cout << endl
             << "queue is empty " << endl;
    else if (front == rear && front != -1 && rear != -1)
    {
        front = -1;
        rear = -1;
    }
    else if (front == capacity - 1)
        front = 0;
    else
        front++;
}
void queue::show()
{
    int i = front;
    if (rear == -1 && front == -1)
        cout << endl
             << " now **** queue is empty " << endl;
    else
    {
        while (i != rear)
        {
            cout << ptr[i] << endl;
            i++;
        }
        cout << ptr[rear] << endl;
    }
}
void queue::insert(int data)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        ptr[rear] = data;
    }
    else if (rear != capacity - 1)
    {
        rear++;
        ptr[rear] = data;
    }
    else if (rear == capacity - 1 && front == 0)
        cout << endl
             << "insertion not possible" << endl;
    else if (rear + 1 == front)
        cout << endl
             << "insertion not possible" << endl;
    else
    {
        rear = 0;
        ptr[rear] = data;
    }
}
queue::queue(int cap)
{
    capacity = cap;
    front = -1;
    rear = -1;
    ptr = new int[capacity];
}
int main()
{
    queue o(5);
    o.insert(1);
    o.insert(2);
    o.insert(3);
    o.insert(4);
    o.insert(5);
    o.show();

    cout << endl
         << "get rear " << o.view_rear() << endl;
    cout << endl
         << "get front " << o.view_front() << endl;

    cout << endl
         << "is full" << o.full() << endl;

    o.deletee();
    o.deletee();
    o.deletee();
    o.show();

    cout << endl
         << "is full" << o.full() << endl;

    cout << endl
         << "is empty " << o.empty() << endl;

    o.deletee();
    o.deletee();

    cout << endl
         << "is empty " << o.empty() << endl;

    o.insert(10);
    o.insert(11);
    o.insert(10);
    o.insert(11);
    o.insert(3);

    o.show();

    cout << endl<< "count of element" << o.count() << endl;

    return 0;
}
