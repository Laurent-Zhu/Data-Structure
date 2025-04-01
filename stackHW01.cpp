//����һ���ַ���str�����һ���㷨������˳��ջ�ж�strs�Ƿ�Ϊ���硰����1@����2���ĺϷ��ַ�������������2������1��������str��ǡ��ֻ��һ��@�ַ���
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
            cout << "�ַ�������������������" << endl;
            break;
        }
    }
    if ((s.top + 1) * 2 != str.length() - 1)
    {
        cout << str << "�������硰����1@����2���ĺϷ��ַ���" << endl;
        return 0;
    }
    i++;

    while (s.top >= -1 && i <= str.length() - 1)
    {
        pop(s, output);
        if (str[i] != output)
        {
            cout << str << "�������硰����1@����2���ĺϷ��ַ���" << endl;
            return 0;
        }
        i++;
    }
    cout << str << "�����硰����1@����2���ĺϷ��ַ���" << endl;
}

int main()
{
    stack s;
    string str;
    int i;
    char output;

    initstack(s);
    cout << "����һ���ַ���:";
    cin >> str;
    cout << endl;
    judge(s, i, output, str);

    return 0;
}