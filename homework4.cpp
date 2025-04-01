//�ʣ����������ϲ�������������A,B�洢�����һ���㷨���������ϵĲC��C��Ȼ�õ�����洢���������㷨��ʱ��Ϳռ临�Ӷȣ�����A=(1,3,2),B=(5,1,4,2),�C=(3)��
//��ʱ�临�Ӷ�ΪO(n*m)���ռ临�Ӷ�ΪO(1)���������¡�
#include<iostream>
using namespace std;

struct LinkedList
{
	int data;
	LinkedList* next;
	LinkedList(int x) :data(x), next(nullptr) {}
};
void CreateList(LinkedList*& Ahead, LinkedList*& Bhead)
{
	Ahead = new LinkedList(0);
	Ahead->next = new LinkedList(1);
	Ahead->next->next = new LinkedList(3);
	Ahead->next->next->next = new LinkedList(2);
	Ahead->next->next->next->next = nullptr;
	Bhead = new LinkedList(0);
	Bhead->next = new LinkedList(5);
	Bhead->next->next = new LinkedList(1);
	Bhead->next->next->next = new LinkedList(4);
	Bhead->next->next->next->next = new LinkedList(2);
	Bhead->next->next->next->next->next = nullptr;
}
void DiffSet(LinkedList*& Ahead, LinkedList*& Bhead)
{
	LinkedList* A = Ahead->next;
	LinkedList* Aprev = Ahead;
	while (A != nullptr)
	{
		LinkedList* B = Bhead->next;
		bool found = false;
		while (B != nullptr)
		{
			if (A->data == B->data)
			{
				found = true;
				break;
			}
			B = B->next;
		}
		if (found)
		{
			Aprev->next = A->next;
			delete A;
			A = Aprev->next;
		}
		else
		{
			Aprev = A;
			A = A->next;
		}
	}
}
void PrintList(LinkedList*& head)
{
	LinkedList* L=head->next;
	while (L != nullptr)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
int main()
{
	LinkedList* Ahead,* Bhead;
	CreateList(Ahead, Bhead);
	cout << "A����";
	PrintList(Ahead);
	cout << "B����";
	PrintList(Bhead);
	DiffSet(Ahead, Bhead);
	cout << "�C=A-B��";
	PrintList(Ahead);

}