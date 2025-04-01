//���һ���㷨������һ��˳��ջ��һ��ѭ�������е�����Ԫ�ص���������ͷ���β����β���ͷ��
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
        cout << "ѭ���б�Ϊ�գ�����ʧ�ܡ�" << endl;
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
    cout << "��ͷ<< ";
    while (q.front != q.rear)
    {
        cout << deletecirqueue(q) << " ";
    }
    cout << "<<��β" << endl;
}

int main()
{
    stack s;
    cirqueue q;
    initstack(s);
    initcirqueue(q);
    int e;
    int x;

    cout << "�㽫Ҫ������ٸ�������";
    cin >> x;
    cout << "����" << x << "��������";
    for (int i = 1; i <= x; i++)
    {
        cin >> e;
        entercirqueue(q, e);
    }
    cout << "ԭѭ�����У�";
    print(q);
    reverse(s, q);
    cout << "���ú��ѭ�����У�";
    print(q);

    return 0;
}