//���һ���㷨����һ��m��n�еĶ�ά��������a�����Ͻ�-���½Ǻ����Ͻ�-���½��������Խ���Ԫ��֮�ͣ���m��nʱ����false�����򷵻�true��
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
	cout << "�������ά�����������";
	cin >> m;
	cout << "�������ά�����������";
	cin >> n;
	vector<vector<int> > a(m, vector<int>(n));
	cout << "�������ά���飺" << endl;
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
		cout << "���Ͻǵ����½ǶԽ���Ԫ�غͣ�" << ltor << endl;
		cout << "���Ͻǵ����½ǶԽ���Ԫ�غͣ�" << rtol << endl;
	}
	else cout << "����������ȣ��޷����㡣" << endl;
	
	return 0;
}