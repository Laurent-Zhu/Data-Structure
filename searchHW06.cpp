//设计一个算法，求一棵非空整数二叉排序树中关键字为k的结点的层次（根结点层次为1）。
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

bool found = false;	//用于判断结点是否找到

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//根结点
	BSTNode<T1, T2>* f;		//临时存放待删除结点的双亲

	BSTClass() :r(NULL), f(NULL) {}

	int SearchLevel(T1 k)		//核心代码，基于层次遍历实现
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
	int k;
	cout << "输入你要查找的结点的关键字k：";
	cin >> k;
	int level = example.SearchLevel(k);
	if (found)
	{
		cout << "关键字为" << k << "的结点所在层次为" << level << endl;
	}
	else cout << "没有找到关键字为" << k << "的结点" << endl;

	return 0;
}