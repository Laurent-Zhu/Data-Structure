//����һ��������ͷ���ķǿ�����������p�����н��ֵ����ͬ����������ݹ��㷨��maxNode(p)���ص�����p�������ֵ��minNode(p)���ص�����p����С���ֵ��
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
	cout << "��Ҫ���������������";
	cin >> n;
	cout << "������" << n << "��������������ͬ����";
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
	cout << "�����ֵ��" << max << endl;
	cout << "��С���ֵ��" << min << endl;

	return 0;
}