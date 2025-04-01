//假设一个字符串s采用string对象表示，设计一个递归算法逆置所有字符。
#include<string>
#include<iostream>
using namespace std;

void reverse(string& s, int i)
{
	if (i == s.size() / 2)
		return;
	else
	{
		char c = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = c;
		reverse(s, ++i);
	}
}

int main()
{
	string s;
	cout << "输入一个字符串：";
	cin >> s;
	reverse(s, 0);
	cout << "逆置后：" << s << endl;
	return 0;
}