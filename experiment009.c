#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

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

int visited[100] = { 0 };		//表示S集合
int dist[100] = { 10000 };
int path[100] = { 0 };		//储存路径

void PrintGraph(MatGraph* p)		
{
	for (int i = 0; i < p->num_vex; i++)
	{
		for (int j = 0; j < p->num_vex; j++)
			printf("%d ", p->edges[i][j].weight);
		printf("\n");
	}
}

void MinPath(MatGraph* matrix, int x)		//使用迪杰斯特拉算法，将x作为起点
{
	for (int i = 0; i < matrix->num_vex; i++)	//第一步，将dist初始化为顶点x到其他点的距离
	{
		dist[i] = matrix->edges[x][i].weight;
	}
	visited[x] = 1;

	for (int j = 0; j < matrix->num_vex - 1; j++)
	{
		int k = 0;
		int min = 10000;
		for (int i = 0; i < matrix->num_vex; i++)	//第二步，在dist中选出最小的那个，作为下一次出发的起点
		{
			if (dist[i] < min && visited[i] == 0)
			{
				min = dist[i];
				k = i;		//dist[k]为当前dist数组中最小的一个
			}
		}
		visited[k] = 1;		//第三步，将顶点k加入S集合
		for (int i = 0; i < matrix->num_vex; i++)	//第四步，以顶点k为中转点，更新dist数组
		{
			if (dist[k] + matrix->edges[k][i].weight < dist[i])		//看从0到直接到顶点i的距离和0经过k到i的距离哪个更短，将短的作为dist[i]
			{
				dist[i] = dist[k] + matrix->edges[k][i].weight;
				path[i] = k;		//更新路径，将k作为i的前驱
			}
		}
	}//第五步，重复以上步骤n-1次
}

void ShowPath(int x, int y)		//打印从x到y的最短路径
{
	int i = 0;
	int path1[100] = {10000};	//存放反转的路径
	int k = y;
	while (k != x)	//反转路径
	{
		path1[i] = k;
		k = path[k];
		i++;
	}
	path1[i] = k;	//正向输出路径
	while (i >= 0)
	{
		printf("%d\n", path1[i]);
		i--;
	}
}

int main()
{
	MatGraph* matrix = (MatGraph*)malloc(sizeof(MatGraph));
	scanf("%d", &matrix->num_vex);
	matrix->num_edges = 0;
	for (int i = 0; i < matrix->num_vex; i++)	//初始化邻接矩阵
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			scanf("%d", &matrix->edges[i][j].weight);
			if (matrix->edges[i][j].weight != 0 && matrix->edges[i][j].weight != 10000 && j > i)
				matrix->num_edges++;
		}
	}
	int x, y;
	scanf("%d %d", &x, &y);	//获取起点和终点
	MinPath(matrix, x);	//调用迪杰斯特拉算法模块，以x为起点
	ShowPath(x, y);
	free(matrix);

	return 0;
}