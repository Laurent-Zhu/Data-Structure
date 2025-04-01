//问：有一个整数单链表L，设计一个算法删除其中所有值为x节点，并给出算法的时间和空间复杂度。例如L=(1,2,2,3,1)，x=2,删除后L=(1,3,1)。
//答：时间复杂度为O(n),空间复杂度为O(1),代码如下。
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
			prev->next = curr->next; // 删除当前节点  
			delete curr; // 释放内存  
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
	cout << "初始链表：";
	PrintList(head);
	Delete(head,del);
	cout << "删除元素"<<del<<"后的链表：";
	PrintList(head);
	delete head;
	
	return 0;
}