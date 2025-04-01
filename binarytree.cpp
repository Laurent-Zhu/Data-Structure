//������
#include<iostream>
//#include<vector>
#include<string>
//#include<stack>
#include"btree.cpp"
using namespace std;
//struct BTNode
//{
//	char data;
//	BTNode* lchild;
//	BTNode* rchild;
//	BTNode():lchild(NULL),rchild(NULL){}
//	BTNode(char ch)
//	{
//		data = ch;
//		lchild = NULL;
//		rchild = NULL;
//	}
//};
//class BTree			//��������
//{
//	BTNode* r;			//�������ĸ����r
//public:
//	BTree()			//���캯��,����һ�ÿ���
//	{
//		r = NULL;
//	}
//	void CreateBTree(string str)//����������
//	{
//		stack<BTNode*> st;
//		BTNode* p;
//		bool flag;
//		int i = 0;
//
//		while (i < str.length())
//		{
//			switch (str[i])
//			{
//			case '(':
//				st.push(p);
//				flag = true;
//				break;
//			case ')':
//				st.pop();
//				break;
//			case ',':
//				flag = false;
//				break;
//			default:
//				p = new BTNode(str[i]);
//				if (r == NULL)
//					r = p;
//				else
//				{
//					if (flag && !st.empty())
//						st.top()->lchild = p;
//					else if (!st.empty())
//						st.top()->rchild = p;
//				}
//				break;
//			}
//			i++;
//		}
//	}
//	//**********************************************************************************************************
//	//*******************���ڶ������������������������ͺ����������ʵ�����¶��ֲ���***************************
//	//**********************************************************************************************************
//	void DispTree()//��ӡ������
//	{
//		DispTree1(r);
//	}
//	void DispTree1(BTNode* b)//�ݹ鷽��
//	{
//		if (b != NULL)
//		{
//			cout << b->data;
//			if (b->lchild || b->rchild)
//			{
//				cout << '(';
//				DispTree1(b->lchild);
//				if(b->rchild != NULL)
//					cout << ',';
//				DispTree1(b->rchild);
//				cout << ')';
//			}
//		}
//	}
//	void DispTree2(BTree& bt)//ʹ�÷ǵݹ鷽����ӡ�����������������
//	{
//		if (bt.r == NULL) return;
//		stack<BTNode*> st;//�õ���ջ��ջ�е�Ԫ���൱�ڻ�û�з��ʵĽ�㣬ջ�������ʾ����Ԫ��û�з��ʣ�ջ�ձ�ʾ����Ԫ�ؾ��ѷ��� 
//		st.push(bt.r);
//		BTNode* p;
//		while (!st.empty())//�˴�Ϊ���������DLR
//		{
//			p = st.top();
//			st.pop();
//			cout << p->data << " ";//���ȷ��ʸ��ڵ�
//			if (p->rchild != NULL)
//				st.push(p->rchild);//�Һ�����������Ȱ��Һ���ѹ��ջ�б��棬����ٴ���
//			if (p->lchild != NULL)
//				st.push(p->lchild);//���ӱ��Һ��Ӻ��ջ������ջ��Ԫ��ʱ���ȷ��ʵ�����
//		}
//	}
//	void DispTree3(BTree& bt)//ʹ�÷ǵݹ鷽����ӡ�����������������
//	{
//		if (bt.r == NULL) return;
//		stack<BTNode*> st;//�õ���ջ
//		BTNode* p = bt.r;
//		while (p != NULL || !st.empty())//�˴�Ϊ���������LDR
//		{
//			if (p != NULL) //һ·����
//			{
//				st.push(p);
//				p = p->lchild;
//			}
//			else
//			{
//				p = st.top();
//				st.pop();
//				cout << p->data << " ";//���ʸ����
//				p = p->rchild;//��ʼ����������
//			}
//		}
//	}
//	void DispTree4(BTree& bt)//ʹ�÷ǵݹ鷽����ӡ�������������������ֻ��Ҫ����������Ļ����ϣ���Ϊ�Ƚ�����ѹ��ջ�����Һ���ѹ��ջ��
//	{
//		if (bt.r == NULL) return;
//		vector<BTNode*> temp;//ʹ��һ����ʱ������������DRLΪ����˳��Ľ��
//		stack<BTNode*> st;//�õ���ջ
//		st.push(bt.r);
//		BTNode* p;
//		while (!st.empty())//�˴�Ϊ���������DLR
//		{
//			p = st.top();
//			st.pop();
//			temp.push_back(p);//���ȷ��ʸ��ڵ�
//			if (p->lchild != NULL)
//				st.push(p->lchild);//������������Ȱ�����ѹ��ջ�б��棬����ٴ���
//			if (p->rchild != NULL)
//				st.push(p->rchild);//�Һ��ӱ����Ӻ��ջ������ջ��Ԫ��ʱ���ȷ��ʵ��Һ���
//		}
//		reverse(temp.begin(), temp.end());//�������飬DRL��ΪLRD��������˺������
//		for (int i = 0; i < temp.size(); i++)
//		{
//			cout << temp[i]->data << " ";
//		}
//	}
//
//	int Height()//��������ĸ߶�
//	{
//		return Height1(r);
//	}
//	int Height1(BTNode* b)
//	{
//		if (b == NULL)
//			return 0;
//		else
//			return max(Height1(b->lchild), Height1(b->rchild)) + 1;//�൱�ں������
//	}
//
//	int count(BTree& bt)//��������Ľ�����
//	{
//		return count1(bt.r);
//	}
//	int count1(BTNode* b)
//	{
//		if (b == NULL)
//			return 0;
//		else
//			return count1(b->lchild) + count1(b->rchild) + 1;//�൱�ں������
//	}
//
//	void DispLeaf()//���Ҷ�ӽ��
//	{
//		DispLeaf1(r);
//	}
//	void DispLeaf1(BTNode* b)
//	{
//		if(b)
//		{
//			if (!b->lchild && !b->rchild)//��������������
//			{
//				cout << b->data << " ";
//				return;
//			}
//			DispLeaf1(b->lchild);
//			DispLeaf1(b->rchild);
//		}
//	}
//
//	void Exchange(BTree& bt)//������������������ʹ����������ͺ��������������ʹ���������
//	{
//		Exchange1(bt.r);
//	}
//	void Exchange1(BTNode* b)
//	{
//		if (b)
//		{
//			swap(b->lchild, b->rchild);//����ʹ���������
//			Exchange1(b->lchild);
//			Exchange1(b->rchild);
//		}
//		return;
//	}
//
//	int FindLevel(BTree& bt, char ch)//����ָ����ֵ������ڵĲ��
//	{
//		return FindLevel1(ch, bt.r, 1);
//	}
//	int FindLevel1(char ch, BTNode* b, int h)
//	{
//		if (!b)
//			return 0;
//		else if (b->data == ch)
//			return h;
//		else
//		{
//			int l = FindLevel1(ch, b->lchild, h + 1);
//			if (l != 0)
//				return l;
//			else
//				return FindLevel1(ch, b->rchild, h + 1);
//		}
//	}
//
//	int KCount(BTree& bt, int k)//�����k�������
//	{
//		int cnt = 0;
//		KCount1(bt.r, k, cnt, 1);
//		return cnt;
//	}
//	void KCount1(BTNode* b, int k, int& cnt, int h)
//	{
//		if (b == NULL)
//			return;
//		if (k == h)
//			cnt++;
//		if(h<k)
//		{
//			KCount1(b->lchild, k, cnt, h+1);
//			KCount1(b->rchild, k, cnt, h + 1);
//		}
//	}
//
//	void Ancestor(BTree& bt, char ch)//Ѱ��ָ����ֵ�Ľ�������
//	{
//		vector<char> anc;
//		Ancestor1(bt.r, ch, anc);
//		reverse(anc.begin(), anc.end());
//		for (int i = 0; i < anc.size(); i++)
//			cout << anc[i] << " ";
//	}
//	bool Ancestor1(BTNode* b, char ch, vector<char>& anc)
//	{
//		if (b == NULL)
//			return false;
//		if (b->lchild != NULL && b->lchild->data == ch)
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		if (b->rchild != NULL && b->rchild->data == ch)
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		if (Ancestor1(b->lchild, ch, anc) || Ancestor1(b->rchild, ch, anc))
//		{
//			anc.push_back(b->data);
//			return true;
//		}
//		return false;
//	}
//
//	void DestroyTree(BTNode* b)//���ٶ�����
//	{
//		if (b != NULL)
//		{
//			DestroyTree(b->lchild);
//			DestroyTree(b->rchild);
//			delete b;
//		}
//	}
//	~BTree()//��������
//	{
//		DestroyTree(r);
//		r = NULL;
//	}
//};

int main()
{
	BTree bt;
	string str = "A(B(D(,G)),C(E,F))";//�ַ�������ʽ��ʾ������
	bt.CreateBTree(str);
	cout << "ԭ���������ݹ鷨��������";
	bt.DispTree();
	cout << endl;
	cout << "ԭ���������ǵݹ鷨�����������򣩣�";
	bt.DispTree2(bt);
	cout << endl;
	cout << "ԭ���������ǵݹ鷨�����������򣩣�";
	bt.DispTree3(bt);
	cout << endl;
	cout << "ԭ���������ǵݹ鷨�����������򣩣�";
	bt.DispTree4(bt); 
	cout << endl;
	cout << "�������ĸ߶��ǣ�" << bt.Height() << endl;
	cout << "�������Ľ������ǣ�" << bt.count(bt) << endl;
	cout << "��������Ҷ�ӽ�����ֵΪ��";
	bt.DispLeaf();
	cout << endl;
	cout << "��������������";
	bt.Exchange(bt);
	bt.DispTree();
	cout << "��Ҫ���ҵĽ����ֵ��";
	char ch;
	cin >> ch;
	int level = bt.FindLevel(bt, ch);
	if (level)
		cout << "���ڲ��Ϊ��" << level << endl;
	else
		cout << "δ�ҵ���Ӧ��ֵ�Ľ��" << endl;
	cout << "��������Ҫ����Ĳ�Σ�";
	int k;
	cin >> k;
	cout << "��" << k << "��Ľ�����Ϊ��" << bt.KCount(bt, k) << endl;
	cout << "��Ҫ����ʲô��ֵ�Ľ������ȣ�";
	cin >> ch;
	cout << "��ֵΪ" << ch << "�����Ƚ�����ֵ�ֱ�Ϊ��";
	bt.Ancestor(bt, ch);

	return 0;
}