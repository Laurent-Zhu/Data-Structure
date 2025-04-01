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

int dist[100][100];		//最短距离矩阵
int path[100][100];		//path[i][j]表示从顶点i到顶点j的中转结点序号

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


void Floyd(MatGraph* matrix)
{
	for (int i = 0; i < matrix->num_vex; i++)	//初始化dist矩阵和路径矩阵path
	{
		for (int j = 0; j < matrix->num_edges; j++)
		{
			dist[i][j] = matrix->edges[i][j].weight;
			if (matrix->edges[i][j].weight != 0 && matrix->edges[i][j].weight != 10000)
			{
				path[i][j] = i;
			}
		}
	}
	for (int i = 0; i < matrix->num_vex; i++)	//最外层循环表示每次以第i个结点为中转点
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			for (int k = 0; k < matrix->num_vex; k++)
			{
				if (dist[j][i] + dist[i][k] < dist[j][k])	//满足条件则更新j到k的距离，并更新路径
				{
					dist[j][k] = dist[j][i] + dist[i][k];
					path[j][k] = i;		//较上题增加部分，把中转点序号赋值给path数组对应的元素
				}
			}
		}
	}
}

void Show_Paths(int start, int end)		//展示路径
{
	int result[100];	//用来存放路径中的中转点（包括start和end）
	int i = 0;
	int k = end;
	while (k != start)	//start到end可能有多个中转点，从后往前找，直到中转点是start时停止
	{					//将找到的中转点（包括start和end）都赋值给临时数组result
		result[i] = k;
		i++;
		k = path[start][k];
	}
	result[i] = start;
	while (i >= 0)	//由于result中储存的是倒序的中转点序列，要反过来输出
	{
		printf("%d", result[i]);
		i--;
		if (i >= 0)
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