//假设有n个整数关键字的元素存于顺序表R中，采用简单选择方法从中选出从小到大的前m个（0<m<<n）个整数。
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void SelectSort(vector<int>& R, int n, int m)	//核心代码
{
	for (int i = 0; i < m; i++)
	{
		int min_pos = i;	//此时R[i]是属于无序区的
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
			swap(R[i], R[min_pos]);
	}
	for (int i = 0; i < m; i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	Print_Array(R);
	int m;
	cout << "输入要找的前m个最小元素数量：";
	cin >> m;
	cout << "结果如下：" << endl;
	SelectSort(R, R.size(), m);

	return 0;
}