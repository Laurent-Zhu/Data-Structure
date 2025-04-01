//假设二叉树中的每个结点值为单个字符，采用二叉树存储结构存储。设计一个算法，采用先序遍历方法求二叉树bt的宽度。
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define MAX_LEVEL 50
using namespace std;

struct BTNode {
	char value;
	BTNode* lchild;
	BTNode* rchild;
	BTNode() :lchild(NULL), rchild(NULL) {}
	BTNode(char ch) :value(ch), lchild(NULL), rchild(NULL) {}
};

class BTree
{
	BTNode* root;
public:
	vector<int> width;
	BTree() :root(NULL) 
	{
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			width.push_back(0);
		}
	}//构造函数
	void CreateBTree(string str)//创建二叉树
	{
		stack<BTNode*> st;
		BTNode* p;
		bool flag;
		int i = 0;

		while (i < str.length())
		{
			switch (str[i])
			{
			case '(':
				st.push(p);
				flag = true;
				break;
			case ')':
				st.pop();
				break;
			case ',':
				flag = false;
				break;
			default:
				p = new BTNode(str[i]);
				if (root == NULL)
					root = p;
				else
				{
					if (flag && !st.empty())
						st.top()->lchild = p;
					else if (!st.empty())
						st.top()->rchild = p;
				}
				break;
			}
			i++;
		}
	}

	void CountWidth()
	{
		int max = 0;
		CountWidth1(root, 0, max);
		cout << "该二叉树的宽度为：" << max << endl;
	}
	void CountWidth1(BTNode* b, int k, int& max)	//核心代码
	{
		if (b == NULL)
			return;
		width[k]++;
		max = max > width[k] ? max : width[k];
		CountWidth1(b->lchild, k + 1, max);
		CountWidth1(b->rchild, k + 1, max);
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.CountWidth();

	return 0;
}