//���һ���㷨��ʵ��m��n�еĶ�ά����a�ľ͵�ת�ã���m��nʱ����false�����򷵻�true��
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
	cout << "�������ά�����������";
	cin >> m;
	cout << "�������ά�����������";
	cin >> n;
	vector<vector<float> > a(m, vector<float>(n));
	cout << "�������ά���飺" << endl;
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
		cout << "����ת�ú�����飺" << endl;
		printarray(a, n, m);
	}

	return 0;
}