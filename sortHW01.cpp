//���һ�����������ֱ�Ӳ����㷨���������������ΪR[0..n-1]��
// ����R[0..i]Ϊ�������� R[i+1..n-1]Ϊ��������������������βԪ��R[i]����������������Ԫ�أ���ͷ��ʼ�����бȽϣ�
// �ҵ�һ���պô���R[i]��λ��j����R[i..j-1]Ԫ��ǰ�ƣ�Ȼ��ԭR[i]����R[j-1]��λ�á�
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

void InsertSort(vector<int>& R, int n)	//���Ĵ���
{
	for (int i = n - 2; i >= 0; i--)
	{
		if (R[i] > R[i + 1])
		{
			int tmp = R[i];
			int j = i + 1;
			while (j < n && tmp > R[j])
			{
				R[j - 1] = R[j];
				j++;
			}
			R[j - 1] = tmp;
		}
	}
}

int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	InsertSort(R, R.size());
	
	Print_Array(R);


	return 0;
}