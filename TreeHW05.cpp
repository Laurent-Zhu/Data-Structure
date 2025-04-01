//假设二叉树中的每个结点值为单个字符，采用二叉树存储结构存储。假设二叉树bt中可能有多个值为x的结点，每个这样的结点对应一个层次，设计一个算法求其中的最小层次。
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
	int level;
	BTree() :root(NULL), level(0) {} //构造函数

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

	void FindMinLev(char ch)		//核心代码，采用层次遍历来实现
	{
		if(root -> value == ch)
		{
			cout << "结点值为" << ch << "的结点的最小层次为：0" <<  endl;
			return;
		}
		queue<BTNode*> qu;
		qu.push(root);

		while (!qu.empty())
		{
			BTNode* p = qu.front();
			int n = qu.size();
			for (int i = 0; i < n; i++)
			{
				p = qu.front();
				if (p->value == ch)
					break;
				qu.pop();
				if (p->lchild != NULL)
					qu.push(p->lchild);
				if (p->rchild != NULL)
					qu.push(p->rchild);
			}
			if (p->value == ch)
				break;
			level++;
		}

		cout << "结点值为" << ch << "的结点的最小层次为：" << level << endl;
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	cout << "输入想要查找的结点的值：";
	char ch;
	cin >> ch;
	bt.FindMinLev(ch);
	
	return 0;
}