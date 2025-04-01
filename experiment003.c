//ϡ�����ת��
#include<stdio.h>
#define MAXSIZE 1000
typedef struct {
	int row, col;
	int data;
}node;
typedef struct {
	node Node[MAXSIZE + 1];
	int m, n, len;
}matrix;

void getmat(matrix* OldMat)
{
	scanf_s("%d", &OldMat->n);
	scanf_s("%d", &OldMat->m);
	int row, col, data;
	int i = 0;
	while (1)
	{
		scanf_s("%d", &row);
		scanf_s("%d", &col);
		scanf_s("%d", &data);
		if (row == 0 && col == 0 && data == 0)//������ĿҪ����������0ʱ�˳�ѭ��
		{
			break;
		}
		OldMat->Node[i].row = row;
		OldMat->Node[i].col = col;
		OldMat->Node[i].data = data;
		i++;
	}
	OldMat->len = i;
}

void transpose(matrix* Old, matrix* New)//���ھ������Ԫ���ʾ������һ�ζ�λ����ת�÷�
{
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];
	New->len = Old->len;
	New->m = Old->m;
	New->n = Old->n;
	if (New->len)
	{
		for (col = 0; col < Old->m; col++)
		{
			num[col] = 0;
		}
		for (t = 0; t < Old->len; t++)
		{
			num[Old->Node[t].col]++;//����ÿһ�з���Ԫ�صĸ���
		}
		position[0] =0;
		for (col = 1; col < Old->m; col++)//��col���е�һ������Ԫ�����¾����е���ȷλ��
		{
			position[col] = position[col - 1] + num[col - 1];
		}
		for (p = 0; p < Old->len; p++)
		{
			col = Old->Node[p].col;
			q = position[col];
			New->Node[q].row = Old->Node[p].col;//���л���
			New->Node[q].col = Old->Node[p].row;
			New->Node[q].data = Old->Node[p].data;
			position[col]++;
		}
	}
}

void PrintMat(matrix* mat)
{
	int i;
	for (i = 0; i < mat->len; i++)
	{
		printf("%d %d %d\n", mat->Node[i].row, mat->Node[i].col, mat->Node[i].data);
	}
}

int main()
{
	matrix OldMat, NewMat;

	getmat(&OldMat);
	transpose(&OldMat, &NewMat);
	PrintMat(&NewMat);

	return 0;
}