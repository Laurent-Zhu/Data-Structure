//问：有两个集合采用递增有序的整数顺序表A，B存储，设计一个在时间上尽可能高效的算法，
//问：求两个集合的并集C，C仍然用顺序表存储，并给出算法的时间和空间复杂度。例如 A=(1,3,5,7),B=(1,2,4,5,7),并集 C=(1, 2，3, 4, 5, 7)。
//答：时间复杂度和空间复杂度均为O(m+n),代码如下。
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
		cout << "顺序表A、B长度之和超出最大长度，无法合并" << endl;
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
	cout << "顺序表A:";
	PrintList(A);
	cout << "顺序表B:";
	PrintList(B);
	merge(A, B, C);
	cout << "A、B并集顺序表C:";
	PrintList(C);


}

