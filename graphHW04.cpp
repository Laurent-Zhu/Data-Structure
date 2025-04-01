//��������ͼG�����ڽӱ�洢�����һ���㷨������ͨ�����ĸ�����
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

	
	void DFS1(AdjGraph& G, int v)	//**��ͨͼ**��������ȱ�������ʼ��Ϊv��������ȱ�������ջ����������ʹ��ջ��ݹ���ʵ��
	{
		visited[v] = 1;
		ArcNode* p = G.adjlist[v].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;		//��ǰ�����ڽӵ�����
			if (visited[w] == 0)		//�����ڽӵ�δ���ʣ��������
				DFS1(G, w);
			p = p->nextarc;
		}
	}
	void NumOfConnected(AdjGraph& G)	//**����ͨͼ**��������ȱ���
	{
		int n = 0;		//���ڼ���
		ClearTag();
		for (int i = 0; i < G.n; i++)	//��˳����ÿһ�����Ϊ��ʼ�㣬��û�з��ʹ��������DFS
		{
			if (visited[i] == 0)
			{
				n++;		//ÿ����һ����ͨ�����ı���������������һ
				DFS1(G, i);
			}
		}
		printf("��ͨ��������Ϊ��%d\n", n);
	}

};

int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,1,1,INF,INF},{1,0,INF,INF,INF},{1,INF,INF,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "ͼ���ڽӱ�����ͼ��:\n"; G.DispAdjGraph();
	cout << "\n";
	G.NumOfConnected(G);
	
	return 0;
}