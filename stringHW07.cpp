//�����ַ���s����˳�򴮴洢�����һ������BF���㷨���ڴ�s�в����Ӵ�t���һ�γ��ֵ�λ�á����磬��s=��abcabcd����t=��abc��ʱ���Ϊ4��
#include<iostream>
#define MAXLEN 40
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

int strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}



int findpos(sstring s, sstring t)
{
	int i = 0, j = 0, start = 0;
	int pos = -1;
	
	while (start <= s.len - t.len)
	{
		while (j < t.len)
		{
			if (s.str[i] == t.str[j])
			{
				i++;
				j++;
				if (j == t.len)
				{
					pos = start + 1;
				}
			}
			else
			{
				break;
			}
		}
		start++;
		i = start;
		j = 0;
	}
	
	return pos;
}

int main()
{
	sstring s;
	cout << "����һ���ַ�����";
	cin >> s.str;
	s.len = strlength(s.str);
	sstring t;
	cout << "����һ����Ҫ���ҵ��Ӵ���";
	cin >> t.str;
	t.len = strlength(t.str);
	int pos = findpos(s, t);
	if (pos == -1)
	{
		cout << "û���ҵ����Ӵ���" << endl;
		return 0;
	}
	cout << "�Ӵ���" << t.str << "�������ֵ�λ��Ϊ" << pos;

	return 0;
}