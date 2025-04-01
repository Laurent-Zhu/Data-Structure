//设计一个双向冒泡排序的算法，在排序过程中交替改变扫描方向。
#include<iostream>
#include<vector>
using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void BubbleSort(vector<int>& R, int n)	//核心代码
{
	int lstart = 0;	//标识从左向右冒泡的起点
	int rstart = n - 1;	//标识从右向左冒泡的起点
	int temp = 0;
	int exchanged = false;
	while (lstart < rstart)		//双向冒泡排序
	{
		for (int i = lstart; i < rstart; i++)	//从左向右冒泡
		{
			if (R[i] > R[i + 1])
			{
				swap(R[i], R[i + 1]);
				temp = i;
				exchanged = true;
			}
		}
		if (!exchanged)
			return;
		rstart = temp;

		for (int i = rstart; i > lstart; i--)	//从右向左冒泡
		{
			if (R[i] < R[i - 1])
			{
				swap(R[i], R[i - 1]);
				temp = i;
				exchanged = true;
			}
		}
		if (!exchanged)
			return;
		lstart = temp;
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	BubbleSort(R, R.size());
	Print_Array(R);

	return 0;
}