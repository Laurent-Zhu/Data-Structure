//����һ����ȨͼG�����ڽӾ���洢�����һ���㷨���õҿ�˹�����㷨�󶥵�s������t�����·�����ȣ����趥s��t����G�еĶ��㣩��
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

struct QNode	//����Ԫ������
{
	int v;
	int dis;

	QNode() {}
	QNode(int v, int dis)
	{
		this->v = v;
		this->dis = dis;
	}
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

	void BFS(AdjGraph& G, int v)
	{
		ClearTag();
		BFS1(G, v);
	}
	void BFS1(AdjGraph& G, int v)	//**��ͨͼ**�Ĺ�����ȱ�������ʼ��Ϊv��������ȱ������϶��е�������ʹ�ö�����ʵ��
	{
		queue<int> qu;
		cout << v << " ";
		visited[v] = 1;
		qu.push(v);
		while (!qu.empty())
		{
			int u = qu.front();
			qu.pop();
			ArcNode* p = G.adjlist[u].firstarc;
			while (p != NULL)
			{
				if (visited[p->adjvex] == 0)
				{
					cout << p->adjvex << " ";
					qu.push(p->adjvex);
					visited[p->adjvex] = 1;
				}
				p = p->nextarc;
			}
		}
	}
	void BFSA(AdjGraph& G)	//**����ͨͼ**�Ĺ�����ȱ���
	{
		ClearTag();
		for (int i = 0; i < G.n; i++)	//��˳����ÿһ�����Ϊ��ʼ�㣬��û�з��ʹ��������BFS
		{
			if (visited[i] == 0)
				BFS1(G, i);
		}
	}
	void Solution(int i)
	{
		ClearTag();
		queue<QNode> qu;
		vector<QNode> vex;
		visited[i] = 1;
		qu.push(QNode(i, 0));
		vex.push_back(QNode(i, 0));
		while (!qu.empty())
		{
			QNode e = qu.front();
			qu.pop();
			ArcNode* p = adjlist[e.v].firstarc;
			while (p != NULL)
			{
				int w = p->adjvex;
				if (visited[w] == 0)
				{
					visited[w] = 1;
					qu.push(QNode(w, e.dis + 1));
					vex.push_back(QNode(w, e.dis + 1));
				}
				p = p->nextarc;
			}
		}
		int maxdis = vex[vex.size() - 1].dis;
		printf("���Զ���%dΪ�����������·���У���ĳ���Ϊ%d���յ㶥���У�", i, maxdis);
		for (int k = vex.size() - 1; vex[k].dis == maxdis; k--)
		{
			cout << vex[k].v << " ";
		}
		cout << endl;

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
	cout << "���붥��v��";
	int v;
	cin >> v;
	G.Solution(v);

	return 0;
}