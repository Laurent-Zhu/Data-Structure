//���һ���㷨�����һ������������������ǰm��0<m<=�����������н��ĸ�����С�Ľ�����С�
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<int> min_m_nodes;

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

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//�����
	BSTNode<T1, T2>* f;		//��ʱ��Ŵ�ɾ������˫��

	BSTClass() :r(NULL), f(NULL) {}

	void Get_Min_m(int m)
	{
		Get_Min_m_1(r, m);
	}
	void Get_Min_m_1(BSTNode<T1, T2>* p, int m)	//���Ĵ��룬���ڶ�����������������õ���������ǰm��
	{
		if (p != NULL && min_m_nodes.size() <= m)
		{
			Get_Min_m_1(p->lchild, m);
			min_m_nodes.push_back(p->key);
			Get_Min_m_1(p->rchild, m);
		}
		return;
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

	int m;
	cout << "��������ҵ�ǰmС�Ľ����m��";
	cin >> m;
	example.Get_Min_m(m);
	cout << "ǰ" << m << "С�Ľ�����У�";
	for (int i = 0; i < m; i++)
		cout << min_m_nodes[i] << " ";
	cout << endl;

	return 0;
}