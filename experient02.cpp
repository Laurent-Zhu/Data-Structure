#include<iostream>
using namespace std;
struct LinkNode {
	int n;
	LinkNode* prior;
	LinkNode* next;
};

bool CreateList(LinkNode*& head, int n) 
{
	LinkNode *p , *pre;
	pre = head;
	p = new LinkNode;
	pre->next = p;
	p->n = 1;
	pre = p;
	for (int i = 2; i <= n; i++)
	{
		p = new LinkNode;
		if (p == nullptr)
			return false;
		p->n = n;
		pre->next = p;
		p->next = nullptr;
	}
	return true;
}
float sum(LinkNode* head, int n)
{


}


int main()
{
	LinkNode* headnode = new LinkNode;
	if (headnode == nullptr)
		return;
	LinkNode* head = headnode;
	head->next = nullptr;
	int n;
	cin >> n;
	CreateList(head, n);
	cout << sum(head, n);


}