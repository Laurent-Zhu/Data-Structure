//���һ���㷨��������n������Ԫ�ص�����a[0��n-1]ѭ������mλ��Ҫ���㷨�Ŀռ临�Ӷ�ΪO��1����
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
	cout << "��Ҫ���������������";
	cin >> n;
	int *a = new int[n];
	cout << "������" << n << "��������";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "��������Ҫ���Ƶ�λ����";
	cin >> m;
	for (i = 0; i < m; i++)
	{
		CycleMove(a, n);
	}
	cout << "ѭ������" << m << "λ������飺";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}