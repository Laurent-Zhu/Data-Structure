//���һ���㷨�������������������йؼ���Ϊk�Ľ���ǰ�����pre���������д��ڹؼ���Ϊk�Ľ�㣬��û��ǰ����㣬��pre=NULL��
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<typename T1, typename T2>
struct BSTNode		//�����������������
{
	T1 key;		//��
	T2 data;	//ֵ
	BSTNode* lchild;	//����
	BSTNode* rchild;	//�Һ���

	BSTNode(T1 k, T2 d)		//���캯��
	{
		key = k;
		data = d;
		lchild = rchild = NULL;
	}
};

bool found = false;

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//�����
	BSTNode<T1, T2>* f;		//��ʱ��Ŵ�ɾ������˫��

	BSTClass() :r(NULL), f(NULL) {}

	BSTNode<T1, T2>* Find_Next(int k)	//���ҵ����k�����ҵ�k�������������½ǵĽ��
	{
		BSTNode<T1, T2>* p = NULL;
		BSTNode<T1, T2>* kptr = NULL;
		Find_k(r, kptr, k);

		p = kptr->lchild;
		while (p->rchild != NULL)
		{
			found = true;
			p = p->rchild;
		}
		return p;
	}
	void Find_k(BSTNode<T1, T2>* p, BSTNode<T1, T2>*& kptr, int k)	//������������ҵ����k
	{
		if (p != NULL)
		{
			Find_k(p->lchild, kptr, k);
			if (p->key == k)
			{
				kptr = p;
				return;
			}
			Find_k(p->rchild, kptr, k);
		}
	}

	void InsertBST(T1 k, T2 d)
	{
		r = _InsertBST(r, k, d);
	}
	BSTNode<T1, T2>* _InsertBST(BSTNode<T1, T2>* p, T1 k, T2 d)	//������
	{
		if (p == NULL)
			p = new BSTNode<T1, T2>(k, d);
		else if (k < p->key)
			p->lchild = _InsertBST(p->lchild, k, d);
		else if (k > p->key)
			p->rchild = _InsertBST(p->rchild, k, d);
		else
			p->data = d;
		return p;
	}

	void CreateBST(vector<T1>& KEY, vector<T2>& DATA)	//��������������
	{
		r = new BSTNode<T1, T2>(KEY[0], DATA[0]);
		for (int i = 0; i < KEY.size(); i++)		//ÿ���һ��������һ�β��뺯��
		{
			InsertBST(KEY[i], DATA[i]);
		}
	}
};

int main()
{
	vector<int> keys;
	vector<char> datas;
	BSTClass<int, char> example;

	cout << "��Ҫ��������ݸ�����";
	int n;
	cin >> n;
	cout << "����" << n << "��������������";
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		keys.push_back(k);
	}
	cout << "����" << n << "���ַ���";
	for (int i = 0; i < n; i++)
	{
		char d;
		cin >> d;
		datas.push_back(d);
	}
	example.CreateBST(keys, datas);
	int k;
	cout << "������Ҫ���ҵĽ��Ĺؼ���k��";
	cin >> k;
	BSTNode<int, char>* pre = example.Find_Next(k);
	if (pre != NULL)
	{
		cout << "�ؼ���Ϊ" << k << "�Ľ���ǰ�����Ĺؼ���Ϊ��" << pre->key << endl;
	}
	else cout << "�ؼ���Ϊ" << k << "�Ľ��û��ǰ�����" << endl;
	
	return 0;
}