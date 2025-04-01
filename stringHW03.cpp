//设有一个顺序串s，其字符仅由数字和小写字母组成。设计一个算法，将s中的所有数字字符放在前半部分，将所有小写字母字符放在后半部分，并给出算法的时间和空间复杂度。
#include<iostream>
#define MAXLEN 40
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

bool process(sstring& s)//时间复杂度为O(n)，空间复杂度为O(1)
{
	int i, j;
	char temp;
	for (i = 0, j = s.len - 1; i < j;)//两个指针分别从字符串头和尾往后往前读
	{
		if (s.str[i] >= 97 && s.str[i] <= 122 && s.str[j] >= 48 && s.str[j] <= 57)//前为字母，后为数字，调换，前后指针往后往前移一位
		{
			temp = s.str[i];
			s.str[i] = s.str[j];
			s.str[j] = temp;
			i++;
			j--;
		}
		else if (s.str[i] >= 48 && s.str[i] <= 57 && s.str[j] >= 97 && s.str[j] <= 122)//前为数字，后为字母，不调换，前后指针往后往前移一位
		{
			i++;
			j--;
		}
		else if (s.str[i] >= 48 && s.str[i] <= 57 && s.str[j] >= 48 && s.str[j] <= 57)//前后均为数字，不调换，前指针往后移一位
		{
			i++;
		}
		else if (s.str[i] >= 97 && s.str[i] <= 122 && s.str[j] >= 97 && s.str[j] <= 122)//前后均为字母，不调换，后指针往前移一位
		{
			j--;
		}
		else//其他情况表示输入有误
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
	cout << "输入一个字符串（只含小写字母和数字）：";
	cin >> s.str;
	strlength(s);
	bool x = process(s);
	if (x == 0)
	{
		cout << "字符串未按要求输入！" << endl;
		return 0;
	}
	cout << "将所有的数字放到小写字母前面后的字符串为：" << s.str << endl;

	return 0;
}