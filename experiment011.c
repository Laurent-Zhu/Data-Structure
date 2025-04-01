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

int dist[100][100];		//��̾������
int path[100][100];		//path[i][j]��ʾ�Ӷ���i������j����ת������

void init(MatGraph* matrix)	//��ʼ���ڽӾ���
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
	for (int i = 0; i < matrix->num_vex; i++)	//��ʼ��dist�����·������path
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
	for (int i = 0; i < matrix->num_vex; i++)	//�����ѭ����ʾÿ���Ե�i�����Ϊ��ת��
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			for (int k = 0; k < matrix->num_vex; k++)
			{
				if (dist[j][i] + dist[i][k] < dist[j][k])	//�������������j��k�ľ��룬������·��
				{
					dist[j][k] = dist[j][i] + dist[i][k];
					path[j][k] = i;		//���������Ӳ��֣�����ת����Ÿ�ֵ��path�����Ӧ��Ԫ��
				}
			}
		}
	}
}

void Show_Paths(int start, int end)		//չʾ·��
{
	int result[100];	//�������·���е���ת�㣨����start��end��
	int i = 0;
	int k = end;
	while (k != start)	//start��end�����ж����ת�㣬�Ӻ���ǰ�ң�ֱ����ת����startʱֹͣ
	{					//���ҵ�����ת�㣨����start��end������ֵ����ʱ����result
		result[i] = k;
		i++;
		k = path[start][k];
	}
	result[i] = start;
	while (i >= 0)	//����result�д�����ǵ������ת�����У�Ҫ���������
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

	int m;	//Ҫ���ҵ�·���ĸ���
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