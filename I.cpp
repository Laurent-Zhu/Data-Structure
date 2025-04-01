#include<iostream>

using namespace std;

int Hermite(int n, int x)
{
	if (n == 0) return 1;
	else if (n == 1) return 2 * x;
	else if(n > 1) return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
}

int main()
{
	int n, x;
	cin >> n >> x;
	int result = Hermite(n, x);
	cout << result;
	return 0;
}