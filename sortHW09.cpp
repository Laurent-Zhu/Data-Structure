//���һ���㷨���ж�һ����������a[0..n-1]�Ƿ񹹳�һ������ѡ�
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

bool MaxHeap(vector<int>& R, int n)	//���Ĵ���
{
	bool answer = false;
	for (int i = 0; 2 * i + 1 < n; i++)
	{
		if (2 * i + 2 >= n)
		{
			if (R[i] < R[2 * i + 1])
				return false;
		}
		else
		{
			if (!(R[i] >= R[2 * i + 1] && R[i] >= R[2 * i + 2]))
				return false;
		}
	}
	return true;
}

int main()
{
	vector<int> R = { 98,77,35,62,55,14,35,48 };
	cout << "���У�";
	Print_Array(R);
	if (MaxHeap(R, R.size()))
		cout << "�Ǵ����" << endl;
	else
		cout << "���Ǵ����" << endl;

	return 0;
}