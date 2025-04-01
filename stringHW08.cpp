//�����ַ���s����˳�򴮴洢�����һ������KMP���㷨���ڴ�s�в����Ӵ�t���һ�γ��ֵ�λ�á����磬��s=��abcabcd����t=��abc��ʱ���Ϊ4��
#include<iostream>
#define MAXLEN 40
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

void strlength(sstring& str)
{
	int i = 0;
	while (str.str[i] != '\0')
	{
		i++;
	}
	str.len = i;
}

void getnext(sstring t, int* next)
{
	int j = -1, i = 0;
	next[0] = -1;
	while (i < t.len + 1)
	{
		if (t.str[j] == t.str[i] || j==-1)
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

bool kmp(sstring s, sstring t, int* next, int& i)
{
	int j = 0;
	while (i < s.len && j < t.len)
	{
		if (s.str[i] == t.str[j] || j == -1)
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == t.len)
	{
		return true;
	}
	else return false;
}

void getpos(sstring s, sstring t, int* next, int& pos)
{
	int i = 0;
	if (!kmp(s, t, next, i))//û���ҵ���Ӧ�Ӵ�
	{
		pos = -1;
		return;
	}
	i = 0;
	pos = 1;
	while (i < s.len - t.len)
	{
		bool n = kmp(s, t, next, i);
		if (!n)//û���ҵ���Ӧ�Ӵ�
		{
			break;
		}
		else
		{
			pos = i + 1 - t.len;
			i = pos;
		}
	}
	return;
}

int main()
{
	sstring s;
	cout << "����һ���ַ�����";
	cin >> s.str;
	strlength(s);
	sstring t;
	cout << "����һ����Ҫ���ҵ��Ӵ���";
	cin >> t.str;
	strlength(t);
	int* next = new int[t.len + 1];
	getnext(t, next);
	cout << "next���飺";
	for (int i = 1; i < t.len + 1; i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;
	int pos;
	getpos(s, t, next, pos);
	if (pos == -1)
	{
		cout << "û���ҵ���Ӧ�Ӵ���" << endl;
		return 0;
	}
	cout << "�Ӵ����һ�γ��ֵ�λ�ã�" << pos;

	return 0;
}