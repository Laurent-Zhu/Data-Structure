//����һ���ַ�������������ʾ�����һ���ݹ��㷨��t��s�����ó��ֵĴ��������磬s = ��aababad��, t = ��aba������t��s�����ó��ֵĴ���Ϊ2��
#include<iostream>
#include<string>
using namespace std;
struct strnode {
	char c;
	strnode* next;
	strnode(){}
	strnode(char ch):c(ch), next(NULL){}
};

void times(strnode* p, string t, int& count)
{
	if (p == NULL)
		return;
	else
	{
		strnode* temp = p;
		for (int i = 0; i < t.size(); i++)
		{
			if (temp == NULL)
				return;
			if (temp->c != t[i])
			{
				times(p->next, t, count);
				return;
			}
			temp = temp->next;
		}
		count++;
		times(p->next, t, count);
		return;
	}
}


int main()
{
	string str;
	cout << "����һ���ַ�����";
	cin >> str;
	strnode* head = new strnode(str[0]);
	strnode* p0 = head;
	for (int i = 1; i < str.size(); i++)
	{
		strnode* p = new strnode(str[i]);
		p0->next = p;
		p0 = p0->next;
	}
	string t;
	cout << "������һ���ַ�����";
	cin >> t;
	int count = 0;
	times(head, t, count);
	cout << t << "��" << str << "�����ó��ֵĴ���Ϊ" << count << endl;

	return 0;
}
