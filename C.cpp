#include<iostream>
#include<math.h>

using namespace std;

int Pow(int a, int b, int mod) {
	int result = 1;
	a = a % mod;
	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return result;
}

int main()
{
	unsigned long long a;
	unsigned long long b;
	cin >> a;
	cin >> b;

	int day = Pow(a, b, 7);
	switch (day) 
	{
		case 0:
			cout << "Sunday";
			break;
		case 1:
			cout << "Monday";
			break;
		case 2:
			cout << "Tuesday";
			break;
		case 3:
			cout << "Wednesday";
			break;
		case 4:
			cout << "Thursday";
			break;
		case 5:
			cout << "Friday";
			break;
		case 6:
			cout << "Saturday";
			break;
	}
	return 0;
}