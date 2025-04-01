//设计一个算法，实现m行n列的二维数组a的就地转置，当m≠n时返回false，否则返回true。
#include<iostream>
#include<vector>
using namespace std;

bool transpose(vector<vector<float>>&a, int n, int m)
{
	if (m != n)
		return false;
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i > j)
			{
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
	return true;
}

void printarray(vector<vector<float>> a, int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int m, n;
	cout << "请输入二维数组的行数：";
	cin >> m;
	cout << "请输入二维数组的列数：";
	cin >> n;
	vector<vector<float> > a(m, vector<float>(n));
	cout << "请输入二维数组：" << endl;
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	if(transpose(a,n,m))
	{
		cout << "行列转置后的数组：" << endl;
		printarray(a, n, m);
	}

	return 0;
}