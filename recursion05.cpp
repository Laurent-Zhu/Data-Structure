//���ں�n������������a[0��n - 1]���������������Ԫ��ֵ��
//��1����n = 1���򷵻�a[0]��
//��2������ȡ�м�λ��mid�����ǰ�벿���е����Ԫ��ֵmax1����벿��
//�е����Ԫ��ֵmax2������max(max1, max2)��
//����ʵ���������̵ĵݹ��㷨��
#include<iostream>
#include<vector>
using namespace std;

int max(vector<int> a, int m, int n)
{
	if (n == 1)
		return a[0];
	int max1, max2;
	if (n == m)
		return a[m];
	else
	{
		int mid = (m + n) / 2;
		max1 = max(a, m, mid);
		max2 = max(a, mid + 1, n);	
	}
	return max1 >= max2 ? max1 : max2;
}

int main()
{
	int n;
	cout << "����Ԫ�ظ�����";
	cin >> n;
	vector<int> a(n);
	cout << "���������飨" << n << "��Ԫ�أ���";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	 n = a.size();
	cout << "���Ԫ��Ϊ" << max(a, 0, n-1) << endl;
	return 0;
}
