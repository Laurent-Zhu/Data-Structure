//利用队列设计一个快速排序的非递归算法。
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int Partition(vector<int>& R, int s, int t)		//划分操作（一趟快速排序）
{
	int i = s;
	int j = t;
	int base = R[s];
	while (i < j)
	{
		while (i < j && R[j] > base)
		{
			j--;
		}
		if (i < j)
		{
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i] <= base)
		{
			i++;
		}
		if (i < j)
		{
			R[j] = R[i];
			j--;
		}
	}
	R[i] = base;
	return i;
}
int pos;
void QuickSort(vector<int>& R, int length)	//核心代码，采用队列实现快速排序
{
	queue<int> qu;
	int left = 0;
	int right = length - 1;
	int pos = Partition(R, left, right);
	if (pos > 1)
	{
		qu.push(left);
		qu.push(pos - 1);
	}
	if (pos < right - 1)
	{
		qu.push(pos + 1);
		qu.push(right);
	}
	while (!qu.empty())
	{
		left = qu.front();
		qu.pop();
		right = qu.front();
		qu.pop();
		pos = Partition(R, left, right);
		if (left < pos - 1)
		{
			qu.push(left);
			qu.push(pos - 1);
		}
		if (pos + 1 < right)
		{
			qu.push(pos + 1);
			qu.push(right);
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	QuickSort(R, R.size());
	Print_Array(R);

	return 0;
}