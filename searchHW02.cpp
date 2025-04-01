//假设关键字有序表为整数，修改基本折半查找算法，给出在成功查找到关键字k时的查找序列。
#include<iostream>
#include<vector>

using namespace std;

int times = 0;
vector<int> R;
vector<int> ans;	//用来储存查找序列

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

	if (k > R[R.size() - 1] || k < R[0])
		return false;
	int low = 0;
	int high = R.size();
	int mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == R[mid])
		{
			times++;
			ans.push_back(R[mid]);	//增加的部分
			return true;
		}
		else if (k < R[mid])
		{
			times++;
			ans.push_back(R[mid]);
			high = mid - 1;
		}
		else
		{
			times++;
			ans.push_back(R[mid]);
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
		cout << "查找序列为：";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
		cout << "比较次数共计" << times << "次" << endl;
	}
	else
	{
		cout << "未找到该关键字对应的元素" << endl;
	}

	return 0;
}