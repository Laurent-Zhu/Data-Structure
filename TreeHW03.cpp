//假设二叉树采用二叉树存储结构，设计一个算法判断一棵二叉树bt是否对称，所谓对称指其左右子树的结构是对称的。
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

	bool is_Symmetrical0()
	{
		if (root->lchild == NULL && root->rchild == NULL)
			return true;
		return is_Symmetrical(root->lchild, root->rchild);
	}
	bool is_Symmetrical(BTNode* left, BTNode* right)		//核心代码
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL && right != NULL || left != NULL && right == NULL)
			return false;
		else if (left->value != right->value)
			return false;

		bool outside = is_Symmetrical(left->lchild, right->rchild);
		bool inside = is_Symmetrical(left->rchild, right->lchild);

		return outside && inside;
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bool ans = bt.is_Symmetrical0();
	if (ans)
		cout << "该二叉树对称" << endl;
	else
		cout << "该二叉树不对称" << endl;

	return 0;
}