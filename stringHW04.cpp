//�������һ�����ȴ���1���Ӵ���ȫ���ַ���ͬ�����Ϊ��ֵ�Ӵ������һ���㷨����˳��s��һ���������ĵ�ֵ�Ӵ�t�������s�в����ڵ�ֵ�Ӵ�����tΪ�մ���
#include<iostream>
#define MAXLEN 100
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

void strlength(sstring& s)
{
	int i;
	for (i = 0; s.str[i] != '\0'; i++)
	{
	}
	s.len = i;
}

void find(sstring& s, sstring& t)
{
	int i, j;
	int maxlen = 1;
	int length = 1;
	char ch = 'c';
	for (i = 0; i < s.len; i++)
	{
		j = i + 1;
		while (s.str[j] == s.str[i])
		{
			length++;
			j++;
		}
		if (length > maxlen)
		{
			maxlen = length;
			ch = s.str[i];
		}
		length = 1;
	}
	t.len = maxlen;
	for (i = 0; i < t.len; i++)
	{
		t.str[i] = ch;
	}
	t.str[i] = '\0';
}

int main()
{
	sstring s, t;
	s.len = 0;
	cout << "����һ���ַ�����";
	cin >> s.str;
	strlength(s);
	find(s, t);
	if (t.len == 1)
	{
		cout << "������ַ����в����ڵ�ֵ�Ӵ���" << endl;
	}
	else
	{
		cout << "������ַ����г�����ĵ�ֵ�Ӵ�Ϊ��" << t.str;
	}

	return 0;
}