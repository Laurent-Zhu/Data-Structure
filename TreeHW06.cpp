//����������е�ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢�����һ���㷨������������������������bt�Ŀ�ȡ�
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define MAX_LEVEL 50
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
	vector<int> width;
	BTree() :root(NULL) 
	{
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			width.push_back(0);
		}
	}//���캯��
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

	void CountWidth()
	{
		int max = 0;
		CountWidth1(root, 0, max);
		cout << "�ö������Ŀ��Ϊ��" << max << endl;
	}
	void CountWidth1(BTNode* b, int k, int& max)	//���Ĵ���
	{
		if (b == NULL)
			return;
		width[k]++;
		max = max > width[k] ? max : width[k];
		CountWidth1(b->lchild, k + 1, max);
		CountWidth1(b->rchild, k + 1, max);
	}
};

int main()
{
	string str;
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	bt.CountWidth();

	return 0;
}