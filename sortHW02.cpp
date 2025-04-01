//设计一个折半插入算法将初始数据从大到小递减排列，要求在初始数据正序时移动元素的次数为零。
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

void BinInsertSort(vector<int>& R, int n)	//核心代码
{
	bool sorted = true;	//加入一个判断原始序列是否以及排好序的布尔数
	for (int i = 0; i < n - 1; i++)
	{
		if (R[i] <= R[i + 1])
			continue;
		else
		{
			sorted = false;
			break;
		}
	}
	if(!sorted)		//在已经排好序的情况下不需再进行排序，直接退出函数即可
	{
		for (int i = 1; i < n; i++)
		{
			if (R[i] > R[i - 1])
			{
				int tmp = R[i];
				int low = 0, high = i - 1;

				while (low <= high)		//此while循环为二分查找，找到R[i]应该插入的位置
				{
					int mid = (low + high) / 2;
					if (tmp > R[mid])
						high = mid - 1;
					else
						low = mid + 1;
				}

				for (int j = i - 1; j >= high + 1; j--)	//元素后移
				{
					R[j + 1] = R[j];
				}
				R[high + 1] = tmp;	//插入
			}
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	BinInsertSort(R, R.size());	
	Print_Array(R);

	return 0;
}