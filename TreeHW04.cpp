//����������е�ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢��ÿ�������һ��˫��ָ��Parent����ʼΪ�ա����һ���㷨���������Ķ����������н���parentָ�붼����Ϊ��ȷ��˫�ס�
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

	void FindParent()
	{
		FindParent1(root);
	}
	void FindParent1(BTNode* b)		//���Ĵ���
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
	void PrintParent1(BTNode* b, char ch)		//��֤
	{
		if (b != NULL)
		{
			if (b->value == ch)
				cout << "�ý���˫�׽��ֵΪ��" << b->parent->value << endl;
			PrintParent1(b->lchild, ch);
			PrintParent1(b->rchild, ch);
		}
		else return;
	}
};

int main()
{
	string str;
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.FindParent();
	char ch;
	cout << "����Ҫ���ҵĽ��ֵ��";
	cin >> ch;
	bt.PrintParent(ch);

	return 0;
}