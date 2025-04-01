//һ��ͼG�����ڽӾ�����Ϊ�洢�ṹ�����һ���㷨���ù�����ȱ����ж϶���i������j�Ƿ���·�������趥��i��j����G�еĶ��㣩��
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
					printf("%5s", "��");
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
	cout << "�ڽӾ���\n";
	g.DispMatGraph();
	cout << "����·�����i��";
	int i;
	cin >> i;
	cout << "����·���յ�j��";
	int j;
	cin >> j;

	if (g.HasPath(i, j))
	{
		printf("���ڴӶ���%d��%d��·��\n", i, j);
	}
	else
		printf("�����ڴӶ���%d��%d��·��\n", i, j);

	return 0;
}