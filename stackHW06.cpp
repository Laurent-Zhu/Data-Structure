//设计一个循环队列QUEUE<T>，用data[0.. MaxSize-1]存放队列元素，用front和rear分别作为队头和队尾指针，另外用一个标志tag标识队列可能
// 空（false）或可能满（true），这样加上front == rear可以作为队空或队慢的条件，要求设计队列的相关基本运算算法。
#include<iostream>
#define MAXSIZE 1000
using namespace std;

struct cirqueue {
    int element[MAXSIZE];
    int front;
    int rear;
    bool tag;
};

void initcirqueue(cirqueue& q)
{
    q.front = q.rear = 0;
}

bool entercirqueue(cirqueue& q, int e)
{
    if ((q.rear + 1) % MAXSIZE == q.front)
    {
        return  false;
    }
    q.element[q.rear] = e;
    q.rear = (q.rear + 1) % MAXSIZE;
    return true;
}

int deletecirqueue(cirqueue& q)
{
    if ((q.rear + 1) % MAXSIZE == q.front)
    {
        return -1;
    }
    int e = q.element[q.front];
    q.front = (q.front + 1) % MAXSIZE;
    return e;
}

void isFull(cirqueue q)
{
    if (q.front == q.rear)
    {
        q.tag = false;
    }
    else if ((q.rear + 1) % MAXSIZE == q.front)
    {
        q.tag = true;
    }
    else cout << "队列非空也非满" << endl;
}

int gethead(cirqueue q)
{
    if (q.tag == false)
    {
        cout << "队列为空" << endl;
    }
    else return q.element[q.front];
}

int main()
{
    cirqueue QUEUE;

}
