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
		while (p->next != NULL)//找到尾结点的位置
		{
			p = p->next;
		}
		nodeptr temp = (nodeptr)malloc(sizeof(node));//新开辟结点
		p->next = temp;//尾插法
		temp->data = data;
		temp->prior = p;
		temp->next = NULL;
	}
}
void result(nodeptr head, int n)//n为用户要求的小数点后位数
{
	nodeptr p = head->next->next;
	printf("3.");//先打印出3.，接下来只要打印小数位即可
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
	rn->prior = NULL;//初始化
	rn->next = NULL;//初始化
	sum->prior = NULL;//初始化
	sum->next = NULL;//初始化
	int i;
	for (i = 0; i < 600; i++)//设置600位
	{
		insert(rn, 0);
		insert(sum, 0);
	}
	nodeptr p1, p2;
	p1 = rn->next;//指向rn的首结点
	p2 = sum->next;//指向sum的首结点
	p1->data = 2;//初始值设置为2
	p2->data = 2;//初始值设置为2
	while (p1->next)
	{
		p1 = p1->next;
	}
	nodeptr rn_rear = p1;//设置尾指针
	while (p2->next)
	{
		p2 = p2->next;
	}
	nodeptr sum_rear = p2;//设置尾指针
	
	//核心代码开始
	int temp = 0;
	int ret = 0;
	int t;
	for (i = 1, t = 3; i < 10000; i++, t = t + 2)
	{
		//模拟乘法手算，从后往前算
		nodeptr p3 = rn_rear;
		ret = 0;
		while (p3)
		{
			temp = p3->data * i + ret;
			p3->data = temp % 10;
			ret = temp / 10;
			p3 = p3->prior;
		}
		//模拟除法手算，从前往后算
		p3 = rn->next;
		ret = 0;
		while (p3)
		{
			temp = p3->data + ret * 10;
			ret = temp % t;
			p3->data = temp / t;
			p3 = p3->next;
		}
		//模拟加法手算，从后往前算
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