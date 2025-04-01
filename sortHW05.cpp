//利用栈设计一个快速排序的非递归算法。
#include<vector>
#include<iostream>
#include<stack>
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
void QuickSort(vector<int>& R, int length)	//核心代码，采用栈来实现快速排序
{
	stack<int> st;
	int left = 0;
	int right = length - 1;
	int pos = Partition(R, left, right);
	if (pos > 0)
	{
		st.push(0);
		st.push(pos - 1);
	}
	if (pos < right - 1)
	{
		st.push(pos + 1);
		st.push(right);
	}
	while (!st.empty())
	{
		right = st.top();
		st.pop();
		left = st.top();
		st.pop();
		pos = Partition(R, left, right);
		if (left < pos - 1)
		{
			st.push(left);
			st.push(pos - 1);
		}
		if (pos + 1 < right)
		{
			st.push(pos + 1);
			st.push(right);
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	QuickSort(R, R.size());
	Print_Array(R);

	return 0;
}