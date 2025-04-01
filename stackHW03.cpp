//设计一个算法，利用顺序栈将一个十进制正整数d转换为r(2≦r≦16)进制的数。
#include<iostream>
#define MAXSIZE 1000
using namespace std;

struct stack {
    int num[MAXSIZE];
    int top;
};

void initstack(stack& s)
{
    s.top = -1;
}

bool push(stack& s, int input)
{
    if (s.top == MAXSIZE - 1)
        return  false;
    s.top++;
    s.num[s.top] = input;
    return true;
}

int pop(stack& s)
{
    if (s.top == -1)
        return -1;
    int output = s.num[s.top];
    s.top--;
    return output;
}

void print(stack s)
{
    while (s.top != -1)
    {
        cout << pop(s);
    }
}

void transform(stack& s, int x, int a)
{
    int remainder, quotient = x;
    while (quotient != 0)
    {
        remainder = quotient % a;
        quotient = (quotient - remainder) / a;
        push(s, remainder);
    }
}

int main()
{
    int x;
    int a;
    cout << "输入一个十进制数:";
    cin >> x;
    cout << "选择进制（2~16）:";
    cin >> a;
    if (a < 2 || a>16 || a % 1 != 0)
    {
        cout << "选择进制错误！" << endl;
        return 0;
    }

    stack s;
    initstack(s);
    transform(s, x, a);
    
    cout << x << "转化成的" << a << "进制数为：";
    print(s);
    cout << endl;

    return 0;
}