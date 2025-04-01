//AVL��
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<typename T1, typename T2>
struct AVLNode
{
	T1 key;
	T2 data;
	int ht;		//��ʾ��ǰ���������߶�
	AVLNode* lchild;
	AVLNode* rchild;

	AVLNode(T1 k, T2 d):lchild(NULL),rchild(NULL)
	{
		ht=1��
		key = k;
		data = d;
	}
};

template<typename T1, typename T2>
class AVLTree
{
	AVLNode* r;
public:
	AVLTree():r(NULL){}

	int getht(AVLNode* p)	//���ؽ��p�������߶�
	{
		if (p == NULL)
			return 0;
		return p->ht;
	}



};

