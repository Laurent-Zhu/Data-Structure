//�ʣ����������ϲ��õ������������˳���A��B�洢�����һ����ʱ���Ͼ����ܸ�Ч���㷨��
//�ʣ����������ϵĲ���C��C��Ȼ��˳���洢���������㷨��ʱ��Ϳռ临�Ӷȡ����� A=(1,3,5,7),B=(1,2,4,5,7),���� C=(1, 2��3, 4, 5, 7)��
//��ʱ�临�ӶȺͿռ临�ӶȾ�ΪO(m+n),�������¡�
#include<iostream>
#define MAXSIZE 40
using namespace std;

struct sqlist
{
	int length;
	int SqList[MAXSIZE];
};

void InitListA(sqlist& A)
{
	A.length = 4;
	A.SqList[0] = 1;
	A.SqList[1] = 3;
	A.SqList[2] = 5;
	A.SqList[3] = 7;
}

void InitListB(sqlist& B)
{
	B.length = 5;
	B.SqList[0] = 1;
	B.SqList[1] = 2;
	B.SqList[2] = 4;
	B.SqList[3] = 5;
	B.SqList[4] = 7;
}

void merge(sqlist& A, sqlist& B, sqlist& C)
{
	int i = 0, j = 0, k = 0;
	if (A.length + B.length > MAXSIZE)
	{
		cout << "˳���A��B����֮�ͳ�����󳤶ȣ��޷��ϲ�" << endl;
		return;
	}
	for (; i < A.length && j < B.length;k++,C.length++)
	{
		if (A.SqList[i] < B.SqList[j])
		{
			C.SqList[k] = A.SqList[i];
			i++;
		}
		else if (A.SqList[i] == B.SqList[j])
		{
			C.SqList[k] = A.SqList[i];
			i++;
			j++;
		}
		else
		{
			C.SqList[k] = B.SqList[j];
			j++;
		}
	}
	while (i < A.length)
	{
		C.SqList[k++] = A.SqList[i++];
	}
	while (j < B.length)
	{
		C.SqList[k++] = B.SqList[j++];
	}

}
void PrintList(sqlist& C)
{
	for (int i = 0; i < C.length; i++)
		cout << C.SqList[i] << " ";
	cout << endl;
}
int main()
{
	sqlist A, B, C;
	C.length = 0;
	InitListA(A);
	InitListB(B);
	cout << "˳���A:";
	PrintList(A);
	cout << "˳���B:";
	PrintList(B);
	merge(A, B, C);
	cout << "A��B����˳���C:";
	PrintList(C);


}

