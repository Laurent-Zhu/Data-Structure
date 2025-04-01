//�ʣ���һ���������������˳���L�����һ���㷨������x�����ʵ�λ���Ա��ָñ�������ԣ��������㷨��ʱ��Ϳռ临�Ӷȣ����磬L = (1, 3, 5.7), ����x = 6��L = (1, 3, 5, 6, 7)��
//��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���������¡�
//ps:��ʦ�ã���ҵ�е�˳�����ֱ��ʹ�������ˣ�û����������û�����Ĳ��֡��������ĿҲ����ˡ�
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
		cout << "˳����������޷�������Ԫ��" << endl;
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

	cout << "ԭ˳���:";
	PrintList(list);

	Insert(list, 6);
	Insert(list, 7);
	Insert(list, 10);

	cout << "����6��7��10���˳���";
	PrintList(list);
	
	return 0;
}