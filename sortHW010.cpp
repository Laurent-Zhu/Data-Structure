//��n��ѧ��Ԫ����˳���R��ţ�ÿ��ѧ�����������Ͱ�ţ����ȡֵΪ0-5�����һ��ʱ�临�Ӷ�ΪO��n�����㷨��R�е�����ѧ��Ԫ�ذ���ŵ�������
//�����ʺ�ʹ��Ͱ����
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

vector<Stu*> buckets(6);	//����Ͱ��Ϊȫ�ֱ���

void BucketSort(vector<Stu>& R)		//���Ĵ��룬ʹ��Ͱ����ʵ��
{
	for (int i = 0; i < R.size(); i++)
	{
		int num = R[i].cl_num;
		R[i].next = buckets[num];
		buckets[num] = &R[i];
	}
	cout << "���������£�\n";
	for (int i = 0; i < 6; i++)
	{
		Stu* p = buckets[i];
		while (p != NULL)
		{
			cout << "[����" << p->name << "�༶" << p->cl_num << "] ";
			p = p->next;
		}
	}
	cout << endl;
}

int main()
{
	cout << "����ѧ��������";
	int n;
	cin >> n;
	vector<Stu> R(n);
	cout << "����" << n << "��ѧ���İ�ţ�";
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