//�ʣ���һ���������������˫����L�����������������ڵ㡣���һ���㷨�͵�ɾ��L������ֵ�ظ��Ľڵ㣬�����ֵ��ͬ�Ľڵ�ֻ����һ��������L=(1,2,2,2,3,5,5),ɾ����L=(1,2,3.5)��
//�𣺴������¡�
#include<iostream>
using namespace std;

struct DoubleLinkedList
{
	int data;
	DoubleLinkedList* next, * prior;
	DoubleLinkedList(int x) :data(x), next(nullptr),prior(nullptr) {}
};
void CreateList(DoubleLinkedList*& Dhead)
{
	Dhead->next = new DoubleLinkedList(1);
	Dhead->next->next = new DoubleLinkedList(2);
	Dhead->next->next->next = new DoubleLinkedList(2);
	Dhead->next->next->next->next = new DoubleLinkedList(2);
	Dhead->next->next->next->next->next = new DoubleLinkedList(3);
	Dhead->next->next->next->next->next->next = new DoubleLinkedList(5);
	Dhead->next->next->next->next->next->next->next = new DoubleLinkedList(5);
	Dhead->next->next->next->next->next->next->next->prior = Dhead->next->next->next->next->next->next;
	Dhead->next->next->next->next->next->next->prior = Dhead->next->next->next->next->next;
	Dhead->next->next->next->next->next->prior = Dhead->next->next->next->next;
	Dhead->next->next->next->next->prior = Dhead->next->next->next;
	Dhead->next->next->next->prior = Dhead->next->next;
	Dhead->next->next->prior = Dhead->next;
	Dhead->next->prior = Dhead;
}
void Delete(DoubleLinkedList*& Dhead)
{
	DoubleLinkedList* L = Dhead->next;
	while (L != nullptr&&L->next != nullptr)
	{
		if (L->data == L->next->data)
		{
			DoubleLinkedList* tmp = L->next;
			L->next = tmp->next;
			if(tmp->next!=nullptr)
				L->next->prior = L;
			delete tmp;
		}
		else
		{
			L = L->next;
		}
	}
}
void Print(DoubleLinkedList*& Dhead)
{
	DoubleLinkedList* L=Dhead->next;
	while (L != nullptr)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
int main()
{
	DoubleLinkedList* Dhead = new DoubleLinkedList(0);
	CreateList(Dhead);
	cout << "ԭ����";
	Print(Dhead);
	Delete(Dhead);
	cout << "ɾ���ظ�Ԫ�غ������";
	Print(Dhead);

}