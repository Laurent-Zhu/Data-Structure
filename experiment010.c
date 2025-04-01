#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct AdjNode
{
	int weight;
}AdjNode;

typedef struct MatGraph
{
	AdjNode edges[100][100];
	int num_vex;
	int num_edges;
}MatGraph;

int dist[100][100];

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

void Floyd(MatGraph* matrix)	//使用弗洛伊德算法求出任意两点间的最短路径长度
{
	for (int i = 0; i < matrix->num_vex; i++)	//初始化dist矩阵
	{
		for (int j = 0; j < matrix->num_edges; j++)
		{
			dist[i][j] = matrix->edges[i][j].weight;
		}
	}

	for (int i = 0; i < matrix->num_vex; i++)	//最外层循环表示每次以第i个结点为中转点
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			for (int k = 0; k < matrix->num_vex; k++)
			{
				if (dist[j][i] + dist[i][k] < dist[j][k])	//满足条件则更新j到k的距离
				{
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}
}

void Show_Dists(int* dists, int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("%d", dists[i]);
		if (i != (m - 1))
			printf("\n");
	}
}

int main()
{
	int n;
	MatGraph* matrix = (MatGraph*)malloc(sizeof(MatGraph));
	scanf("%d", &matrix->num_vex);
	n = matrix->num_vex;
	matrix->num_edges = 0;
	init(matrix);	//初始化邻接矩阵

	Floyd(matrix);	//使用弗洛伊德算法

	int m;	//要查找的路径的个数
	scanf("%d", &m);
	int* dists = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		dists[i] = dist[start][end];
	}
	Show_Dists(dists, m);	//输出最短路径长度

	free(matrix);

	return 0;
}