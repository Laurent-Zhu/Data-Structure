//设计一个折半查找算法，求成功查找到关键字为k的元素所需关键字的比较次数。假设R[mid]=k和k<R[mid]的比较计为一次比较。
#include<iostream>
#include<vector>
using namespace std;

vector<int> R;
int times = 0;		//比较次数，声明为全局变量

void GetList()
{
	int n;
	cout << "输入序列的元素个数：";
	cin >> n;
	cout << "输入" << n << "个整数（从小到大）：";
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		R.push_back(x);
	}
}

bool BinSearch()	//核心代码
{
	int k;
	cout << "输入关键字k：";
	cin >> k;
	int low = 0;
	int high = R.size();
	int mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == R[mid])
		{
			times++;
			return true;
		}
		else if (k < R[mid])
		{
			times++;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

int main()
{
	GetList();
	bool find = BinSearch();
	if (find)
	{
		cout << "比较次数为" << times << endl;
	}
	else
	{
		cout << "未找到该关键字对应的元素" << endl;
	}
	
	return 0;
}