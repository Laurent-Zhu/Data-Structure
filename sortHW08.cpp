//������n�������ؼ��ֵ�Ԫ�ش���˳���R�У����ü�ѡ�񷽷�����ѡ����С�����ǰm����0<m<<n����������
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print_Array(vector<int>& R)	//չʾ����
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void SelectSort(vector<int>& R, int n, int m)	//���Ĵ���
{
	for (int i = 0; i < m; i++)
	{
		int min_pos = i;	//��ʱR[i]��������������
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
			swap(R[i], R[min_pos]);
	}
	for (int i = 0; i < m; i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	Print_Array(R);
	int m;
	cout << "����Ҫ�ҵ�ǰm����СԪ��������";
	cin >> m;
	cout << "������£�" << endl;
	SelectSort(R, R.size(), m);

	return 0;
}