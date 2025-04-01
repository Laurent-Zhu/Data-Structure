//������������ö������洢�ṹ�����һ���㷨�ж�һ�ö�����bt�Ƿ�Գƣ���ν�Գ�ָ�����������Ľṹ�ǶԳƵġ�
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

	bool is_Symmetrical0()
	{
		if (root->lchild == NULL && root->rchild == NULL)
			return true;
		return is_Symmetrical(root->lchild, root->rchild);
	}
	bool is_Symmetrical(BTNode* left, BTNode* right)		//���Ĵ���
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
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bool ans = bt.is_Symmetrical0();
	if (ans)
		cout << "�ö������Գ�" << endl;
	else
		cout << "�ö��������Գ�" << endl;

	return 0;
}