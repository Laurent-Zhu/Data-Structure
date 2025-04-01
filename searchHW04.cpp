//设计一个算法，求在一棵整数二叉排序树中成功找到关键字为k的结点的查找序列（查找路径）。
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<int> path;		//全局变量，用来储存查找序列

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

	BSTClass() :r(NULL), f(NULL) {}		//构造函数

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
			{
				path.push_back(p->key);		//增加部分，核心代码
				return p;
			}
			else if (p->key > k)
			{
				path.push_back(p->key);
				p = p->lchild;
			}
			else if (p->key < k)
			{
				path.push_back(p->key);
				p = p->rchild;
			}
		}
		return NULL;	//查找失败
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

	cout << "输入要查找的关键字（整数）：";
	int k;
	cin >> k;
	BSTNode<int, char>* p = example.SearchBST(k);
	if (p != NULL)
	{
		cout << "找到：" << "[" << p->key << "→" << p->data << "]" << endl;
		cout << "查找序列为：";
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		cout << endl;
	}
	else cout << "未找到关键字" << k << "对应的元素" << endl;

	return 0;
}