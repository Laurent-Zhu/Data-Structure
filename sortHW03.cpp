//���һ���㷨������R[low..high](0<=low<=high<=n)�Ĳ���Ԫ�ز���ð�����򷽷�ʵ�ֵ�������
#include<vector>
#include<iostream>
using namespace std;

void Print_Array(vector<int>& R)	//չʾ����
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void BubbleSort(vector<int>& R, int n, int low, int high)	//���Ĵ���
{
	for (int i = low; i < n; i++)
	{
		bool exchange = false;	//������ʶһ�������Ƿ��н���
		for (int j = high; j > i; j--)
		{
			if (R[j] < R[j - 1])	
			{
				swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)	//��һ������û�з���������˵���Լ��ź��ˣ�ֱ���˳�����
			return;
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	cout << "ԭ���У�";
	Print_Array(R);
	int low;
	int high;
	cout << "����Ҫ����Ĳ��ֵ����½����������룺�½� �Ͻ磩��";
	cin >> low;
	cin >> high;
	BubbleSort(R, R.size(), low, high);
	cout << "��������ΧΪ" << low << "��" << high << "��Ԫ�������";
	Print_Array(R);

	return 0;
}