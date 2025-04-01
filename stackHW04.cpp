//设计一个算法，利用一个顺序栈将一个循环序列中的所有元素倒过来，队头变队尾，队尾变队头。
#include<iostream>
#define MAXSIZE 1000
using namespace std;

struct stack {
    int num[MAXSIZE];
    int top;
};

struct cirqueue {
    int element[MAXSIZE];
    int front;
    int rear;
};

void initstack(stack& s)
{
    s.top = -1;
}

bool pushstack(stack& s, int input)
{
    if (s.top == MAXSIZE - 1)
        return  false;
    s.top++;
    s.num[s.top] = input;
    return true;
}

int popstack(stack& s)
{
    if (s.top == -1)
        return -1;
    int output = s.num[s.top];
    s.top--;
    return output;
}

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

void reverse(stack& s, cirqueue& q)
{
    if (q.rear % MAXSIZE == q.front % MAXSIZE)
    {
        cout << "循环列表为空，操作失败。" << endl;
        return;
    }
    while (q.front != q.rear)
    {
        pushstack(s, deletecirqueue(q));
    }
    while (s.top != -1)
    {
        entercirqueue(q, popstack(s));
    }
}

void print(cirqueue q)
{
    cout << "队头<< ";
    while (q.front != q.rear)
    {
        cout << deletecirqueue(q) << " ";
    }
    cout << "<<队尾" << endl;
}

int main()
{
    stack s;
    cirqueue q;
    initstack(s);
    initcirqueue(q);
    int e;
    int x;

    cout << "你将要输入多少个整数？";
    cin >> x;
    cout << "输入" << x << "个整数：";
    for (int i = 1; i <= x; i++)
    {
        cin >> e;
        entercirqueue(q, e);
    }
    cout << "原循环序列：";
    print(q);
    reverse(s, q);
    cout << "逆置后的循环序列：";
    print(q);

    return 0;
}