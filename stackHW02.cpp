//假设有一个链栈st，设计一个算法，出栈从栈顶开始的第k个结点。
#include<iostream>
using namespace std;

struct stacknode {
	int data;
	stacknode* next;
	stacknode(int x):data(x),next(nullptr){}
};

void initlinkstack(stacknode*& headnode)
{
	headnode = new stacknode(0);
}

void push(stacknode*& top ,int x)
{
	stacknode* temp = new stacknode(x);
	temp->next = top->next;
	top->next = temp;
}

int pop(stacknode*& top)
{
	stacknode* temp = top->next;
	top->next = temp->next;
	int e = temp->data;
	delete temp;
	return e;
}

void popkth(stacknode*& top1, stacknode*& top2, int k, int& x)
{
	int i = 1;
	int e;
	while (i < k)
	{
		e = pop(top1);
		push(top2, e);
		i++;
	}
	x = pop(top1);
	i = 1;
	while (i < k)
	{
		e = pop(top2);
		push(top1, e);
		i++;
	}
}

void printstack(stacknode*& top)
{
	stacknode* p = top->next;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	stacknode* st;
	initlinkstack(st);
	stacknode* top1 = st;

	stacknode* st2;
	initlinkstack(st2);
	stacknode* top2 = st2;

	int x;
	int e;
	
	/*cout << "输入栈元素（按Ctrl+z加回车结束）：";
	while (cin >> x)
	{
		push(top1, x);
	} */
	for (x = 1; x <= 6; x++)
	{
		push(top1, x);
	}
	cout << "原栈:";
	printstack(top1);
	cout << endl;
	int k;
	cout << "输入删除结点的位置:";
	cin >> k;
	if (k >= x || k < 1)
	{
		cout << "输入位置不合法。" << endl;
		return 0;
	}
	popkth(top1, top2, k, e);
	cout << "删除的结点的数据:" << e << endl;
	cout << "删除第" << k << "个结点后:";
	printstack(top1);
	cout << endl;

	return 0;
}