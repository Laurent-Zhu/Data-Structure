//假设一个无向图采用邻接表G作为存储结构，设计一个算法判断其中是否存在经过顶点v的简单回路（环）
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
	vector<int> cycpath;

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

	bool HasCycle(AdjGraph& G, int v)
	{
		ClearTag();
		bool has = false;
		vector<int> path;
		
		HasCycle1(G, v, v, -1, has, path, cycpath);
		return has;
	}
	void HasCycle1(AdjGraph& G, int v, int u, int d, bool& has, vector<int> path, vector<int>& cycpath)		//核心代码
	{
		path.push_back(u);
		visited[u] = 1;
		ArcNode* p = adjlist[u].firstarc;
		d++;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (visited[w] == 0)
				HasCycle1(G, v, w, d, has, path, cycpath);
			else if (w == v && d > 1)
			{
				path.push_back(w);
				has = true;
				cycpath = path;
				return;
			}
			p = p->nextarc;
		}
	}

};


int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,1,INF,1,INF},{1,0,1,INF,INF},{INF,1,0,1,1},{1,INF,1,0,INF},{INF,INF,1,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "图的邻接表:\n"; G.DispAdjGraph();
	cout << "\n";
	cout << "输入你要判断的顶点v：";
	int v;
	cin >> v;
	if (G.HasCycle(G, v))
	{
		printf("存在经过顶点%d的简单回路：", v);
		for (int i = 0; i < G.cycpath.size(); i++)
		{
			cout << G.cycpath[i] << " ";
		}
		cout << endl;
	}
	else
		printf("不存在经过顶点%d的简单回路\n", v);

	return 0;
}