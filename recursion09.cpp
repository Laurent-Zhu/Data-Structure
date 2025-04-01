//设有一个不带表头结点的整数单链表p，设计一个递归算法delxall(p,x)，删除单链表p中所有值为x的结点。
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
	cout << "删除值为" << x << "的结点后：";
	printlist(head);

	return 0;
}