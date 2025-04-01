//假设二叉树中的每个结点值为单个字符，采用二叉树存储结构存储。设计一个算法，采用先序遍历方法求二叉树bt中值为x的结点的子孙，假设值为x的结点值唯一的。
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
	BTNode* temp;
	BTree() :root(NULL), temp(NULL) {}//构造函数
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

	//以下为核心代码
	void LDR(BTNode* b, char ch)
	{
		if (b != NULL)
		{
			if (b->value == ch)
			{
				temp = b;
				return;
			}
			LDR(b->lchild, ch);
			LDR(b->rchild, ch);
		}
	}
	void Descendent(char ch)
	{
		LDR(root, ch);
		if (temp == NULL)
		{
			cout << "没有找到值为" << ch << "的结点" << endl;
			return;
		}
		if (temp->lchild == NULL && temp->rchild == NULL)
		{
			cout << "该结点是叶子结点，没有子孙" << endl;
			return;
		}
		cout << "结点值为" << ch << "的子孙有：";
		Descendent1(temp, ch);
	}
	void Descendent1(BTNode* b,char& ch)
	{
		if (b != NULL)
		{
			if(b->value!=ch)
				cout << b->value << " ";
			Descendent1(b->lchild, ch);
			Descendent1(b->rchild, ch);
		}
	}
};

int main()
{
	string str;
	cout << "输入一个二叉树【使用字符串表示法，例如：A(B(D(,G)),C(E,F))】：";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	cout << "输入你要查找的结点的值：";
	char ch;
	cin >> ch;
	bt.Descendent(ch);

	return 0;
}