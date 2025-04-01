//一个图G采用邻接矩阵作为存储结构，设计一个算法采用广度优先遍历判断顶点i到顶点j是否有路径（假设顶点i和j都是G中的顶点）。
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f3f;
class MatGraph
{
public:
	int edges[MAXV][MAXV];
	int n, e;

	void CreateMatGraph(int a[][MAXV], int n, int e)
	{
		this->n = n;
		this->e = e;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				this->edges[i][j] = a[i][j];
			}
		}
	}

	void DispMatGraph()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (edges[i][j] == INF)
					printf("%5s", "∞");
				else
					printf("%4d", edges[i][j]);
			}
			printf("\n");
		}
	}

	bool HasPath(int i, int j)
	{
		vector<int> visited(n, 0);
		queue<int> qu;
		qu.push(i);
		visited[i] = 1;
		bool has_path = false;
		while (!qu.empty())
		{
			int u = qu.front();
			qu.pop();
			if (u == j)
				has_path = true;
			for (int i = 0; i < n; i++)
			{
				if (edges[u][i] != 0 && edges[u][i] != INF)
				{
					if(visited[i] == 0)
					{
						visited[i] = 1;
						qu.push(i);
					}
				}
			}
		}
		return has_path;
	}
	
};
int main()
{
	MatGraph g;
	int n = 5, e = 5;
	int a[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	g.CreateMatGraph(a, n, e);
	cout << "邻接矩阵：\n";
	g.DispMatGraph();
	cout << "输入路径起点i：";
	int i;
	cin >> i;
	cout << "输入路径终点j：";
	int j;
	cin >> j;

	if (g.HasPath(i, j))
	{
		printf("存在从顶点%d到%d的路径\n", i, j);
	}
	else
		printf("不存在从顶点%d到%d的路径\n", i, j);

	return 0;
}