//��һ����n(n<100)����������������a�����һ���㷨���ÿ�������˼·��ǰk(1<=k<=n)������Ԫ�ء�
#include<iostream>
#include<vector>

using namespace std;

void Print_Array(vector<int>& R)	//չʾ����
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int Partition(vector<int>& R, int s, int t)		//���ֲ�����һ�˿�������
{
	int i = s;
	int j = t;
	int base = R[s];
	while (i < j)
	{
		while (i < j && R[j] < base)
		{
			j--;
		}
		if (i < j)
		{
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i] >= base)
		{
			i++;
		}
		if (i < j)
		{
			R[j] = R[i];
			j--;
		}
	}
	R[i] = base;
	return i;
}
int pos;
void QuickSort(vector<int>& R, int low, int high, int k)	//��������
{
	if (low < high)
	{
		pos = Partition(R, low, high);
		QuickSort(R, low, pos - 1, k);
		QuickSort(R, pos + 1, high, k);
	}
}
void SelectMaxK(vector<int>& R, int k)	//ѡ��ǰk��Ԫ��
{
	QuickSort(R, 0, R.size() - 1, k);
	cout << "ǰ" << k << "�����Ԫ�أ�";
	for (int i = 0; i < k; i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	Print_Array(R);
	int k;
	cout << "����Ҫ�ҵ�ǰk��Ԫ��������";
	cin >> k;
	SelectMaxK(R, k);
	
	return 0;
}