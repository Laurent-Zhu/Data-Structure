//����ؼ��������Ϊ�������޸Ļ����۰�����㷨�������ڳɹ����ҵ��ؼ���kʱ�Ĳ������С�
#include<iostream>
#include<vector>

using namespace std;

int times = 0;
vector<int> R;
vector<int> ans;	//���������������

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

	if (k > R[R.size() - 1] || k < R[0])
		return false;
	int low = 0;
	int high = R.size();
	int mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == R[mid])
		{
			times++;
			ans.push_back(R[mid]);	//���ӵĲ���
			return true;
		}
		else if (k < R[mid])
		{
			times++;
			ans.push_back(R[mid]);
			high = mid - 1;
		}
		else
		{
			times++;
			ans.push_back(R[mid]);
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
		cout << "��������Ϊ��";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
		cout << "�Ƚϴ�������" << times << "��" << endl;
	}
	else
	{
		cout << "δ�ҵ��ùؼ��ֶ�Ӧ��Ԫ��" << endl;
	}

	return 0;
}