//回溯法
//有表达式为1□2□3□4，其中□为正或者负号，采用回溯法求出该表达式绝对值为4的所有表达式。
#include<iostream>
using namespace std;

int a[] = {1,2,3,4};
char x[4];

void solution(int i, int sum)
{
	if (i == 3)
	{
		if (abs(sum) == 4)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d", a[j]);
				printf("%c", x[j]);
			}
			printf("=%d\n", sum);
		}
		return;
	}
	x[i] = '+';
	sum += a[i + 1];
	solution(i + 1, sum);
	sum -= a[i + 1];
	x[i] = '-';
	sum -= a[i + 1];
	solution(i + 1, sum);
	sum += a[i + 1];
}

int main()
{
	int sum = 1;
	cout << "绝对值为4的表达式有：" << endl;
	solution(0, sum);

	return 0;
}