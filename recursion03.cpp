//假设一个字符串采用链串表示，设计一个递归算法求t在s中重置出现的次数。例如，s = “aababad”, t = “aba”，则t在s中重置出现的次数为2。
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
	cout << "输入一个字符串：";
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
	cout << "输入另一个字符串：";
	cin >> t;
	int count = 0;
	times(head, t, count);
	cout << t << "在" << str << "中重置出现的次数为" << count << endl;

	return 0;
}
