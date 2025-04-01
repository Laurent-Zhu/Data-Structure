#include<stdio.h>
#define MAXSIZE 200
typedef struct {
	int row, col;
	int data;
}node;
typedef struct {
	node Node[MAXSIZE + 1];
	int rowpos[MAXSIZE];
	int m, n, len;
}matrix, *matptr;

void getmat(matptr Mat)
{
	scanf_s("%d", &Mat->n);
	scanf_s("%d", &Mat->m);
	int row, col, data;
	int i = 0;
	while (1)
	{
		scanf_s("%d", &row);
		scanf_s("%d", &col);
		scanf_s("%d", &data);
		if (row == 0 && col == 0 && data == 0)
		{
			break;
		}
		Mat->Node[i].row = row;
		Mat->Node[i].col = col;
		Mat->Node[i].data = data;
		i++;
	}
	Mat->len = i;

	int num[100];
	for (int i = 0; i < Mat->n; i++)
		num[i] = 0;
	for (int i = 0; i < Mat->len; i++)
		num[Mat->Node[i].row]++;
	Mat->rowpos[0] = 0;
	for (int i = 1; i <= Mat->n; i++)
		Mat->rowpos[i] = Mat->rowpos[i - 1] + num[i - 1];
}

void Multiplication(matptr A, matptr B, matptr C)
{
	int temp[200];
	for (int i = 0; i < 200; i++)
	{
		temp[i] = 0;
	}

	C->n = A->n;
	C->m = B->m;
	C->len = 0;

	int arow, anext_rowpos, brow, bnext_rowpos, ccol, p, q;
	if(A->len * B->len != 0)
	{
		for (arow = 1; arow <= A->n; arow++)
		{
			for (int i = 0; i < 200; i++)
			{
				temp[i] = 0;
			}
			
			if (arow < A->n)
				anext_rowpos = A->rowpos[arow + 1];
			else
				anext_rowpos = A->len;
			for (p = A->rowpos[arow]; p < anext_rowpos; p++)
			{
				brow = A->Node[p].col;
				if (brow < B->n)
					bnext_rowpos = B->rowpos[brow + 1];
				else
					bnext_rowpos = B->len;
				for (q = B->rowpos[brow]; q < bnext_rowpos; q++)
				{
					ccol = B->Node[q].col;
					temp[ccol] += A->Node[p].data * B->Node[q].data;
				}
			}
			for (ccol = 1; ccol <= C->m; ccol++)
			{
				if (temp[ccol])
				{
					C->Node[C->len].row = arow;
					C->Node[C->len].col = ccol;
					C->Node[C->len].data = temp[ccol];
					C->len++;
				}
			}
		}
	}
}

void PrintMat(matptr mat)
{
	int i;
	for (i = 0; i < mat->len; i++)
	{
		printf("%d %d %d\n", mat->Node[i].row, mat->Node[i].col, mat->Node[i].data);
	}
}

int main()
{
	matrix A, B, C;

	getmat(&A);
	getmat(&B);

	Multiplication(&A, &B, &C);
	PrintMat(&C);

	return 0;
}