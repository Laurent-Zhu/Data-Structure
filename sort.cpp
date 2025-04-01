//�ڲ�����
//��Ϊ���������򣬽�������ѡ�����򣬹鲢���򣬻�������
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

void Print_Array(vector<int>& R)	//չʾ����
{
	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i] << " ";
	}
	cout << endl;
}

void InsertSort(vector<int>& R, int n)	//�������򡪡�ֱ�Ӳ�������
{
	for (int i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])
		{
			int tmp = R[i];
			int j = i - 1;
			while (j >= 0 && tmp < R[j])
			{
				R[j + 1] = R[j];
				j--;
			}
			R[j + 1] = tmp;
		}
	}
}

void BinInsertSort(vector<int>& R, int n)	//�������򡪡��۰��������
{
	for (int i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])
		{
			int tmp = R[i];
			int low = 0, high = i - 1;

			while (low <= high)		//��whileѭ��Ϊ���ֲ��ң��ҵ�R[i]Ӧ�ò����λ��
			{
				int mid = (low + high) / 2;
				if (tmp < R[mid])
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

void ShellSort(vector<int>& R, int n)	//�������򡪡�ϣ�����򣬺������ڷ���
{
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d; i < n; i++)	//�����forѭ��ʵ���Ͼ��Ǽ��Ϊd�Ĳ�������
		{
			if (R[i] < R[i - d])
			{
				int tmp = R[i];
				int j = i - d;
				do
				{
					R[j + d] = R[j];
					j = j - d;
				} while (j >= 0 && R[j] > tmp);
				R[j + d] = tmp;
			}
		}
		d = d / 2;
	}
}

void BubbleSort(vector<int>& R, int n)	//���������򡪡�ð������
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;	//������ʶһ�������Ƿ��н���
		for (int j = n - 1; j > i; j--)
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

int Partition(vector<int>& R, int s, int t)		//���ֲ�����һ�˿�������
{
	int i = s;
	int j = t;
	int base = R[s];
	while (i < j)
	{
		while (i < j && R[j] > base)
		{
			j--;
		}
		if (i < j)
		{
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i] <= base)
		{
			i++;
		}
		if (i < j)
		{
			R[j] = R[i];
			j--;
		}
	}
	R[i] = base;
	return i;
}
int pos;
void QuickSort(vector<int>& R, int low, int high)	//���������򡪡���������ÿ��ѡһ����׼��Ϊ�ֽ�㣬����Partition������С�ķ�����ǰ�棬��ķź��棬ֱ�������еĳ���С�ڵ���1
{
	if (low < high)
	{
		pos = Partition(R, low, high);
		QuickSort(R, low, pos - 1);
		QuickSort(R, pos + 1, high);
	}
}

void SelectSort(vector<int>& R, int n)	//ѡ�������򡪡���ѡ������ÿ������������ѡ����С��Ԫ�ؼ���������
{
	for (int i = 0; i < n; i++)
	{
		int min_pos = i;	//��ʱR[i]��������������
		for (int j = i + 1; j < n; j++)
		{
			if (R[j] < R[min_pos])
				min_pos = j;
		}
		if (min_pos != i)
			swap(R[i], R[min_pos]);
	}
}

//***********************************ѡ��������������ѡ�����򡢶����򣬴˴��Թ�***********************************

void Merge(vector<int>& R, int low, int mid, int high)	//�Դ����һ�����н��ж�·�鲢
{
	vector<int> R1;	//�����ռ�
	R1.resize(high - low + 1);
	int i = low;
	int j = mid + 1;
	int k = 0;
	while ((i <= mid) && (j <= high))	//�鲢
	{
		if (R[i] <= R[j])
		{
			R1[k] = R[i];
			k++;
			i++;
		}
		else
		{
			R1[k] = R[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid)	//��ʣ���ֱ�Ӽ��븨���ռ�
	{
		R1[k] = R[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		R1[k] = R[j];
		k++;
		j++;
	}
	for (k = 0, i = low; k < R1.size(); k++, i++)	//���ƻ�ԭ�ռ�
	{
		R[i] = R1[k];
	}
}
void MergePass(vector<int>& R, int length)	//һ�˹鲢�������鲢���ڵ���������Ϊlength���ӱ�
{
	/*int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(R, low, mid);
		MergeSort(R, mid + 1, high);
		Merge(R, low, mid, high);
	}*/
	int n = R.size();
	int i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length < n)
		Merge(R, i, i + length - 1, n - 1);
}
void MergeSort(vector<int>& R, int n)	//�鲢�����򡪡���·�鲢����
{
	for (int length = 1; length < n; length *= 2)
	{
		MergePass(R, length);
	}
}




int main()
{
	vector<int> R = { 1,24,3,2,3,1,42,53,56,68,343,24 };
	//InsertSort(R, R.size());
	//BinInsertSort(R, R.size());
	//ShellSort(R, R.size());
	//BubbleSort(R, R.size());
	QuickSort(R, 0, R.size() - 1);
	//SelectSort(R, R.size());
	//MergeSort(R, R.size());
	Print_Array(R);


	return 0;
}