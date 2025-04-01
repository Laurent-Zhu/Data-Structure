//�����������ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢�����һ���㷨�����ҵ���Ĵ������һ�ö�����bt�е�����Ҷ�ӽ�㡣
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
	BTree() :root(NULL) {}//���캯��
	void CreateBTree(string str)//����������
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
	void DispLeaf_RtoL1(BTNode* b)		//���Ĵ���
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
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.DispLeaf_RtoL();

	return 0;
}