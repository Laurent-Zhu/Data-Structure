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

	void DFS(AdjGraph& G, int v)
	{
		ClearTag();
		DFS1(G, v);
	}
	void DFS0(AdjGraph& G, int v)	//区别于DFS1，DFS0只遍历，不打印
	{
		visited[v] = 1;
		ArcNode* p = G.adjlist[v].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;		
			if (visited[w] == 0)		
				DFS0(G, w);
			p = p->nextarc;
		}
	}
	void DFS1(AdjGraph& G, int v)	//**连通图**的深度优先遍历，起始点为v，深度优先遍历符合栈的特征，可使用栈或递归来实现
	{
		cout << v << " ";
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
	void DFSA(AdjGraph& G)	//**非连通图**的深度优先遍历
	{
		ClearTag();
		for (int i = 0; i < G.n; i++)	//按顺序以每一个结点为起始点，若没有访问过，则进行DFS
		{
			if (visited[i] == 0)
				DFS1(G, i);
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
				if(visited[p->adjvex] == 0)
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

	bool IsConnected(AdjGraph& G)	//判断无向图是否连通
	{
		ClearTag();
		DFS0(G, 0);		//先从结点0开始进行一次DFS
		for (int i = 0; i < G.n; i++)
		{
			if (visited[i] == 0)	//如果发现有没访问过的结点，说明该无向图不连通
				return false;
		}
		return true;
	}
	
	bool HasPath(AdjGraph& G, int u, int v)		//基于深度优先遍历，查找是否存在从u到v的简单路径
	{
		ClearTag();
		return HasPath1(G, u, v);
	}
	bool HasPath1(AdjGraph& G, int u, int v)
	{
		visited[u] = 1;
		ArcNode* p = G.adjlist[u].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;
			if (w == v)
				return true;
			else if (visited[w] == 0)
			{
				if(HasPath1(G, w, v))
					return true;
			}
			p = p->nextarc;
		}
		return false;
	}
	void FindaPath(AdjGraph& G, int u, int v)
	{
		ClearTag();
		vector<int> path;
		FindaPath1(G, u, v, path);
	}
	void FindaPath1(AdjGraph& G, int u, int v, vector<int> path)	//找出一个从u到v的简单路径，注意path不能是引用参数
	{
		visited[u] = 1;
		path.push_back(u);
		if (u == v)
		{
			for (int i = 0; i < path.size(); i++)
				cout << path[i] << " ";
			cout << endl;
			return;
		}
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (visited[w] == 0)
				FindaPath1(G, w, v, path);
			p = p->nextarc;
		}
	}

	bool HasCycle(AdjGraph& G)
	{
		for(int i = 0;i < G.n;i++)		//轮流以每一个结点为起始点找路径，看是否有回路
		{
			vector<int> path;
			vector<int> inpath(G.n, 0);
			if (HasCycle1(G, i, path, inpath))
				return true;
		}
		return false;
	}
	bool HasCycle1(AdjGraph& G, int u, vector<int> path, vector<int> inpath)	 //判断有向图中是否存在任何简单回路
	{
		inpath[u] = 1;
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (inpath[w] == 0)
			{
				if (HasCycle1(G, w, path, inpath))
					return true;
			}
			else
				return true;
			p = p->nextarc;
		}
		return false;
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

	cout << "一个深度优先遍历（连通图）：" << endl;
	G.DFS(G, 0);
	cout << endl;
	cout << "一个深度优先遍历（非连通图）：" << endl;
	G.DFSA(G);
	cout << endl;
	if (G.IsConnected(G))
		cout << "该无向图是连通的" << endl;
	else
		cout << "该无向图不连通" << endl;
	cout << endl;

	cout << "一个广度优先遍历（连通图）：" << endl;
	G.BFS(G, 0);
	cout << endl;
	cout << "一个广度优先遍历（非连通图）：" << endl;
	G.BFSA(G);
	cout << endl;
	
	cout << "输入你要查找的路径（起始点和终点）：";
	int u, v;
	cin >> u;
	cin >> v;
	if (G.HasPath(G, u, v))
	{
		cout << "存在从" << u << "到" << v << "的简单路径，其中一条简单路径为：";
		G.FindaPath(G, u, v);
		cout << endl;
	}
	else
		cout << "不存在从" << u << "到" << v << "的简单路径" << endl;
	if (G.HasCycle(G))
		cout << "该有向图存在回路" << endl;
	else
		cout << "该有向图不存在回路" << endl;


	return 0;
}