//���һ���㷨����һ�÷ǿ����������������йؼ���Ϊk�Ľ��Ĳ�Σ��������Ϊ1����
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

bool found = false;	//�����жϽ���Ƿ��ҵ�

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//�����
	BSTNode<T1, T2>* f;		//��ʱ��Ŵ�ɾ������˫��

	BSTClass() :r(NULL), f(NULL) {}

	int SearchLevel(T1 k)		//���Ĵ��룬���ڲ�α���ʵ��
	{
		int level = 1;
		queue<BSTNode<T1, T2>*> qu;
		qu.push(r);
		while (!qu.empty())
		{
			BSTNode<T1, T2>* p = qu.front();
			int n = qu.size();
			for (int i = 0; i < n; i++)
			{
				p = qu.front();
				if (p->key == k)
				{
					found = true;
					return level;
				}
				qu.pop();
				if (p->lchild != NULL)
					qu.push(p->lchild);
				if (p->rchild != NULL)
					qu.push(p->rchild);
			}
			level++;
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
	int level = example.SearchLevel(k);
	if (found)
	{
		cout << "�ؼ���Ϊ" << k << "�Ľ�����ڲ��Ϊ" << level << endl;
	}
	else cout << "û���ҵ��ؼ���Ϊ" << k << "�Ľ��" << endl;

	return 0;
}