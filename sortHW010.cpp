//设n个学生元素用顺序表R存放，每个学生包含姓名和班号，班号取值为0-5，设计一个时间复杂度为O（n）的算法将R中的所有学生元素按班号递增排序。
//本题适合使用桶排序
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Stu
{
	string name;
	int cl_num;
	Stu* next;
	Stu(){}
	Stu(int i) :cl_num(i), next(NULL) { name = "xxx"; }
};

vector<Stu*> buckets(6);	//六个桶作为全局变量

void BucketSort(vector<Stu>& R)		//核心代码，使用桶排序实现
{
	for (int i = 0; i < R.size(); i++)
	{
		int num = R[i].cl_num;
		R[i].next = buckets[num];
		buckets[num] = &R[i];
	}
	cout << "排序结果如下：\n";
	for (int i = 0; i < 6; i++)
	{
		Stu* p = buckets[i];
		while (p != NULL)
		{
			cout << "[姓名" << p->name << "班级" << p->cl_num << "] ";
			p = p->next;
		}
	}
	cout << endl;
}

int main()
{
	cout << "输入学生总数：";
	int n;
	cin >> n;
	vector<Stu> R(n);
	cout << "输入" << n << "个学生的班号：";
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		R[i].cl_num = tmp;
		R[i].name = "xxx";
	}
	BucketSort(R);

	return 0;
}