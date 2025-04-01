//设计一个算法，判断顺序串s是否为回文（回文指一个字符串从前向后堵和从后向前读的结果相同）。
#include<iostream>
#define MAXLEN 40
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

void strlength(sstring& str)
{
	int i;
	for (i = 0; str.str[i] != '\0'; i++)
	{
	}
	str.len = i;
}

bool isPalindrome(sstring str)
{
	int i;
	for (i = 0; i < str.len / 2; i++)
	{
		if (str.str[i] == str.str[str.len - 1 - i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	sstring s;
	s.len = 0;
	cout << "输入一个字符串（只含字母）：";
	cin >> s.str;
	strlength(s);
	if (isPalindrome(s))
	{
		cout << "该字符串是回文。" << endl;
	}
	else
	{
		cout << "该字符串不是回文。" << endl;
	}
	return 0;
}