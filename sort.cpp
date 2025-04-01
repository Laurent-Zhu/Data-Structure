//内部排序
//分为：插入排序，交换排序，选择排序，归并排序，基数排序
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

void Print_Array(vector<int>& R)	//展示序列
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void InsertSort(vector<int>& R, int n)	//插入排序——直接插入排序
{
	for (int i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])
		{
			int tmp = R[i];
			int j = i - 1;
			while (j >= 0 && tmp < R[j])
			{
				R[j + 1] = R[j];
				j--;
			}
			R[j + 1] = tmp;
		}
	}
}

void BinInsertSort(vector<int>& R, int n)	//插入排序——折半插入排序
{
	for (int i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])
		{
			int tmp = R[i];
			int low = 0, high = i - 1;

			while (low <= high)		//此while循环为二分查找，找到R[i]应该插入的位置
			{
				int mid = (low + high) / 2;
				if (tmp < R[mid])
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

void ShellSort(vector<int>& R, int n)	//插入排序——希尔排序，核心在于分组
{
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d; i < n; i++)	//这里的for循环实际上就是间隔为d的插入排序
		{
			if (R[i] < R[i - d])
			{
				int tmp = R[i];
				int j = i - d;
				do
				{
					R[j + d] = R[j];
					j = j - d;
				} while (j >= 0 && R[j] > tmp);
				R[j + d] = tmp;
			}
		}
		d = d / 2;
	}
}

void BubbleSort(vector<int>& R, int n)	//交换类排序——冒泡排序
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;	//用来标识一轮排序是否有交换
		for (int j = n - 1; j > i; j--)
		{
			if (R[j] < R[j - 1])
			{
				swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)	//若一轮排序没有发生交换，说明以及排好了，直接退出函数
			return;
	}
}

int Partition(vector<int>& R, int s, int t)		//划分操作（一趟快速排序）
{
	int i = s;
	int j = t;
	int base = R[s];
	while (i < j)
	{
		while (i < j && R[j] > base)
		{
			j--;
		}
		if (i < j)
		{
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i] <= base)
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
void QuickSort(vector<int>& R, int low, int high)	//交换类排序——快速排序。每次选一个基准作为分界点，调用Partition，比它小的放在它前面，大的放后面，直到分序列的长度小于等于1
{
	if (low < high)
	{
		pos = Partition(R, low, high);
		QuickSort(R, low, pos - 1);
		QuickSort(R, pos + 1, high);
	}
}

void SelectSort(vector<int>& R, int n)	//选择类排序——简单选择排序。每次在无序区中选出最小的元素加入有序区
{
	for (int i = 0; i < n; i++)
	{
		int min_pos = i;	//此时R[i]是属于无序区的
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
			swap(R[i], R[min_pos]);
	}
}

//***********************************选择类排序还有树形选择排序、堆排序，此处略过***********************************

void Merge(vector<int>& R, int low, int mid, int high)	//对传入的一个序列进行二路归并
{
	vector<int> R1;	//辅助空间
	R1.resize(high - low + 1);
	int i = low;
	int j = mid + 1;
	int k = 0;
	while ((i <= mid) && (j <= high))	//归并
	{
		if (R[i] <= R[j])
		{
			R1[k] = R[i];
			k++;
			i++;
		}
		else
		{
			R1[k] = R[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid)	//将剩余的直接加入辅助空间
	{
		R1[k] = R[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		R1[k] = R[j];
		k++;
		j++;
	}
	for (k = 0, i = low; k < R1.size(); k++, i++)	//复制回原空间
	{
		R[i] = R1[k];
	}
}
void MergePass(vector<int>& R, int length)	//一趟归并，用来归并相邻的两个长度为length的子表
{
	/*int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(R, low, mid);
		MergeSort(R, mid + 1, high);
		Merge(R, low, mid, high);
	}*/
	int n = R.size();
	int i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length < n)
		Merge(R, i, i + length - 1, n - 1);
}
void MergeSort(vector<int>& R, int n)	//归并类排序——二路归并排序
{
	for (int length = 1; length < n; length *= 2)
	{
		MergePass(R, length);
	}
}




int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	//InsertSort(R, R.size());
	//BinInsertSort(R, R.size());
	//ShellSort(R, R.size());
	//BubbleSort(R, R.size());
	QuickSort(R, 0, R.size() - 1);
	//SelectSort(R, R.size());
	//MergeSort(R, R.size());
	Print_Array(R);


	return 0;
}