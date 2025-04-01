#include<stdio.h>
#include<stdlib.h>
typedef struct crossnode
{
	int row, col;
	int value;
	struct crossnode* right,* down;
}crossnode, *nodeptr;

typedef struct
{
	nodeptr* rowhead,* colhead;
	int rowsum, colsum, len;
}crosslist;

void createlist(crosslist* list, int rowsum, int colsum)
{
	int i;
	nodeptr p, q;

	list->rowhead = (nodeptr*)malloc((rowsum + 1) * sizeof(nodeptr));
	list->colhead = (nodeptr*)malloc((colsum + 1) * sizeof(nodeptr));

	for (i = 1; i <= rowsum; i++)
	{
		list->rowhead[i] = NULL;
	}
	for (i = 1; i <= colsum; i++)
	{
		list->colhead[i] = NULL;
	}

	int r, c, v;
	for (i = 1; i <= list->len; i++)
	{
		scanf_s("%d %d %d", &r, &c, &v);
		p = (nodeptr)malloc(sizeof(crossnode));
		p->row = r;
		p->col = c;
		p->value = v;

		//行表插入
		if (list->rowhead[p->row] == NULL)
		{
			list->rowhead[p->row] = p;
			p->right = NULL;
		}
		else if (p->col < list->rowhead[p->row]->col)
		{
			p->right = list->rowhead[p->row];
			list->rowhead[p->row] = p;
		}
		else
		{
			for (q = list->rowhead[p->row]; q->right && q->right->col < p->col; q = q->right);
			p->right = q->right;
			q->right = p;
		}

		//列表插入
		if (list->colhead[p->col] == NULL)
		{
			list->colhead[p->col] = p;
			p->down = NULL;
		}
		else if (p->row < list->colhead[p->col]->row)
		{
			p->down = list->colhead[p->col];
			list->colhead[p->col] = p;
		}
		else
		{
			for (q = list->colhead[p->col]; q->down && q->down->row < p->row; q = q->down);
			p->down = q->down;
			q->down = p;
		}
	}
}

void addition(crosslist* A, crosslist* B)
{
	nodeptr pa, pb, papre;
	int i = 1;
	pa = A->rowhead[1];
	pb = B->rowhead[1];
	A->len += B->len;
	while (i++ < A->rowsum)
	{
		papre = A->rowhead[i-1];
		if (pa == NULL && pb)
		{
			pa->right = pb;
			pa = A->rowhead[i];
			pb = B->rowhead[i];
			continue;
		}
		if (pa && pb)
		{
			while (pa && pb)
			{
				if (pa->col < pb->col)
				{
					papre = pa;
					pa = pa->right;
				}
				else if (pa->col > pb->col)
				{
					papre->right = pb;
					pb = pb->right;
					papre = papre->right;
					papre->right = pa;
				}
				else
				{
					int sum = pa->value + pb->value;
					if (sum)
					{
						pa->value = sum;
						papre = pa;
						pa = pa->right;
						pb = pb->right;
					}
					else
					{
						nodeptr temp = pa;
						papre->right = pa->right;
						pa = pa->right;
						free(temp);
					}
				}
			}
		}
		pa = A->rowhead[i];
		pb = B->rowhead[i];
	}
}

void printlist(crosslist* list)
{
	int i;
	nodeptr p;
	for (i = 1; i <= list->rowsum; i++)
	{
		for (p = list->rowhead[i]; p; p = p->right)
		{
			printf("%d %d %d\n", p->row, p->col, p->value);
		}
	}
}

int main()
{
	crosslist *A, *B;
	A = (crosslist*)malloc(sizeof(crosslist));
	B = (crosslist*)malloc(sizeof(crosslist));

	int rowsum, colsum;
	scanf_s("%d", &rowsum);
	scanf_s("%d", &colsum);
	A->rowsum = rowsum;
	A->colsum = colsum;
	B->rowsum = rowsum;
	B->colsum = colsum;
	scanf_s("%d", &A->len);
	scanf_s("%d", &B->len);
	createlist(A, rowsum, colsum);
	createlist(B, rowsum, colsum);

	addition(A, B);
	printlist(A);

	free(A->rowhead);
	free(A->colhead);
	free(B->rowhead);
	free(B->colhead);

	return 0;
}