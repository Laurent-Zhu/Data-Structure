//��a��һ������n��Ԫ�ص�double�����飬b��һ������n��Ԫ�ص��������飬��ֵ����0��n - 1��������Ԫ�ز���ͬ��
//�����һ���㷨��Ҫ��b�����ݵ���a��Ԫ�ص�˳�����統b[2] = 11ʱ��Ҫ��a[11]Ԫ�ص�����a[2]�С�
//��n = 5, a = { 1,2,3,4,5 }, b = { 2,3,4,1,0 }��ִ�б��㷨��a = { 3,4,5,1,2 }��
#include<iostream>
using namespace std;

void move(float*& a, int * b, int n)
{
	float* c = new float[n];
	int i;
	for (i = 0; i < n; i++)
	{
		c[i] = a[i];
	}
	for (i = 0; i < n; i++)
	{
		a[i] = c[b[i]];
	}
}

void PrintArray(float* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "��Ҫ���������������Ե�Ԫ�ظ�����";
	cin >> n;
	float* a = new float[n];
	int* b = new int[n];
	cout << "������" << n << "������������a����";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "������" << n << "������������b����0��"<<n-1<<"����";
	for (i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	move(a, b, n);
	cout << "����a���ź�";
	PrintArray(a, n);

	return 0;
}