#include<stdio.h>

int main()
{
	long long a, b;
	scanf_s("%lld %lld", &a, &b);
	if (a == b)
	{
		printf("%d", 0);
		return 0;
	}
	if ((a - b) % 100 > 0)
		printf("%lld", (a - b) / 100 + 1);
	else
		printf("%lld", (a - b) / 100);
	return 0;
}