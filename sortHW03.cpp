//设计一个算法，对于R[low..high](0<=low<=high<=n)的部分元素采用冒泡排序方法实现递增排序。
#include<vector>
#include<iostream>
using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void BubbleSort(vector<int>& R, int n, int low, int high)	//核心代码
{
	for (int i = low; i < n; i++)
	{
		bool exchange = false;	//用来标识一轮排序是否有交换
		for (int j = high; j > i; j--)
		{
			if (R[j] < R[j - 1])	
			{
				swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)	//若一轮排序没有发生交换，说明以及排好了，直接退出函数
			return;
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	cout << "原序列：";
	Print_Array(R);
	int low;
	int high;
	cout << "输入要排序的部分的上下界索引（输入：下界 上界）：";
	cin >> low;
	cin >> high;
	BubbleSort(R, R.size(), low, high);
	cout << "对索引范围为" << low << "到" << high << "的元素排序后：";
	Print_Array(R);

	return 0;
}