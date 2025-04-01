//二叉树
#include<iostream>
//#include<vector>
#include<string>
//#include<stack>
#include"btree.cpp"
using namespace std;
//struct BTNode
//{
//	char data;
//	BTNode* lchild;
//	BTNode* rchild;
//	BTNode():lchild(NULL),rchild(NULL){}
//	BTNode(char ch)
//	{
//		data = ch;
//		lchild = NULL;
//		rchild = NULL;
//	}
//};
//class BTree			//二叉树类
//{
//	BTNode* r;			//二叉树的根结点r
//public:
//	BTree()			//构造函数,建立一棵空树
//	{
//		r = NULL;
//	}
//	void CreateBTree(string str)//创建二叉树
//	{
//		stack<BTNode*> st;
//		BTNode* p;
//		bool flag;
//		int i = 0;
//
//		while (i < str.length())
//		{
//			switch (str[i])
//			{
//			case '(':
//				st.push(p);
//				flag = true;
//				break;
//			case ')':
//				st.pop();
//				break;
//			case ',':
//				flag = false;
//				break;
//			default:
//				p = new BTNode(str[i]);
//				if (r == NULL)
//					r = p;
//				else
//				{
//					if (flag && !st.empty())
//						st.top()->lchild = p;
//					else if (!st.empty())
//						st.top()->rchild = p;
//				}
//				break;
//			}
//			i++;
//		}
//	}
//	//**********************************************************************************************************
//	//*******************基于二叉树的先序遍历，中序遍历和后序遍历可以实现以下多种操作***************************
//	//**********************************************************************************************************
//	void DispTree()//打印二叉树
//	{
//		DispTree1(r);
//	}
//	void DispTree1(BTNode* b)//递归方法
//	{
//		if (b != NULL)
//		{
//			cout << b->data;
//			if (b->lchild || b->rchild)
//			{
//				cout << '(';
//				DispTree1(b->lchild);
//				if(b->rchild != NULL)
//					cout << ',';
//				DispTree1(b->rchild);
//				cout << ')';
//			}
//		}
//	}
//	void DispTree2(BTree& bt)//使用非递归方法打印二叉树（先序遍历）
//	{
//		if (bt.r == NULL) return;
//		stack<BTNode*> st;//用到了栈，栈中的元素相当于还没有访问的结点，栈不空则表示还有元素没有访问，栈空表示所有元素均已访问 
//		st.push(bt.r);
//		BTNode* p;
//		while (!st.empty())//此处为先序遍历，DLR
//		{
//			p = st.top();
//			st.pop();
//			cout << p->data << " ";//首先访问根节点
//			if (p->rchild != NULL)
//				st.push(p->rchild);//右孩子最后处理，故先把右孩子压进栈中保存，最后再处理
//			if (p->lchild != NULL)
//				st.push(p->lchild);//左孩子比右孩子后进栈，访问栈顶元素时会先访问到左孩子
//		}
//	}
//	void DispTree3(BTree& bt)//使用非递归方法打印二叉树（中序遍历）
//	{
//		if (bt.r == NULL) return;
//		stack<BTNode*> st;//用到了栈
//		BTNode* p = bt.r;
//		while (p != NULL || !st.empty())//此处为中序遍历，LDR
//		{
//			if (p != NULL) //一路向左
//			{
//				st.push(p);
//				p = p->lchild;
//			}
//			else
//			{
//				p = st.top();
//				st.pop();
//				cout << p->data << " ";//访问根结点
//				p = p->rchild;//开始处理右子树
//			}
//		}
//	}
//	void DispTree4(BTree& bt)//使用非递归方法打印二叉树（后序遍历）（只需要在先序遍历的基础上，改为先将左孩子压入栈，后将右孩子压入栈）
//	{
//		if (bt.r == NULL) return;
//		vector<BTNode*> temp;//使用一个临时数组来储存以DRL为储存顺序的结点
//		stack<BTNode*> st;//用到了栈
//		st.push(bt.r);
//		BTNode* p;
//		while (!st.empty())//此处为先序遍历，DLR
//		{
//			p = st.top();
//			st.pop();
//			temp.push_back(p);//首先访问根节点
//			if (p->lchild != NULL)
//				st.push(p->lchild);//左孩子最后处理，故先把左孩子压进栈中保存，最后再处理
//			if (p->rchild != NULL)
//				st.push(p->rchild);//右孩子比左孩子后进栈，访问栈顶元素时会先访问到右孩子
//		}
//		reverse(temp.begin(), temp.end());//逆置数组，DRL变为LRD，即变成了后序遍历
//		for (int i = 0; i < temp.size(); i++)
//		{
//			cout << temp[i]->data << " ";
//		}
//	}
//
//	int Height()//求二叉树的高度
//	{
//		return Height1(r);
//	}
//	int Height1(BTNode* b)
//	{
//		if (b == NULL)
//			return 0;
//		else
//			return max(Height1(b->lchild), Height1(b->rchild)) + 1;//相当于后序遍历
//	}
//
//	int count(BTree& bt)//求二叉树的结点个数
//	{
//		return count1(bt.r);
//	}
//	int count1(BTNode* b)
//	{
//		if (b == NULL)
//			return 0;
//		else
//			return count1(b->lchild) + count1(b->rchild) + 1;//相当于后序遍历
//	}
//
//	void DispLeaf()//输出叶子结点
//	{
//		DispLeaf1(r);
//	}
//	void DispLeaf1(BTNode* b)
//	{
//		if(b)
//		{
//			if (!b->lchild && !b->rchild)//这里采用先序遍历
//			{
//				cout << b->data << " ";
//				return;
//			}
//			DispLeaf1(b->lchild);
//			DispLeaf1(b->rchild);
//		}
//	}
//
//	void Exchange(BTree& bt)//交换左右子树，可以使用先序遍历和后序遍历，但不能使用中序遍历
//	{
//		Exchange1(bt.r);
//	}
//	void Exchange1(BTNode* b)
//	{
//		if (b)
//		{
//			swap(b->lchild, b->rchild);//这里使用先序遍历
//			Exchange1(b->lchild);
//			Exchange1(b->rchild);
//		}
//		return;
//	}
//
//	int FindLevel(BTree& bt, char ch)//查找指定数值结点所在的层次
//	{
//		return FindLevel1(ch, bt.r, 1);
//	}
//	int FindLevel1(char ch, BTNode* b, int h)
//	{
//		if (!b)
//			return 0;
//		else if (b->data == ch)
//			return h;
//		else
//		{
//			int l = FindLevel1(ch, b->lchild, h + 1);
//			if (l != 0)
//				return l;
//			else
//				return FindLevel1(ch, b->rchild, h + 1);
//		}
//	}
//
//	int KCount(BTree& bt, int k)//计算第k层结点个数
//	{
//		int cnt = 0;
//		KCount1(bt.r, k, cnt, 1);
//		return cnt;
//	}
//	void KCount1(BTNode* b, int k, int& cnt, int h)
//	{
//		if (b == NULL)
//			return;
//		if (k == h)
//			cnt++;
//		if(h<k)
//		{
//			KCount1(b->lchild, k, cnt, h+1);
//			KCount1(b->rchild, k, cnt, h + 1);
//		}
//	}
//
//	void Ancestor(BTree& bt, char ch)//寻找指定数值的结点的祖先
//	{
//		vector<char> anc;
//		Ancestor1(bt.r, ch, anc);
//		reverse(anc.begin(), anc.end());
//		for (int i = 0; i < anc.size(); i++)
//			cout << anc[i] << " ";
//	}
//	bool Ancestor1(BTNode* b, char ch, vector<char>& anc)
//	{
//		if (b == NULL)
//			return false;
//		if (b->lchild != NULL && b->lchild->data == ch)
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		if (b->rchild != NULL && b->rchild->data == ch)
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		if (Ancestor1(b->lchild, ch, anc) || Ancestor1(b->rchild, ch, anc))
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		return false;
//	}
//
//	void DestroyTree(BTNode* b)//销毁二叉树
//	{
//		if (b != NULL)
//		{
//			DestroyTree(b->lchild);
//			DestroyTree(b->rchild);
//			delete b;
//		}
//	}
//	~BTree()//析构函数
//	{
//		DestroyTree(r);
//		r = NULL;
//	}
//};

int main()
{
	BTree bt;
	string str = "A(B(D(,G)),C(E,F))";//字符串的形式表示二叉树
	bt.CreateBTree(str);
	cout << "原二叉树（递归法遍历）：";
	bt.DispTree();
	cout << endl;
	cout << "原二叉树（非递归法遍历）（先序）：";
	bt.DispTree2(bt);
	cout << endl;
	cout << "原二叉树（非递归法遍历）（中序）：";
	bt.DispTree3(bt);
	cout << endl;
	cout << "原二叉树（非递归法遍历）（后序）：";
	bt.DispTree4(bt); 
	cout << endl;
	cout << "二叉树的高度是：" << bt.Height() << endl;
	cout << "二叉树的结点个数是：" << bt.count(bt) << endl;
	cout << "二叉树的叶子结点的数值为：";
	bt.DispLeaf();
	cout << endl;
	cout << "交换左右子树后：";
	bt.Exchange(bt);
	bt.DispTree();
	cout << "你要查找的结点数值：";
	char ch;
	cin >> ch;
	int level = bt.FindLevel(bt, ch);
	if (level)
		cout << "所在层次为：" << level << endl;
	else
		cout << "未找到对应数值的结点" << endl;
	cout << "请输入你要计算的层次：";
	int k;
	cin >> k;
	cout << "第" << k << "层的结点个数为：" << bt.KCount(bt, k) << endl;
	cout << "你要查找什么数值的结点的祖先：";
	cin >> ch;
	cout << "数值为" << ch << "的祖先结点的数值分别为：";
	bt.Ancestor(bt, ch);

	return 0;
}