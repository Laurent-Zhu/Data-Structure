#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	int m;
	vector<int> array;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		array.push_back(tmp);
	}
	int sum = 0;
	cin >> m;
	for (int i = 0; i < array.size(); i++)
	{
		if (m == array[i])
			sum++;
	}
	cout << sum;
	return 0;
}