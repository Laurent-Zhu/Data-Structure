//假设一个字符串s采用string对象表示，设计一个递归算法在s中查找字符c的最后一个位置，找到后返回其位置，没有找到返回 - 1。
#include<string>
#include<iostream>
using namespace std;

int search(string s, int i, char c)
{
	if (i == -1)
		return -1;
	else
	{
		if (s[i] == c)
		{
			return i + 1;
		}
		return search(s, --i, c);
	}
}

int main()
{
	string s;
	char c;
	cout << "输入一个字符串：";
	cin >> s;
	cout << "输入想要查找的字符：";
	cin >> c;
	int pos = search(s, s.size() - 1, c);
	if (pos != -1)
		cout << "字符" << c << "的最后一个位置为" << pos << endl;
	else
		cout << "未找到该字符。" << endl;
	return 0;
}