//ÁÚ½Ó¾ØÕó
#include<iostream>
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
					printf("%5s", "¡Ş");
				else
					printf("%4d", edges[i][j]);
			}
			printf("\n");
		}
	}

};
int main()
{
	MatGraph g;
	int n = 5, e = 5;
	int a[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	g.CreateMatGraph(a, n, e);
	cout << "ÁÚ½Ó¾ØÕó£º\n";
	g.DispMatGraph();

	return 0;
}