#include <time.h>
#include <iostream>
#include <list>
#include<math.h>
using namespace std;

// ����Ҫ����Ĵ���
// ����һ��
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

// ��������
/*int count(int n)
{
	double ret = (double)n;
	return (int)(ret / 0.3);
}*/

int main()
{
	// ����������Ҫ���ٸ����
#define NODE_NUM 550
	list<int> num(NODE_NUM, 0);// ���R(n)
	list<int> sum(NODE_NUM, 0);// ���Sum(n)
	int print;// ���辫��
	cin >> print;
	int cnt = count(print);// �����������

	// ����ֱ�ӽ� R(1) ��ʼ��Ϊ2�������Ϳ�����ȥ������ͳһ��2
	num.front() = 2;
	sum.front() = 2;

	// ����ѭ���� i ���� n 
	for (int i = 1; i <= cnt; ++i)
	{
		int ret = 0;// ��¼��λ����λ���

		// ����R(n + 1)

		   // ���� R(n) * n
		for (list<int>::reverse_iterator cur1 = num.rbegin(); cur1 != num.rend(); cur1++)
		{
			// ÿһλ���Ǳ�λ��i���ټ��Ͻ�λ
			int val = *cur1 * i + ret;
			// �����λ
			ret = val / 10;
			// ���汾λ
			*cur1 = val % 10;
		}

		ret = 0;
		// ���� R(n) * n / (2n + 1)
		for (list<int>::iterator cur1 = num.begin(); cur1 != num.end(); cur1++)
		{
			// ����
			int div = (i << 1) + 1;
			// ����ǰһλ������
			int val = *cur1 + ret * 10;
			// ���������汾λ
			*cur1 = val / div;
			// ��������
			ret = val - *cur1 * div;
		}

		ret = 0;
		// ���� sum += R(n + 1)
		for (auto cur2 = sum.rbegin(), cur1 = num.rbegin(); cur2 != sum.rend(); cur2++, cur1++)
		{
			// �����ӷ�
			int val = *cur1 + *cur2 + ret;
			*cur2 = val % 10;
			ret = val / 10;
		}

	}
	// ��ӡ
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
