#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> names;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		names.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		if (names[i][0] >= 97 && names[i][0] <= 122)
			names[i][0] -= 32;
		for (int j = 1; j < names[i].size(); j++)
		{
			if (names[i][j] >= 65 && names[i][j] <= 90)
				names[i][j] += 32;
		}
		cout << names[i] << endl;
	}

	return 0;
}