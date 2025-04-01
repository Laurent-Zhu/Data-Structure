//假设一个有向图采用邻接矩阵g存储，设计一个算法求顶点i的所有入边邻接点。
#include<iostream>
#include<vector>
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

	void InNodes(int i)
	{
		vector<int> PreAdjNodes;
		for (int j = 0; j < n; j++)
		{
			if (edges[j][i] != 0 && edges[j][i] != INF)
			{
				PreAdjNodes.push_back(j);
			}
		}
		for (int j = 0; j < PreAdjNodes.size(); j++)
		{
			cout << PreAdjNodes[j] << " ";
		}
		cout << endl;
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
	cout << "输入要查找的顶点i：";
	int i;
	cin >> i;
	cout << "顶点" << i << "的入边邻接点有：";
	g.InNodes(i);

	return 0;
}