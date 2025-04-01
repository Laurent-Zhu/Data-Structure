//设a是一个含有n个元素的double型数组，b是一个含有n个元素的整数数组，其值介于0∽n - 1，且所有元素不相同。
//现设计一个算法，要求按b的内容调整a中元素的顺序，例如当b[2] = 11时，要求将a[11]元素调整到a[2]中。
//如n = 5, a = { 1,2,3,4,5 }, b = { 2,3,4,1,0 }，执行本算法后a = { 3,4,5,1,2 }。
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
	cout << "你要输入的两个数组各自的元素个数：";
	cin >> n;
	float* a = new float[n];
	int* b = new int[n];
	cout << "请输入" << n << "个整数（数组a）：";
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "请输入" << n << "个整数（数组b）（0到"<<n-1<<"）：";
	for (i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	move(a, b, n);
	cout << "数组a重排后：";
	PrintArray(a, n);

	return 0;
}