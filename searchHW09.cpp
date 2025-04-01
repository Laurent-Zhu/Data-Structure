//在哈希表（除留余数法+拉链法）HashTable类中添加remove（k）算法用于删除关键字为k的元素。
#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int d) :data(d) { next = NULL;}
};

class HashTable
{
public:
	Node* HTable[100];	//存放头指针的数组
	int n;	//哈希表中元素个数
	int m;	//哈希表长度

	HashTable(int m)
	{
		this->m = m;
		for (int i = 0; i < m; i++)
		{
			HTable[i] = NULL;
		}
		n = 0;
	}
	
	void Display()
	{
		for (int i = 0; i < m; i++)
		{
			Node* p = HTable[i];
			if (p == NULL)
			{
				cout << "NULL" << endl;
				continue;
			}
			while (p != NULL)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	void CreateHT(vector<int> input)	//使用除留余数法+拉链法创建哈希表
	{
		for (int i = 0; i < input.size(); i++)
		{
			int pos = input[i] % m;	//取余
			Node* p = new Node(input[i]);
			p->next = HTable[pos];		//插入
			HTable[pos] = p;
			n++;
		}
	}
	void remove(int k)		//核心代码
	{
		int pos = k % m;
		Node* p = HTable[pos];
		Node* pre = p;
		if (p->data == k)
		{
			HTable[pos] = p->next;
			return;
		}
		while (p->data != k)
		{
			pre = p;
			p = p->next;
			if (p == NULL)
				break;
		}
		if (p == NULL)
		{
			cout << "没有找到相应的结点" << endl;
			return;
		}
		else
		{
			pre->next = p->next;
			delete p;
		}
	}
};

int main()
{
	int m;
	cout << "哈希表长度：";
	cin >> m;
	HashTable HT(m);
	vector<int> input;
	cout << "你要输入的元素个数：";
	int n;
	cin >> n;
	cout << "请输入" << n << "个元素：";
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	HT.CreateHT(input);
	cout << "哈希表如下：" << endl;
	HT.Display();

	int k;
	cout << "输入你要删除的结点值：";
	cin >> k;
	HT.remove(k);
	cout << "删除结点" << k << "后的哈希表如下：" << endl;
	HT.Display();

	return 0;
}