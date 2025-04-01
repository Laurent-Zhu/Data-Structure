//���һ��ѭ������QUEUE<T>����data[0.. MaxSize-1]��Ŷ���Ԫ�أ���front��rear�ֱ���Ϊ��ͷ�Ͷ�βָ�룬������һ����־tag��ʶ���п���
// �գ�false�����������true������������front == rear������Ϊ�ӿջ������������Ҫ����ƶ��е���ػ��������㷨��
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
    else cout << "���зǿ�Ҳ����" << endl;
}

int gethead(cirqueue q)
{
    if (q.tag == false)
    {
        cout << "����Ϊ��" << endl;
    }
    else return q.element[q.front];
}

int main()
{
    cirqueue QUEUE;

}
