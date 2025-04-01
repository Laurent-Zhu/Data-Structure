#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Stu {
public:
	int score;
	string name;
	Stu(int s, string n):score(s), name(n){}
};

int main()
{
	int n;
	cin >> n;
	vector<Stu> students;
	for (int i = 0; i < n; i++)
	{
		int tmp1;
		string tmp2;
		cin >> tmp1 >> tmp2;
		Stu* tmp = new Stu(tmp1, tmp2);
		students.push_back(*tmp);
		delete tmp;
	}
	int score_max = students[0].score;
	int maxIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (students[i].score > score_max)
		{
			score_max = students[i].score;
			maxIndex = i;
		}
	}
	cout << students[maxIndex].name;
	return 0;
}