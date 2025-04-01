//����������
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

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//�����
	BSTNode<T1, T2>* f;		//��ʱ��Ŵ�ɾ������˫��

	BSTClass():r(NULL),f(NULL){}

	void DispBST()
	{
		DispBST1(r);
	}
	void DispBST1(BSTNode<T1, T2>* p)	//�������
	{
		if (p != NULL)
		{
			DispBST1(p->lchild);
			cout << "[" << p->key << "��" << p->data << "] ";
			DispBST1(p->rchild);
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

	BSTNode<T1, T2>* SearchBST(T1 k)	//�����������Ĳ���
	{
		BSTNode<T1, T2>* p = r;
		while (p)
		{
			if (p->key == k)
				return p;
			else if (p->key > k)
				p = p->lchild;
			else if (p->key < k)
				p = p->rchild;
		}
		return NULL;	//����ʧ��
	}

	bool DeleteBST(T1 k)
	{
		f = NULL;
		return _DeleteBST(k, r, -1);
	}
	bool _DeleteBST(T1 k, BSTNode<T1, T2>* p, int flag)		//flag������ʶpָ��Ľ������˫�׽��f�����ӻ����Һ��ӣ�-1��ʾû��˫�ף�0��ʾ�����ӣ�1��ʾ���Һ���
	{														//�÷�������Ѱ�Ҵ�ɾ����㣬�ҵ������DeleteNode
		if (p == NULL)
			return false;
		if (k == p->key)
			return DeleteNode(p, f, flag);
		if (k < p->key)
		{
			f = p;
			return _DeleteBST(k, p->lchild, 0);
		}
		else
		{
			f = p;
			return _DeleteBST(k, p->rchild, 1);
		}
	}
	bool DeleteNode(BSTNode<T1, T2>* p, BSTNode<T1, T2>* f, int flag)	//ɾ����㣬��Ҫ�������������
	{
		if (p->rchild == NULL)
		{
			if (flag == -1)
				r = p->lchild;
			else if (flag == 0)
				f->lchild = p->lchild;
			else
				f->rchild = p->lchild;
		}
		else if (p->lchild == NULL)
		{
			if (flag == -1)
				r = p->rchild;
			else if (flag == 0)
				f->lchild = p->rchild;
			else
				f->rchild = p->rchild;
		}
		else	//��ɾ������Һ��Ӷ���Ϊ��ʱ���ҵ���������������㣬�����������ɾ����㣨ֱ����ֵ�����
		{
			BSTNode<T1, T2>* f1 = p;
			BSTNode<T1, T2>* q = p->lchild;
			if (q->rchild == NULL)
			{
				p->key = q->key;
				p->data = q->data;
				p->lchild = q->lchild;
				delete q;
			}
			else
			{
				while (q->rchild != NULL)
				{
					f1 = q;
					q = q->rchild;
				}
				p->key = q->key;
				p->data = q->data;
				f1->rchild = q->lchild;
				delete q;
			}
		}
		return true;
	}
};

int main()
{
	vector<int> keys;
	vector<char> datas;
	BSTClass<int, char> example;
	cout << "����6��������������";
	for (int i = 0; i < 6; i++)
	{
		int k;
		cin >> k;
		keys.push_back(k);
	}
	cout << "����6���ַ���";
	for (int i = 0; i < 6; i++)
	{
		char d;
		cin >> d;
		datas.push_back(d);
	}
	example.CreateBST(keys, datas);
	cout << "չʾ������������";
	example.DispBST();
	cout << endl;
	cout << "����Ҫ���ҵĹؼ��֣���������";
	int k;
	cin >> k;
	BSTNode<int, char>* p = example.SearchBST(k);
	if(p != NULL)
	{
		cout << "�ҵ���" << "[" << p->key << "��" << p->data << "]" << endl;
	}
	cout << "������Ҫɾ����ֵ�Ĺؼ��֣���������";
	cin >> k;
	if (example.DeleteBST(k))
	{
		cout << "ɾ����Ķ�����������";
		example.DispBST();
	}
	else
		cout << "û���ҵ���Ӧ�Ĺؼ��ֵ�ֵ" << endl;


	return 0;
}