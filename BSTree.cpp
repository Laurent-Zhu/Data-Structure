//二叉排序树
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<typename T1, typename T2>
struct BSTNode		//二叉排序树结点类型
{
	T1 key;		//键
	T2 data;	//值
	BSTNode* lchild;	//左孩子
	BSTNode* rchild;	//右孩子

	BSTNode(T1 k, T2 d)		//构造函数
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
	BSTNode<T1, T2>* r;		//根结点
	BSTNode<T1, T2>* f;		//临时存放待删除结点的双亲

	BSTClass():r(NULL),f(NULL){}

	void DispBST()
	{
		DispBST1(r);
	}
	void DispBST1(BSTNode<T1, T2>* p)	//中序遍历
	{
		if (p != NULL)
		{
			DispBST1(p->lchild);
			cout << "[" << p->key << "→" << p->data << "] ";
			DispBST1(p->rchild);
		}
		return;
	}

	void InsertBST(T1 k, T2 d)
	{
		r = _InsertBST(r, k, d);
	}
	BSTNode<T1, T2>* _InsertBST(BSTNode<T1, T2>* p, T1 k, T2 d)	//插入结点
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

	void CreateBST(vector<T1>& KEY, vector<T2>& DATA)	//创建二叉排序树
	{
		r = new BSTNode<T1, T2>(KEY[0], DATA[0]);
		for (int i = 0; i < KEY.size(); i++)		//每添加一个结点调用一次插入函数
		{
			InsertBST(KEY[i], DATA[i]);
		}
	}

	BSTNode<T1, T2>* SearchBST(T1 k)	//二叉排序树的查找
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
		return NULL;	//查找失败
	}

	bool DeleteBST(T1 k)
	{
		f = NULL;
		return _DeleteBST(k, r, -1);
	}
	bool _DeleteBST(T1 k, BSTNode<T1, T2>* p, int flag)		//flag用来标识p指向的结点是其双亲结点f的左孩子还是右孩子，-1表示没有双亲，0表示是左孩子，1表示是右孩子
	{														//该方法用于寻找待删除结点，找到后调用DeleteNode
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
	bool DeleteNode(BSTNode<T1, T2>* p, BSTNode<T1, T2>* f, int flag)	//删除结点，需要分三种情况讨论
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
		else	//待删结点左右孩子都不为空时，找到其左子树的最大结点，用它来替代待删除结点（直接用值替代）
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
	cout << "输入6个键（整数）：";
	for (int i = 0; i < 6; i++)
	{
		int k;
		cin >> k;
		keys.push_back(k);
	}
	cout << "输入6个字符：";
	for (int i = 0; i < 6; i++)
	{
		char d;
		cin >> d;
		datas.push_back(d);
	}
	example.CreateBST(keys, datas);
	cout << "展示二叉排序树：";
	example.DispBST();
	cout << endl;
	cout << "输入要查找的关键字（整数）：";
	int k;
	cin >> k;
	BSTNode<int, char>* p = example.SearchBST(k);
	if(p != NULL)
	{
		cout << "找到：" << "[" << p->key << "→" << p->data << "]" << endl;
	}
	cout << "输入想要删除的值的关键字（整数）：";
	cin >> k;
	if (example.DeleteBST(k))
	{
		cout << "删除后的二叉排序树：";
		example.DispBST();
	}
	else
		cout << "没有找到相应的关键字的值" << endl;


	return 0;
}