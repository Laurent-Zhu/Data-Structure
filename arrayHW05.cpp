//设计一个算法，求一个m行n列的二维整型数组a的左上角-右下角和右上角-左下角两条主对角线元素之和，当m≠n时返回false，否则返回true。
#include<iostream>
#include<vector>
using namespace std;

bool sum(vector<vector<int>> a, int n, int m, int& ltor, int& rtol)
{
	if (m != n) return false;
	ltor = 0;
	rtol = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		ltor += a[i][i];
		rtol += a[n - i - 1][i];
	}
	return true;
}

int main()
{
	int m, n;
	cout << "请输入二维数组的行数：";
	cin >> m;
	cout << "请输入二维数组的列数：";
	cin >> n;
	vector<vector<int> > a(m, vector<int>(n));
	cout << "请输入二维数组：" << endl;
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int ltor, rtol;
	if (sum(a, n, m, ltor, rtol))
	{
		cout << "左上角到右下角对角线元素和：" << ltor << endl;
		cout << "右上角到左下角对角线元素和：" << rtol << endl;
	}
	else cout << "行列数不相等，无法计算。" << endl;
	
	return 0;
}