//���һ���㷨������һ����������ĸ�ַ���˳��s�������ĸ���ֵĴ�����
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
	cout << "����һ���ַ�����ֻ����ĸ����";
	cin >> str.str;
	str.len = strlength(str);
	int n;
	char max;
	calculate(str, max, n);
	cout << "������ĸ��" << max << "�����ֵĴ���Ϊ" << n << "��" << endl;

	return 0;
}