//��һ������n������Ԫ�ص�����a[0��n-1]�����һ���㷨���������һ����СԪ�ص��±ꡣ
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
	cout << "��Ҫ���������������";
	cin >> n;
	int* a = new int[n];
	cout << "������" << n << "��������";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "���һ����СԪ�ص��±꣺" << GetLastMin(a, n) << endl;

	return 0;
}