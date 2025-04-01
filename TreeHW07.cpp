//����������е�ÿ�����ֵΪ�����ַ������ö������洢�ṹ�洢�����һ���㷨������������������������bt��ֵΪx�Ľ����������ֵΪx�Ľ��ֵΨһ�ġ�
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
	BTree() :root(NULL), temp(NULL) {}//���캯��
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

	//����Ϊ���Ĵ���
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
			cout << "û���ҵ�ֵΪ" << ch << "�Ľ��" << endl;
			return;
		}
		if (temp->lchild == NULL && temp->rchild == NULL)
		{
			cout << "�ý����Ҷ�ӽ�㣬û������" << endl;
			return;
		}
		cout << "���ֵΪ" << ch << "�������У�";
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
	cout << "����һ����������ʹ���ַ�����ʾ�������磺A(B(D(,G)),C(E,F))����";
	cin >> str;
	BTree bt;
	bt.CreateBTree(str);
	cout << "������Ҫ���ҵĽ���ֵ��";
	char ch;
	cin >> ch;
	bt.Descendent(ch);

	return 0;
}