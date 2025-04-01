//��һ����������a, ���һ���㷨��������ż��λ��Ԫ���ƶ�����������λ��Ԫ��ǰ�棬Ҫ�����ǵ���Դ��򲻱䡣
//���磬a = { 1, 2, 3, 4, 5, 6, 7, 8 },�ƶ���a = { 2, 4, 6, 8, 1, 3, 5, 7 }��
#include<iostream>
#define MAXSIZE 1000
using namespace std;

struct cirqueue {
    int element[MAXSIZE];
    int front;
    int rear;
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

void dispose(int* a, int n)
{
    cirqueue q;
    initcirqueue(q);
    int i;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            entercirqueue(q, a[i]);//ż��λԪ�ؽ���
        }
    }
    for (i = 0; i < n; i++)
    {
        if ((i + 1) % 2 != 0)
        {
            entercirqueue(q, a[i]);//����λԪ�ؽ���
        }
    }
    i = 0;
    while (q.rear != q.front)
    {
        a[i] = deletecirqueue(q);//Ԫ�ػص�����
        i++;
    }
}

void printarray(int* a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "��Ҫ���������������";
    cin >> n;
    cout << "������" << n << "��������";
    int* a = (int*)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "ԭ���飺";
    printarray(a, n);
    dispose(a, n);
    cout << "��ż��λԪ�طŵ�����λԪ��֮ǰ��";
    printarray(a, n);
    free(a);

    return 0;
}