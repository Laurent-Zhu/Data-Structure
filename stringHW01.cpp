//设计一个算法，计算一个仅包含字母字符的顺序串s中最大字母出现的次数。
#include<iostream>
#define MAXLEN 40
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

int strlength(sstring str)
{
	int i;
	for (i = 0; str.str[i] != '\0'; i++)
	{}
	return i;
}

void calculate(sstring str, char& max, int& n)
{
	max = str.str[0];
	n = 1;
	for (int i = 0; i < str.len; i++)
	{
		if (max < str.str[i])
		{
			max = str.str[i];
			n = 1;
		}
		else if (str.str[i] == max)
		{
			n++;
		}
		else continue;
	}
}

int main()
{
	sstring str;
	str.len = 0;
	cout << "输入一个字符串（只含字母）：";
	cin >> str.str;
	str.len = strlength(str);
	int n;
	char max;
	calculate(str, max, n);
	cout << "最大的字母是" << max << "，出现的次数为" << n << "次" << endl;

	return 0;
}