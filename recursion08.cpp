//����һ��������ͷ��������������p�����һ���ݹ��㷨delx(p, x)��ɾ��������p�е�һ��ֵΪx�Ľ�㡣
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
	if (p->e == x)
	{
		node* temp = p;
		p = p->next;
		delete temp;
		head = p;
		return;
	}
	if (p->next == NULL)
		return;
	if (p->next->e == x)
	{
		node* temp = p->next;
		p->next = temp->next;
		delete temp;
		return;
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
	cout << "ɾ����һ��ֵΪ" << x << "�Ľ���";
	printlist(head);

	return 0;
}