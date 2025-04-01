//�����ַ���s���������洢�����һ���㷨���ж��Ƿ�Ϊ��x@x����ʽ�Ĵ�������x�ǲ�����@�������⴮�����磬��s = ��ab@ab��ʱ����true����s = ��abcd��ʱ����false��
#include<iostream>
#define MAXLEN 100
using namespace std;
struct lstring {
	char ch;
	lstring* next;
	lstring(char e) :ch(e), next(nullptr) {}
};

void initstring(lstring*& s)
{
	s = new lstring('h');
}

void assignStr(lstring*& head, char* str)
{
	int i;
	lstring* p = head;
	for (i = 0; str[i] != '\0'; i++)
	{
		lstring* temp = new lstring(str[i]);
		p->next = temp;
		p = p->next;
	}
}

bool judge(lstring* head)
{
	lstring* p1 = head->next;
	lstring* p0 = p1;
	while (p1->ch != '@')
	{
		p1 = p1->next;
		if (p1 == nullptr)
		{
			return false;
		}
	}
	p1 = p1->next;
	while (p0->ch != '@' && p1 != nullptr)
	{
		if (p0->ch == p1->ch)
		{
			p0 = p0->next;
			p1 = p1->next;
			continue;
		}
		else
		{
			return false;
		}
	}
	if (p0->ch != '@' || p1 != nullptr)
	{
		return false;
	}
	return true;
}

int main()
{
	char str[MAXLEN];
	lstring* s;
	initstring(s);
	lstring* head = s;
	cout << "����һ���ַ�����";
	cin >> str;
	assignStr(head, str);
	bool x = judge(head);
	if (x)
	{
		cout << "���ַ����ǡ�x@x����ʽ�Ĵ�������x�ǲ�����@�������⴮��" << endl;
	}
	else
	{
		cout << "���ַ������ǡ�x@x����ʽ�Ĵ�������x�ǲ�����@�������⴮��" << endl;
	}
	delete s;
	return 0;
}