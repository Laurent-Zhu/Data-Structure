#include <time.h>
#include <iostream>
#include <list>
#include<math.h>
using namespace std;

// 估测要计算的次数
// 方法一：
int count(int n)
{
	int i = 1;
	double sum = 0;
	int a, b;
	while (1)
	{
		a = 2 * i + 1;
		b = i;
		sum = sum + log10(a / b);
		i++;
		if (sum > n + 1) {
			return i;
		}
	}
}

// 方法二：
/*int count(int n)
{
	double ret = (double)n;
	return (int)(ret / 0.3);
}*/

int main()
{
	// 定义我们需要多少个结点
#define NODE_NUM 550
	list<int> num(NODE_NUM, 0);// 存放R(n)
	list<int> sum(NODE_NUM, 0);// 存放Sum(n)
	int print;// 所需精度
	cin >> print;
	int cnt = count(print);// 所需迭代次数

	// 我们直接将 R(1) 初始化为2，这样就可以免去后面再统一乘2
	num.front() = 2;
	sum.front() = 2;

	// 这里循环的 i 就是 n 
	for (int i = 1; i <= cnt; ++i)
	{
		int ret = 0;// 记录进位，补位情况

		// 计算R(n + 1)

		   // 计算 R(n) * n
		for (list<int>::reverse_iterator cur1 = num.rbegin(); cur1 != num.rend(); cur1++)
		{
			// 每一位都是本位乘i，再加上进位
			int val = *cur1 * i + ret;
			// 保存进位
			ret = val / 10;
			// 保存本位
			*cur1 = val % 10;
		}

		ret = 0;
		// 计算 R(n) * n / (2n + 1)
		for (list<int>::iterator cur1 = num.begin(); cur1 != num.end(); cur1++)
		{
			// 除数
			int div = (i << 1) + 1;
			// 加上前一位的余数
			int val = *cur1 + ret * 10;
			// 除法，保存本位
			*cur1 = val / div;
			// 保存余数
			ret = val - *cur1 * div;
		}

		ret = 0;
		// 计算 sum += R(n + 1)
		for (auto cur2 = sum.rbegin(), cur1 = num.rbegin(); cur2 != sum.rend(); cur2++, cur1++)
		{
			// 大数加法
			int val = *cur1 + *cur2 + ret;
			*cur2 = val % 10;
			ret = val / 10;
		}

	}
	// 打印
	cout << sum.front() << '.';
	list<int>::iterator it = sum.begin();
	it++;

	int i = 0;
	while (i < print)
	{
		cout << *it;
		it++;
		i++;
	}

	return 0;
}
