//假设一个带权图G采用邻接矩阵存储，设计一个算法采用狄克斯特拉算法求顶点s到顶点t的最短路径长度（假设顶s和t都是G中的顶点）。
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#define MAXV 20		//最大结点数量
const int INF = 0x3f3f3f3f;
using namespace std;

struct ArcNode		//边结点类型
{
	int adjvex;		//邻接点的数值（索引）
	int weight;
	ArcNode* nextarc;
};

struct HNode		//头结点类型
{
	string info;		//包含的信息
	ArcNode* firstarc;
};

struct QNode	//队列元素类型
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

class AdjGraph		//用邻接表储存图
{
public:
	HNode adjlist[MAXV];
	int n, e;
	int visited[MAXV];		//用于标识对应索引的结点是否访问过，没有访问为0，访问过为1

	AdjGraph()		//构造函数
	{
		for (int i = 0; i < MAXV; i++)
		{
			adjlist[i].firstarc = NULL;
			visited[i] = 0;
		}
	}

	~AdjGraph()		//析构函数
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

	void CreateAdjGraph(int a[][MAXV], int n, int e)		//创建图
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

	void DispAdjGraph()		//打印图
	{
		cout << "(邻接点索引，该边权值)" << endl;
		ArcNode* p;
		for (int i = 0; i < n; i++)
		{
			printf(" [%d]", i);
			p = adjlist[i].firstarc;
			if (p != NULL)
				cout << " → ";
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
	void BFS1(AdjGraph& G, int v)	//**连通图**的广度优先遍历，起始点为v，广度优先遍历符合队列的特征，使用队列来实现
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
	void BFSA(AdjGraph& G)	//**非连通图**的广度优先遍历
	{
		ClearTag();
		for (int i = 0; i < G.n; i++)	//按顺序以每一个结点为起始点，若没有访问过，则进行BFS
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
		printf("在以顶点%d为起点的所有最短路径中，最长的长度为%d，终点顶点有：", i, maxdis);
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
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	cout << "\n";
	cout << "输入顶点v：";
	int v;
	cin >> v;
	G.Solution(v);

	return 0;
}