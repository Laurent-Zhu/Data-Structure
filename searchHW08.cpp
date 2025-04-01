//设计一个算法，在整数二叉排序树中查找第一个值大于k的结点。
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

bool found = false;		//用于标记k是否有逆中序前驱结点，若无置假，若有置真

template<typename T1, typename T2>
class BSTClass
{
public:
	BSTNode<T1, T2>* r;		//根结点
	BSTNode<T1, T2>* f;		//临时存放待删除结点的双亲

	BSTClass() :r(NULL), f(NULL) {}

	BSTNode<T1, T2>* Find_Next(int k)	//先找到结点k，再找到k的右子树最左下角的结点
	{
		BSTNode<T1, T2>* p = NULL;
		BSTNode<T1, T2>* kptr = NULL;
		Find_k(r, kptr, k);
		
		p = kptr->rchild;
		while (p->lchild != NULL)
		{
			found = true;
			p = p->lchild;
		}
		return p;
	}
	void Find_k(BSTNode<T1, T2>* p, BSTNode<T1, T2>*& kptr, int k)	//利用中序遍历找到结点k
	{
		if (p != NULL)
		{
			Find_k(p->rchild, kptr, k);
			if (p->key == k)
			{
				kptr = p;
				return;
			}
			Find_k(p->lchild, kptr, k);
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
	BSTNode<int, char>* pre = example.Find_Next(k);
	if (pre != NULL)
	{
		cout << "第一个大于关键字为" << k << "的结点的关键字为：" << pre->key << endl;
	}
	else cout << "关键字为" << k << "的结点没有关键字大于它的结点" << endl;

	return 0;
}