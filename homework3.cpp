//�ʣ���һ������������L�����һ���㷨ɾ����������ֵΪx�ڵ㣬�������㷨��ʱ��Ϳռ临�Ӷȡ�����L=(1,2,2,3,1)��x=2,ɾ����L=(1,3,1)��
//��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),�������¡�
#include<iostream>
using namespace std;

struct LinkedList
{
	int data;
	LinkedList* next;
	LinkedList(int x):data(x),next(nullptr){}
};

void CreateList(LinkedList*& head)
{
	head = new LinkedList(1);
	head->next = new LinkedList(2);
	head->next->next = new LinkedList(2);
	head->next->next->next = new LinkedList(3);
	head->next->next->next->next = new LinkedList(1);
	head->next->next->next->next->next = nullptr;
}
void Delete(LinkedList*& head, int del)
{
	LinkedList* prev = head;
	LinkedList* tmp;
	LinkedList* curr = prev->next;
	if (prev->data == del)
	{
		tmp = prev;
		prev = prev->next;
		head = prev;
		delete tmp;
	}
	while (curr != nullptr)
	{
		if (curr->data == del)
		{
			/*tmp = curr;
			prev->next = tmp->next;
			curr = curr->next;
			delete tmp;*/
			prev->next = curr->next; // ɾ����ǰ�ڵ�  
			delete curr; // �ͷ��ڴ�  
			curr = prev->next;
		}
		else
		{
			prev = prev->next;
			curr = prev->next;
		}
	}
}

void PrintList(LinkedList* head)
{
	LinkedList* L = head;
	while (L != nullptr)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << endl;
}
int main()
{
	int del = 2;
	LinkedList* L;
	LinkedList* head;
	CreateList(head);
	cout << "��ʼ����";
	PrintList(head);
	Delete(head,del);
	cout << "ɾ��Ԫ��"<<del<<"�������";
	PrintList(head);
	delete head;
	
	return 0;
}