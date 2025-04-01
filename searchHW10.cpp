//�ڹ�ϣ������������+��������HashTable�������ASL1�����㷨��ɹ�����µ�ƽ�����ҳ��ȡ�
#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d) :data(d) { next = NULL; }
};

class HashTable
{
public:
	Node* HTable[100];	//���ͷָ�������
	int n;	//��ϣ����Ԫ�ظ���
	int m;	//��ϣ����

	HashTable(int m)
	{
		this->m = m;
		for (int i = 0; i < m; i++)
		{
			HTable[i] = NULL;
		}
		n = 0;
	}

	void Display()
	{
		for (int i = 0; i < m; i++)
		{
			Node* p = HTable[i];
			if (p == NULL)
			{
				cout << "NULL" << endl;
				continue;
			}
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	void CreateHT(vector<int> input)	//ʹ�ó���������+������������ϣ��
	{
		for (int i = 0; i < input.size(); i++)
		{
			int pos = input[i] % m;	//ȡ��
			Node* p = new Node(input[i]);
			p->next = HTable[pos];		//����
			HTable[pos] = p;
			n++;
		}
	}
	void remove(int k)	
	{
		int pos = k % m;
		Node* p = HTable[pos];
		Node* pre = p;
		if (p->data == k)
		{
			HTable[pos] = p->next;
			return;
		}
		while (p->data != k)
		{
			pre = p;
			p = p->next;
			if (p == NULL)
				break;
		}
		if (p == NULL)
		{
			cout << "û���ҵ���Ӧ�Ľ��" << endl;
			return;
		}
		else
		{
			pre->next = p->next;
			delete p;
		}
	}

	double ASL1(vector<int> input)		//������Ĵ���
	{
		int times = 0;
		double asl = 0;
		int n = input.size();

		for (int i = 0; i < input.size(); i++)
		{
			int pos = input[i] % m;
			Node* p = HTable[pos];
			while (p != NULL)
			{
				times++;
				p = p->next;
			}
		}
		asl = (double)times / (double)n;

		return asl;
	}
};

int main()
{
	int m;
	cout << "��ϣ���ȣ�";
	cin >> m;
	HashTable HT(m);
	vector<int> input;
	cout << "��Ҫ�����Ԫ�ظ�����";
	int n;
	cin >> n;
	cout << "������" << n << "��Ԫ�أ�";
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	HT.CreateHT(input);
	cout << "��ϣ�����£�" << endl;
	HT.Display();

	/*int k;
	cout << "������Ҫɾ���Ľ��ֵ��";
	cin >> k;
	HT.remove(k);
	cout << "ɾ�����" << k << "��Ĺ�ϣ�����£�" << endl;
	HT.Display();*/
	cout << "�ɹ�����µ�ƽ�����ҳ���Ϊ��" << HT.ASL1(input) << endl;

	return 0;
}