#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> patients;
	int ages[4] = { 0 };
	double ratios[4] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp >= 0 && tmp <= 18)
			ages[0]++;
		else if (tmp >= 19 && tmp <= 35)
			ages[1]++;
		else if (tmp >= 36 && tmp <= 60)
			ages[2]++;
		else if (tmp >= 61)
			ages[3]++;
	}
	for (int i = 0; i < 4; i++)
	{
		ratios[i] = (double)(ages[i] * 100);
		ratios[i] = ratios[i] / n;
		printf("%.2f", ratios[i]);
		cout << "%" << endl;
	}
	return 0;
}