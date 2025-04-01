//���һ���۰�����㷨����ʼ���ݴӴ�С�ݼ����У�Ҫ���ڳ�ʼ��������ʱ�ƶ�Ԫ�صĴ���Ϊ�㡣
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

void BinInsertSort(vector<int>& R, int n)	//���Ĵ���
{
	bool sorted = true;	//����һ���ж�ԭʼ�����Ƿ��Լ��ź���Ĳ�����
	for (int i = 0; i < n - 1; i++)
	{
		if (R[i] <= R[i + 1])
			continue;
		else
		{
			sorted = false;
			break;
		}
	}
	if(!sorted)		//���Ѿ��ź��������²����ٽ�������ֱ���˳���������
	{
		for (int i = 1; i < n; i++)
		{
			if (R[i] > R[i - 1])
			{
				int tmp = R[i];
				int low = 0, high = i - 1;

				while (low <= high)		//��whileѭ��Ϊ���ֲ��ң��ҵ�R[i]Ӧ�ò����λ��
				{
					int mid = (low + high) / 2;
					if (tmp > R[mid])
						high = mid - 1;
					else
						low = mid + 1;
				}

				for (int j = i - 1; j >= high + 1; j--)	//Ԫ�غ���
				{
					R[j + 1] = R[j];
				}
				R[high + 1] = tmp;	//����
			}
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	BinInsertSort(R, R.size());	
	Print_Array(R);

	return 0;
}