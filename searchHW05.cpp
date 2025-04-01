//设计一个算法，输出一棵整数二叉排序树中前m（0<m<=二叉排序树中结点的个数）小的结点序列。
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<int> min_m_nodes;

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

	BSTClass() :r(NULL), f(NULL) {}

	void Get_Min_m(int m)
	{
		Get_Min_m_1(r, m);
	}
	void Get_Min_m_1(BSTNode<T1, T2>* p, int m)	//核心代码，基于二叉树的中序遍历，得到递增序列前m项
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
};

int main()
{
	vector<int> keys;
	vector<char> datas;
	BSTClass<int, char> example;

	cout << "你要输入的数据个数：";
	int n;
	cin >> n;
	cout << "输入" << n << "个键（整数）：";
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		keys.push_back(k);
	}
	cout << "输入" << n << "个字符：";
	for (int i = 0; i < n; i++)
	{
		char d;
		cin >> d;
		datas.push_back(d);
	}
	example.CreateBST(keys, datas);

	int m;
	cout << "输入待查找的前m小的结点数m：";
	cin >> m;
	example.Get_Min_m(m);
	cout << "前" << m << "小的结点序列：";
	for (int i = 0; i < m; i++)
		cout << min_m_nodes[i] << " ";
	cout << endl;

	return 0;
}