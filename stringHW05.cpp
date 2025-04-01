//设计一个算法，删除一个链串s中所有非重叠的“abc”子串。例如，s = “aabcabcd”，删除后s = “ad”。
#include<iostream>
#define MAXLEN 100
using namespace std;
struct lstring {
	char ch;
	lstring* next;
	lstring(char e):ch(e),next(nullptr){}
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

void deleteStr(lstring*& head)
{
	lstring* p = head->next->next;
	lstring* pre = head->next;
	while (p != nullptr)
	{
		while (p->ch == 'a' && p->next->ch == 'b' && p->next->next->ch == 'c')
		{
			lstring* temp1 = p;
			lstring* temp2 = p->next;
			p = p->next->next->next;
			pre->next = p;
			delete temp1;
			temp1 = temp2;
			temp2 = temp2->next;
			delete temp1;
			delete temp2;
		}
		pre = p;
		p = p->next;
	}
}

void printStr(lstring* head)
{
	lstring* p = head->next;
	while (p != nullptr)
	{
		cout << p->ch;
		p = p->next;
	}
	cout << endl;
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
	deleteStr(head);
	cout << "删除所有非重叠的“abc”子串后：";
	printStr(head);

	delete s;
}