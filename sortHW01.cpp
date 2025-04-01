//设计一个递增排序的直接插入算法，设待排序序列问为R[0..n-1]，
// 其中R[0..i]为无序区， R[i+1..n-1]为有序区，对于无序区的尾元素R[i]，将其与有序区的元素（从头开始）进行比较，
// 找到一个刚好大于R[i]的位置j，将R[i..j-1]元素前移，然后将原R[i]插入R[j-1]的位置。
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

void InsertSort(vector<int>& R, int n)	//核心代码
{
	for (int i = n - 2; i >= 0; i--)
	{
		if (R[i] > R[i + 1])
		{
			int tmp = R[i];
			int j = i + 1;
			while (j < n && tmp > R[j])
			{
				R[j - 1] = R[j];
				j++;
			}
			R[j - 1] = tmp;
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	InsertSort(R, R.size());
	
	Print_Array(R);


	return 0;
}