//有一个含n(n<100)个整数的无序序列a，设计一个算法利用快速排序思路求前k(1<=k<=n)个最大的元素。
#include<iostream>
#include<vector>

using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

int Partition(vector<int>& R, int s, int t)		//划分操作（一趟快速排序）
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
void QuickSort(vector<int>& R, int low, int high, int k)	//快速排序
{
	if (low < high)
	{
		pos = Partition(R, low, high);
		QuickSort(R, low, pos - 1, k);
		QuickSort(R, pos + 1, high, k);
	}
}
void SelectMaxK(vector<int>& R, int k)	//选出前k个元素
{
	QuickSort(R, 0, R.size() - 1, k);
	cout << "前" << k << "个最大元素：";
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
	cout << "输入要找的前k个元素数量：";
	cin >> k;
	SelectMaxK(R, k);
	
	return 0;
}