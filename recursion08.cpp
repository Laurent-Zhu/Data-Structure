//设有一个不带表头结点的整数单链表p，设计一个递归算法delx(p, x)，删除单链表p中第一个值为x的结点。
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
	cout << "你要输入的整数个数：";
	cin >> n;
	cout << "请输入" << n << "个整数：";
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
	cout << "你要删除的结点值：";
	int x;
	cin >> x;
	delxall(p, x);
	cout << "删除第一个值为" << x << "的结点后：";
	printlist(head);

	return 0;
}