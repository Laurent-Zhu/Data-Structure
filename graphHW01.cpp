//����һ������ͼ�����ڽӱ�G�洢�����һ���㷨�󶥵�i����������ڽӵ㡣
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#define MAXV 20		//���������
const int INF = 0x3f3f3f3f;
using namespace std;

struct ArcNode		//�߽������
{
	int adjvex;		//�ڽӵ����ֵ��������
	int weight;
	ArcNode* nextarc;
};

struct HNode		//ͷ�������
{
	string info;		//��������Ϣ
	ArcNode* firstarc;
};

vector<int> PreAdjNodes;

class AdjGraph		//���ڽӱ���ͼ
{
public:
	HNode adjlist[MAXV];
	int n, e;
	int visited[MAXV];		//���ڱ�ʶ��Ӧ�����Ľ���Ƿ���ʹ���û�з���Ϊ0�����ʹ�Ϊ1

	AdjGraph()		//���캯��
	{
		for (int i = 0; i < MAXV; i++)
		{
			adjlist[i].firstarc = NULL;
			visited[i] = 0;
		}
	}

	~AdjGraph()		//��������
	{
		ArcNode* p, * pre;
		for (int i = 0; i < n; i++)
		{
			pre = adjlist[i].firstarc;
			if (pre != NULL)
			{
				p = pre->nextarc;
				while (p != NULL)
				{
					delete pre;
					pre = p;
					p = p->nextarc;
				}
				delete pre;
			}
		}
	}

	void CreateAdjGraph(int a[][MAXV], int n, int e)		//����ͼ
	{
		ArcNode* p;
		this->n = n;
		this->e = e;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (a[i][j] != 0 && a[i][j] != INF)
				{
					p = new ArcNode();
					p->adjvex = j;
					p->weight = a[i][j];
					p->nextarc = adjlist[i].firstarc;
					adjlist[i].firstarc = p;
				}
			}
		}
	}

	void DispAdjGraph()		//��ӡͼ
	{
		cout << "(�ڽӵ��������ñ�Ȩֵ)" << endl;
		ArcNode* p;
		for (int i = 0; i < n; i++)
		{
			printf(" [%d]", i);
			p = adjlist[i].firstarc;
			if (p != NULL)
				cout << " �� ";
			while (p != NULL)
			{
				printf("(%d,%d) ", p->adjvex, p->weight);
				p = p->nextarc;
			}
			printf("\n");
		}
	}

	void ClearTag()
	{
		for (int i = 0; i < MAXV; i++)
		{
			visited[i] = 0;
		}
	}

	void BFS(AdjGraph& G, int v, int i)
	{
		ClearTag();
		BFS1(G, v, i);
	}
	void BFS1(AdjGraph& G, int v, int i)	//���Ĵ��룬���ڹ�����ȱ�����ʵ��
	{
		queue<int> qu;
		visited[v] = 1;
		qu.push(v);
		while (!qu.empty())
		{
			int u = qu.front();
			qu.pop();
			ArcNode* p = G.adjlist[u].firstarc;
			while (p != NULL)
			{
				if (p->adjvex == i)		//�ؼ����
					PreAdjNodes.push_back(u);
				if (visited[p->adjvex] == 0)
				{
					qu.push(p->adjvex);
					visited[p->adjvex] = 1;
				}
				p = p->nextarc;
			}
		}
	}
};

int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout << "\n";
	cout << "����Ҫ���ҵĶ���i��";
	int i;
	cin >> i;
	G.BFS(G, 0, i);
	cout << "����" << i << "������ڽӵ��У�";
	for (int j = 0; j < PreAdjNodes.size(); j++)
	{
		cout << PreAdjNodes[j] << " ";
	}

	return 0;
}