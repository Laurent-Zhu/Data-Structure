//���һ���۰�����㷨����ɹ����ҵ��ؼ���Ϊk��Ԫ������ؼ��ֵıȽϴ���������R[mid]=k��k<R[mid]�ıȽϼ�Ϊһ�αȽϡ�
#include<iostream>
#include<vector>
using namespace std;

vector<int> R;
int times = 0;		//�Ƚϴ���������Ϊȫ�ֱ���

void GetList()
{
	int n;
	cout << "�������е�Ԫ�ظ�����";
	cin >> n;
	cout << "����" << n << "����������С���󣩣�";
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		R.push_back(x);
	}
}

bool BinSearch()	//���Ĵ���
{
	int k;
	cout << "����ؼ���k��";
	cin >> k;
	int low = 0;
	int high = R.size();
	int mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == R[mid])
		{
			times++;
			return true;
		}
		else if (k < R[mid])
		{
			times++;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

int main()
{
	GetList();
	bool find = BinSearch();
	if (find)
	{
		cout << "�Ƚϴ���Ϊ" << times << endl;
	}
	else
	{
		cout << "δ�ҵ��ùؼ��ֶ�Ӧ��Ԫ��" << endl;
	}
	
	return 0;
}