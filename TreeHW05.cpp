//����������е�ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢�����������bt�п����ж��ֵΪx�Ľ�㣬ÿ�������Ľ���Ӧһ����Σ����һ���㷨�����е���С��Ρ�
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
	BTree() :root(NULL), level(0) {} //���캯��

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

	void FindMinLev(char ch)		//���Ĵ��룬���ò�α�����ʵ��
	{
		if(root -> value == ch)
		{
			cout << "���ֵΪ" << ch << "�Ľ�����С���Ϊ��0" <<  endl;
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

		cout << "���ֵΪ" << ch << "�Ľ�����С���Ϊ��" << level << endl;
	}
};

int main()
{
	string str;
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	cout << "������Ҫ���ҵĽ���ֵ��";
	char ch;
	cin >> ch;
	bt.FindMinLev(ch);
	
	return 0;
}