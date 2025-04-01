//给定一个字符串str，设计一个算法，采用顺序栈判断strs是否为形如“序列1@序列2”的合法字符串，其中序列2是序列1的逆序，在str中恰好只有一个@字符。
#include<iostream>
#include<string>
#define MAXSIZE 100
using namespace std;

struct stack {
    char str[MAXSIZE];
    int top;
};

void initstack(stack& s)
{
    s.top = -1;
}

bool push(stack& s ,char input)
{
    if (s.top == MAXSIZE - 1)
        return  false;
    s.top++;
    s.str[s.top] = input;
    return true;
}

bool pop(stack& s ,char& output)
{
    if (s.top == -1)
        return false;
    output = s.str[s.top];
    s.top--;
    return true;
}
int judge(stack& s, int& i, char& output, string& str)
{
    for (i = 0;; i++)
    {
        if (s.top < MAXSIZE)
        {
            if (str[i] == '@' || i >= str.length() / 2)
            {
                break;
            }
            push(s, str[i]);
        }
        else
        {
            cout << "字符串过长或不满足条件。" << endl;
            break;
        }
    }
    if ((s.top + 1) * 2 != str.length() - 1)
    {
        cout << str << "不是形如“序列1@序列2”的合法字符串" << endl;
        return 0;
    }
    i++;

    while (s.top >= -1 && i <= str.length() - 1)
    {
        pop(s, output);
        if (str[i] != output)
        {
            cout << str << "不是形如“序列1@序列2”的合法字符串" << endl;
            return 0;
        }
        i++;
    }
    cout << str << "是形如“序列1@序列2”的合法字符串" << endl;
}

int main()
{
    stack s;
    string str;
    int i;
    char output;

    initstack(s);
    cout << "输入一个字符串:";
    cin >> str;
    cout << endl;
    judge(s, i, output, str);

    return 0;
}