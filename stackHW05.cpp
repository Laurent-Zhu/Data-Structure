//有一个整数数组a, 设计一个算法，将所有偶数位的元素移动到所有奇数位的元素前面，要求它们的相对次序不变。
//例如，a = { 1, 2, 3, 4, 5, 6, 7, 8 },移动后a = { 2, 4, 6, 8, 1, 3, 5, 7 }。
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
            entercirqueue(q, a[i]);//偶数位元素进队
        }
    }
    for (i = 0; i < n; i++)
    {
        if ((i + 1) % 2 != 0)
        {
            entercirqueue(q, a[i]);//奇数位元素进队
        }
    }
    i = 0;
    while (q.rear != q.front)
    {
        a[i] = deletecirqueue(q);//元素回到数组
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
    cout << "你要输入的整数个数：";
    cin >> n;
    cout << "请输入" << n << "个整数：";
    int* a = (int*)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "原数组：";
    printarray(a, n);
    dispose(a, n);
    cout << "将偶数位元素放到奇数位元素之前：";
    printarray(a, n);
    free(a);

    return 0;
}