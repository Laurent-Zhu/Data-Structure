//����һ���ַ���s����string�����ʾ�����һ���ݹ��㷨��s�в����ַ�c�����һ��λ�ã��ҵ��󷵻���λ�ã�û���ҵ����� - 1��
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
	cout << "����һ���ַ�����";
	cin >> s;
	cout << "������Ҫ���ҵ��ַ���";
	cin >> c;
	int pos = search(s, s.size() - 1, c);
	if (pos != -1)
		cout << "�ַ�" << c << "�����һ��λ��Ϊ" << pos << endl;
	else
		cout << "δ�ҵ����ַ���" << endl;
	return 0;
}