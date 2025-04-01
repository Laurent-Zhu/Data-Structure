//假设二叉树中的每个结点值为单个字符，采用二叉树存储结构存储。设计一个算法，判断一棵二叉树bt是否为完全二叉树。
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
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
	BTree() :root(NULL) {}//构造函数
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

	bool Is_Complete()		//核心代码，采用层次遍历实现，判断找到第一个有孩子为空的结点后，后面还是否存在有孩子不为空的结点
	{
		queue<BTNode*> qu;
		bool found = false;	//用来标识是否找到第一个有孩子为空的结点
		if (root != NULL)
			qu.push(root);
		while (!qu.empty())
		{
			BTNode* p = qu.front();
			int n = qu.size();
			for (int i = 0; i < n; i++)
			{
				p = qu.front();
				qu.pop();
				if (p->rchild == NULL || p->lchild == NULL)
					found = true;

				if (p->lchild != NULL && !found)
					qu.push(p->lchild);
				else if (p->lchild != NULL && found)
					return false;
				if (p->rchild != NULL && !found)
					qu.push(p->rchild);
				else if (p->rchild != NULL && found)
					return false;
			}
		}
		return true;
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	if (bt.Is_Complete())
		cout << "该二叉树是完全二叉树" << endl;
	else
		cout << "该二叉树不是完全二叉树" << endl;
	
	return 0;
}