//设有一个不带表头结点的整数单链表p，设计一个递归算法getNo(p, x)，查找第一个值为x的结点的序号（假设首结点的序号为0），没有找到是返回 - 1。
#include<iostream>
using namespace std;

struct node
{
	int e;
	node* next;
	node(int i):e(i),next(NULL){}
};
int i = -1;
int getNo(node* p, int x)
{
	i++;
	if (p == NULL)
		return -1;
	if (p->e == x)
		return i;
	else
		return getNo(p->next, x);
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

int main()
{
	node* head;
	getlist(head);
	int x;
	cout << "输入你要查找的值：";
	cin >> x;
	int pos = getNo(head, x);
	if (pos == -1)
	{
		cout << "未能找到该数值所在的结点。" << endl;
		return 0;
	}
	cout << "第一个值为" << x << "的结点序号为" << pos << endl;
	return 0;
}