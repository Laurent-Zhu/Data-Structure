//如果串中一个长度大于1的子串的全部字符相同，则称为等值子串。设计一个算法，求顺序串s中一个长度最大的等值子串t，如果串s中不存在等值子串，则t为空串。
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
	cout << "输入一个字符串：";
	cin >> s.str;
	strlength(s);
	find(s, t);
	if (t.len == 1)
	{
		cout << "输入的字符串中不存在等值子串。" << endl;
	}
	else
	{
		cout << "输入的字符串中长度最长的等值子串为：" << t.str;
	}

	return 0;
}