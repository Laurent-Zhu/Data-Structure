#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct AdjNode
{
	int weight;
}AdjNode;

typedef struct MatGraph
{
	AdjNode edges[6][6];
	int num_vex;
	int num_edges;
}MatGraph;

int dist[100][100];
int path[100][100][100];

void init(MatGraph* matrix)	//初始化邻接矩阵
{
	for (int i = 0; i < matrix->num_vex; i++)
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			scanf("%d", &matrix->edges[i][j].weight);
			if (matrix->edges[i][j].weight != 0 && matrix->edges[i][j].weight != 10000 && j > i)
				matrix->num_edges++;
		}
	}
}

void New_Path(int j, int i, int k)
{
	path[j][k][0] = j;
	path[j][k][1] = i;
	path[j][k][2] = k;
}

void Floyd(MatGraph* matrix)
{
	for (int i = 0; i < matrix->num_vex; i++)	//初始化dist矩阵和路径矩阵path
	{
		for (int j = 0; j < matrix->num_edges; j++)
		{
			dist[i][j] = matrix->edges[i][j].weight;
			if (matrix->edges[i][j].weight != 0 && matrix->edges[i][j].weight != 10000)
			{
				path[i][j][0] = i;
				path[i][j][1] = j;
			}
		}
	}
	printf("%s", path[0][1]);
	for (int i = 0; i < matrix->num_vex; i++)	//最外层循环表示每次以第i个结点为中转点
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			for (int k = 0; k < matrix->num_vex; k++)
			{
				if (dist[j][i] + dist[i][k] < dist[j][k])	//满足条件则更新j到k的距离，并更新路径
				{
					dist[j][k] = dist[j][i] + dist[i][k];
					New_Path(j, i, k);
				}
			}
		}
	}
}

void Show_Paths(int start, int end)
{
	int i = 0;
	while(path[start][end][i] != end)
	{
		printf("%d\n", path[start][end][i]);
		i++;
	}
	printf("%d", path[start][end][i]);
}

int main()
{
	int n;
	MatGraph* matrix = (MatGraph*)malloc(sizeof(MatGraph));
	scanf("%d", &matrix->num_vex);
	n = matrix->num_vex;
	matrix->num_edges = 0;
	init(matrix);

	Floyd(matrix);

	int m;	//要查找的路径的个数
	scanf("%d", &m);
	
	int starts[100], ends[100];
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &starts[i], &ends[i]);
	}
	for (int i = 0; i < m; i++)
	{
		Show_Paths(starts[i], ends[i]);
		if (i != m - 1)
			printf("\n");
	}

	free(matrix);

	return 0;
}