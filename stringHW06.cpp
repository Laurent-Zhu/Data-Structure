//假设字符串s采用链串存储，设计一个算法，判断是否为“x@x”形式的串，其中x是不含“@”的任意串。例如，当s = “ab@ab”时返回true，当s = “abcd”时返回false。
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
	cout << "输入一个字符串：";
	cin >> str;
	assignStr(head, str);
	bool x = judge(head);
	if (x)
	{
		cout << "该字符串是“x@x”形式的串，其中x是不含“@”的任意串。" << endl;
	}
	else
	{
		cout << "该字符串不是“x@x”形式的串，其中x是不含“@”的任意串。" << endl;
	}
	delete s;
	return 0;
}