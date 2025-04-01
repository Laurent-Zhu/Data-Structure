//有一个含有n个整数元素的数组a[0…n-1]，设计一个算法求其中最后一个最小元素的下标。
#include<iostream>
using namespace std;

int GetLastMin(int* a, int n)
{
	int minpos = 0;
	int min = a[0];
	int i;
	for (i = 0; i < n; i++)
	{
		if (min >= a[i])
		{
			min = a[i];
			minpos = i;
		}
	}
	return minpos;
}

int main()
{
	int n, m;
	cout << "你要输入的整数个数：";
	cin >> n;
	int* a = new int[n];
	cout << "请输入" << n << "个整数：";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "最后一个最小元素的下标：" << GetLastMin(a, n) << endl;

	return 0;
}