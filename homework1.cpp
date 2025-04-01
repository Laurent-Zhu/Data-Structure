//问：有一个递增有序的整数顺序表L，设计一个算法将整数x插入适当位置以保持该表的有序性，并给出算法的时间和空间复杂度，例如，L = (1, 3, 5.7), 插入x = 6后L = (1, 3, 5, 6, 7)。
//答：时间复杂度为O(n),空间复杂度为O(1)，代码如下。
//ps:老师好，作业中的顺序表我直接使用例子了，没有再设计让用户输入的部分。后面的题目也是如此。
#include<iostream>
#define MAXSIZE 40
using namespace std;

struct sqlist
{
	int length;
	int SqList[MAXSIZE];
};

void Insert(sqlist& list, int x)
{
	if (list.length >= MAXSIZE) 
	{
		cout << "顺序表已满，无法插入新元素" << endl;
		return;
	}

	for (int i = 0; i < list.length; i++)
	{
		if (x <= list.SqList[i])
		{

			for (int j = list.length - 1; j >= i; j--)
			{
				list.SqList[j + 1] = list.SqList[j];
			}
			list.length++;
			list.SqList[i] = x;
			return;
		}
	}
	list.SqList[list.length] = x;
	list.length++;
}
void InitList(sqlist& list)
{
	list.length = 5;
	list.SqList[0] = 1;
	list.SqList[1] = 3;
	list.SqList[2] = 5;
	list.SqList[3] = 7;
	list.SqList[4] = 9;
}
void PrintList(sqlist& list)
{
	for (int i = 0; i < list.length; i++)
	{
		cout << list.SqList[i] << ' ';
	}
	cout << endl;
}
int main()
{
	sqlist list;
	InitList(list);

	cout << "原顺序表:";
	PrintList(list);

	Insert(list, 6);
	Insert(list, 7);
	Insert(list, 10);

	cout << "插入6，7，10后的顺序表：";
	PrintList(list);
	
	return 0;
}