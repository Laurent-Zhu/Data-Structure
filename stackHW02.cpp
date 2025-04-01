//������һ����ջst�����һ���㷨����ջ��ջ����ʼ�ĵ�k����㡣
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
	
	/*cout << "����ջԪ�أ���Ctrl+z�ӻس���������";
	while (cin >> x)
	{
		push(top1, x);
	} */
	for (x = 1; x <= 6; x++)
	{
		push(top1, x);
	}
	cout << "ԭջ:";
	printstack(top1);
	cout << endl;
	int k;
	cout << "����ɾ������λ��:";
	cin >> k;
	if (k >= x || k < 1)
	{
		cout << "����λ�ò��Ϸ���" << endl;
		return 0;
	}
	popkth(top1, top2, k, e);
	cout << "ɾ���Ľ�������:" << e << endl;
	cout << "ɾ����" << k << "������:";
	printstack(top1);
	cout << endl;

	return 0;
}