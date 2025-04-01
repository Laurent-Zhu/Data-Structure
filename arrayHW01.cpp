//设计一个算法，将含有n个整数元素的数组a[0…n-1]循环右移m位，要求算法的空间复杂度为O（1）。
#include<iostream>
using namespace std;

void CycleMove(int*& a, int n)
{
	int temp = a[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = temp;
}

int main()
{
	int n, m;
	cout << "你要输入的整数个数：";
	cin >> n;
	int *a = new int[n];
	cout << "请输入" << n << "个整数：";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "请输入你要右移的位数：";
	cin >> m;
	for (i = 0; i < m; i++)
	{
		CycleMove(a, n);
	}
	cout << "循环右移" << m << "位后的数组：";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}