//����һ��������ͷ��������������p�����һ���ݹ��㷨delxall(p,x)��ɾ��������p������ֵΪx�Ľ�㡣
#include<iostream>
using namespace std;
struct node
{
	int e;
	node* next;
	node(int i) :e(i), next(NULL) {}
};
node* head;

void delxall(node* p, int x)
{
	if (head->e == x)
	{
		node* temp = head;
		head = head->next;
		delete temp;
		p = head;
	}
	if (p->next == NULL)
		return;
	if (p->next->e == x)
	{
		node* temp = p->next;
		p->next = temp->next;
		delete temp;
		delxall(p, x);
	}
	else
		delxall(p->next, x);
}

void getlist(node*& head)
{
	int n;
	int e;
	cout << "��Ҫ���������������";
	cin >> n;
	cout << "������" << n << "��������";
	cin >> e;
	head = new node(e);
	node* p = head;
	for (int i = 1; i < n; i++)
	{
		cin >> e;
		node* temp = new node(e);
		p->next = temp;
		p = p->next;
	}
}

void printlist(node* p)
{
	while (p != NULL)
	{
		cout << p->e << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	getlist(head);
	node* p = head;
	cout << "��Ҫɾ���Ľ��ֵ��";
	int x;
	cin >> x;
	delxall(p, x);
	cout << "ɾ��ֵΪ" << x << "�Ľ���";
	printlist(head);

	return 0;
}