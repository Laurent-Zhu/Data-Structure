//����������е�ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢�����һ���㷨���ж�һ�ö�����bt�Ƿ�Ϊ��ȫ��������
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

	bool Is_Complete()		//���Ĵ��룬���ò�α���ʵ�֣��ж��ҵ���һ���к���Ϊ�յĽ��󣬺��滹�Ƿ�����к��Ӳ�Ϊ�յĽ��
	{
		queue<BTNode*> qu;
		bool found = false;	//������ʶ�Ƿ��ҵ���һ���к���Ϊ�յĽ��
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
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	if (bt.Is_Complete())
		cout << "�ö���������ȫ������" << endl;
	else
		cout << "�ö�����������ȫ������" << endl;
	
	return 0;
}