//假设无向图G采用邻接表存储，设计一个算法求其连通分量的个数。
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

	
	void DFS1(AdjGraph& G, int v)	//**连通图**的深度优先遍历，起始点为v，深度优先遍历符合栈的特征，可使用栈或递归来实现
	{
		visited[v] = 1;
		ArcNode* p = G.adjlist[v].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;		//当前结点的邻接点索引
			if (visited[w] == 0)		//若该邻接点未访问，则访问它
				DFS1(G, w);
			p = p->nextarc;
		}
	}
	void NumOfConnected(AdjGraph& G)	//**非连通图**的深度优先遍历
	{
		int n = 0;		//用于计数
		ClearTag();
		for (int i = 0; i < G.n; i++)	//按顺序以每一个结点为起始点，若没有访问过，则进行DFS
		{
			if (visited[i] == 0)
			{
				n++;		//每进行一个连通分量的遍历，计数次数加一
				DFS1(G, i);
			}
		}
		printf("连通分量个数为：%d\n", n);
	}

};

int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,1,1,INF,INF},{1,0,INF,INF,INF},{1,INF,INF,INF,INF},{INF,INF,INF,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "图的邻接表（无向图）:\n"; G.DispAdjGraph();
	cout << "\n";
	G.NumOfConnected(G);
	
	return 0;
}