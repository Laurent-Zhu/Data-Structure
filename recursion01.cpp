//����һ���ַ���s����string�����ʾ�����һ���ݹ��㷨���������ַ���
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
	cout << "����һ���ַ�����";
	cin >> s;
	reverse(s, 0);
	cout << "���ú�" << s << endl;
	return 0;
}