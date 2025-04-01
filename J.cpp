#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> train;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		train.push_back(tmp);
	}
	int times = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (train[i] > train[j]) times++;
		}
	}
	cout << times;

	return 0;
}