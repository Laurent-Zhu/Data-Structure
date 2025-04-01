//假设二叉树中的每个结点值为单个字符，采用二叉树存储结构存储，每个结点有一个双亲指针Parent，初始为空。设计一个算法，将这样的二叉树中所有结点的parent指针都设置为正确的双亲。
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct BTNode {
	char value;
	BTNode* lchild;
	BTNode* rchild;
	BTNode* parent;
	BTNode() :lchild(NULL), rchild(NULL), parent(NULL) {}
	BTNode(char ch) :value(ch), lchild(NULL), rchild(NULL), parent(NULL) {}
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

	void FindParent()
	{
		FindParent1(root);
	}
	void FindParent1(BTNode* b)		//核心代码
	{
		if (b != NULL)
		{
			if (b->lchild != NULL)
				b->lchild->parent = b;
			if (b->rchild != NULL)
				b->rchild->parent = b;
			FindParent1(b->lchild);
			FindParent1(b->rchild);
		}
		else return;
	}

	void PrintParent(char ch)		
	{
		PrintParent1(root, ch);
	}
	void PrintParent1(BTNode* b, char ch)		//验证
	{
		if (b != NULL)
		{
			if (b->value == ch)
				cout << "该结点的双亲结点值为：" << b->parent->value << endl;
			PrintParent1(b->lchild, ch);
			PrintParent1(b->rchild, ch);
		}
		else return;
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.FindParent();
	char ch;
	cout << "输入要查找的结点值：";
	cin >> ch;
	bt.PrintParent(ch);

	return 0;
}