//����һ��������ͷ��������������p�����һ���ݹ��㷨getNo(p, x)�����ҵ�һ��ֵΪx�Ľ�����ţ������׽������Ϊ0����û���ҵ��Ƿ��� - 1��
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

int main()
{
	node* head;
	getlist(head);
	int x;
	cout << "������Ҫ���ҵ�ֵ��";
	cin >> x;
	int pos = getNo(head, x);
	if (pos == -1)
	{
		cout << "δ���ҵ�����ֵ���ڵĽ�㡣" << endl;
		return 0;
	}
	cout << "��һ��ֵΪ" << x << "�Ľ�����Ϊ" << pos << endl;
	return 0;
}