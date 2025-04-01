//设计一个算法，判断一个整数序列a[0..n-1]是否构成一个大根堆。
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

bool MaxHeap(vector<int>& R, int n)	//核心代码
{
	bool answer = false;
	for (int i = 0; 2 * i + 1 < n; i++)
	{
		if (2 * i + 2 >= n)
		{
			if (R[i] < R[2 * i + 1])
				return false;
		}
		else
		{
			if (!(R[i] >= R[2 * i + 1] && R[i] >= R[2 * i + 2]))
				return false;
		}
	}
	return true;
}

int main()
{
	vector<int> R = { 98,77,35,62,55,14,35,48 };
	cout << "序列：";
	Print_Array(R);
	if (MaxHeap(R, R.size()))
		cout << "是大根堆" << endl;
	else
		cout << "不是大根堆" << endl;

	return 0;
}