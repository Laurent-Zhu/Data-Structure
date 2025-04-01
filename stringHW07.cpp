//假设字符串s采用顺序串存储，设计一个基于BF的算法，在串s中查找子串t最后一次出现的位置。例如，当s=“abcabcd”，t=“abc”时结果为4。
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
	cout << "输入一个字符串：";
	cin >> s.str;
	s.len = strlength(s.str);
	sstring t;
	cout << "输入一个想要查找的子串：";
	cin >> t.str;
	t.len = strlength(t.str);
	int pos = findpos(s, t);
	if (pos == -1)
	{
		cout << "没有找到该子串。" << endl;
		return 0;
	}
	cout << "子串“" << t.str << "”最后出现的位置为" << pos;

	return 0;
}