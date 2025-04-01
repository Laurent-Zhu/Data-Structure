//对于含n个整数的数组a[0…n - 1]，可以这样求最大元素值：
//（1）若n = 1，则返回a[0]。
//（2）否则，取中间位置mid，求出前半部分中的最大元素值max1，后半部分
//中的最大元素值max2，返回max(max1, max2)。
//给出实现上述过程的递归算法。
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
	cout << "数组元素个数：";
	cin >> n;
	vector<int> a(n);
	cout << "请输入数组（" << n << "个元素）：";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	 n = a.size();
	cout << "最大元素为" << max(a, 0, n-1) << endl;
	return 0;
}
