//���һ���㷨���ж�˳��s�Ƿ�Ϊ���ģ�����ָһ���ַ�����ǰ���ºʹӺ���ǰ���Ľ����ͬ����
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
	cout << "����һ���ַ�����ֻ����ĸ����";
	cin >> s.str;
	strlength(s);
	if (isPalindrome(s))
	{
		cout << "���ַ����ǻ��ġ�" << endl;
	}
	else
	{
		cout << "���ַ������ǻ��ġ�" << endl;
	}
	return 0;
}