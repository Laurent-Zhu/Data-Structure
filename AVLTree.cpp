//AVL树
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
	int ht;		//表示当前结点的子树高度
	AVLNode* lchild;
	AVLNode* rchild;

	AVLNode(T1 k, T2 d):lchild(NULL),rchild(NULL)
	{
		ht=1；
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

	int getht(AVLNode* p)	//返回结点p的子树高度
	{
		if (p == NULL)
			return 0;
		return p->ht;
	}



};

