//假设二叉树中每个结点值为单个字符，采用二叉树存储结构存储。设计一个算法按从右到左的次序输出一棵二叉树bt中的所有叶子结点。
#include<iostream>
#include<vector>
#include<string>
#include<stack>
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

	void DispLeaf_RtoL()
	{
		DispLeaf_RtoL1(root);
	}
	void DispLeaf_RtoL1(BTNode* b)		//核心代码
	{
		if (b != NULL)
		{
			DispLeaf_RtoL1(b->rchild);
			if (b->rchild == NULL && b->lchild == NULL)
				cout << b->value << " ";
			DispLeaf_RtoL1(b->lchild);
		}
		return;
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.DispLeaf_RtoL();

	return 0;
}