#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* prior;
	struct node* next;
}node,*nodeptr;
void insert(nodeptr head,int data)
{
	nodeptr p = head;
	if (p == NULL)
		return;
	else
	{
		while (p->next != NULL)//�ҵ�β����λ��
		{
			p = p->next;
		}
		nodeptr temp = (nodeptr)malloc(sizeof(node));//�¿��ٽ��
		p->next = temp;//β�巨
		temp->data = data;
		temp->prior = p;
		temp->next = NULL;
	}
}
void result(nodeptr head, int n)//nΪ�û�Ҫ���С�����λ��
{
	nodeptr p = head->next->next;
	printf("3.");//�ȴ�ӡ��3.��������ֻҪ��ӡС��λ����
	for (int i = 1; i <= n; i++)
	{
		printf("%d", p->data);
		if (p->next) {
			p = p->next;
		}
	}
	printf("\n");
}
int main()
{
	nodeptr rn, sum;
	rn = (nodeptr)malloc(sizeof(node));
	sum = (nodeptr)malloc(sizeof(node));
	rn->prior = NULL;//��ʼ��
	rn->next = NULL;//��ʼ��
	sum->prior = NULL;//��ʼ��
	sum->next = NULL;//��ʼ��
	int i;
	for (i = 0; i < 600; i++)//����600λ
	{
		insert(rn, 0);
		insert(sum, 0);
	}
	nodeptr p1, p2;
	p1 = rn->next;//ָ��rn���׽��
	p2 = sum->next;//ָ��sum���׽��
	p1->data = 2;//��ʼֵ����Ϊ2
	p2->data = 2;//��ʼֵ����Ϊ2
	while (p1->next)
	{
		p1 = p1->next;
	}
	nodeptr rn_rear = p1;//����βָ��
	while (p2->next)
	{
		p2 = p2->next;
	}
	nodeptr sum_rear = p2;//����βָ��
	
	//���Ĵ��뿪ʼ
	int temp = 0;
	int ret = 0;
	int t;
	for (i = 1, t = 3; i < 10000; i++, t = t + 2)
	{
		//ģ��˷����㣬�Ӻ���ǰ��
		nodeptr p3 = rn_rear;
		ret = 0;
		while (p3)
		{
			temp = p3->data * i + ret;
			p3->data = temp % 10;
			ret = temp / 10;
			p3 = p3->prior;
		}
		//ģ��������㣬��ǰ������
		p3 = rn->next;
		ret = 0;
		while (p3)
		{
			temp = p3->data + ret * 10;
			ret = temp % t;
			p3->data = temp / t;
			p3 = p3->next;
		}
		//ģ��ӷ����㣬�Ӻ���ǰ��
		p3 = rn_rear;
		nodeptr p4 = sum_rear;
		ret = 0;
		while (p3 && p4)
		{
			temp = p3->data + p4->data + ret;
			ret = temp / 10;
			p4->data = temp % 10;
			p3 = p3->prior;
			p4 = p4->prior;
		}
	}
	int n;
	scanf_s("%d", &n);
	result(sum, n);
	free(rn);
	free(sum);

	return 0;
}