//设有一个不带表头结点的非空整数单链表p，所有结点值不相同，设计两个递归算法，maxNode(p)返回单链表p的最大结点值，minNode(p)返回单链表p的最小结点值。
#include<iostream>
using namespace std;
struct node
{
	int e;
	node* next;
	node(int i):e(i),next(NULL){}
};

int maxNode(node* p)
{
	if (p->next == NULL)
		return p->e;
	int max = maxNode(p->next);
	if (p->e >= max)
		return p->e;
	else
		return max;
}

int minNode(node* p)
{
	if (p->next == NULL)
		return p->e;
	int min = minNode(p->next);
	if (p->e <= min)
		return p->e;
	else
		return min;
}

void getlist(node*& head)
{
	int n;
	int e;
	cout << "你要输入的整数个数：";
	cin >> n;
	cout << "请输入" << n << "个整数（互不相同）：";
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

int main()
{
	node* head;
	getlist(head);
	int max = maxNode(head);
	int min = minNode(head);
	cout << "最大结点值：" << max << endl;
	cout << "最小结点值：" << min << endl;

	return 0;
}