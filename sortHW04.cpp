//���һ��˫��ð��������㷨������������н���ı�ɨ�跽��
#include<iostream>
#include<vector>
using namespace std;

void Print_Array(vector<int>& R)	//չʾ����
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void BubbleSort(vector<int>& R, int n)	//���Ĵ���
{
	int lstart = 0;	//��ʶ��������ð�ݵ����
	int rstart = n - 1;	//��ʶ��������ð�ݵ����
	int temp = 0;
	int exchanged = false;
	while (lstart < rstart)		//˫��ð������
	{
		for (int i = lstart; i < rstart; i++)	//��������ð��
		{
			if (R[i] > R[i + 1])
			{
				swap(R[i], R[i + 1]);
				temp = i;
				exchanged = true;
			}
		}
		if (!exchanged)
			return;
		rstart = temp;

		for (int i = rstart; i > lstart; i--)	//��������ð��
		{
			if (R[i] < R[i - 1])
			{
				swap(R[i], R[i - 1]);
				temp = i;
				exchanged = true;
			}
		}
		if (!exchanged)
			return;
		lstart = temp;
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	BubbleSort(R, R.size());
	Print_Array(R);

	return 0;
}