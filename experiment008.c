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

int visited[100] = { 0 };		//��ʾS����
int dist[100] = { 10000 };

void PrintGraph(MatGraph* p)
{
	for (int i = 0; i < p->num_vex; i++)
	{
		for (int j = 0; j < p->num_vex; j++)
			printf("%d ", p->edges[i][j].weight);
		printf("\n");
	}
}

void MinPath(MatGraph* matrix)		//ʹ�õϽ�˹�����㷨
{
	for (int i = 0; i < matrix->num_vex; i++)	//��һ������dist��ʼ��Ϊ����0��������ľ���
	{
		dist[i] = matrix->edges[0][i].weight;
	}
	visited[0] = 1;

	for(int j = 0; j < matrix->num_vex - 1; j++)
	{
		int k = 0;
		int min = 10000;
		for (int i = 0; i < matrix->num_vex; i++)	//�ڶ�������dist��ѡ����С���Ǹ�����Ϊ��һ�γ��������
		{
			if (dist[i] < min && visited[i] == 0)
			{
				min = dist[i];
				k = i;		//dist[k]Ϊ��ǰdist��������С��һ��
			}
		}
		visited[k] = 1;		//��������������k����S����
		for (int i = 0; i < matrix->num_vex; i++)	//���Ĳ����Զ���kΪ��ת�㣬����dist����
		{
			if (dist[k] + matrix->edges[k][i].weight < dist[i])		//����0��ֱ�ӵ�����i�ľ����0����k��i�ľ����ĸ����̣����̵���Ϊdist[i]
				dist[i] = dist[k] + matrix->edges[k][i].weight;	
		}
	}//���岽���ظ����ϲ���n-1��
}

int main()
{
	MatGraph* matrix = (MatGraph*)malloc(sizeof(MatGraph));
	scanf("%d", &matrix->num_vex);
	matrix->num_edges = 0;
	for (int i = 0; i < matrix->num_vex; i++)	//��ʼ���ڽӾ���
	{
		for (int j = 0; j < matrix->num_vex; j++)
		{
			scanf("%d", &matrix->edges[i][j].weight);
			if (matrix->edges[i][j].weight != 0 && matrix->edges[i][j].weight != 10000 && j > i)
				matrix->num_edges++;
		}
	}
	MinPath(matrix);	//���õϽ�˹�����㷨ģ��
	for (int i = 0; i < matrix->num_vex; i++)
	{
		printf("%d\n", dist[i]);
	}
	free(matrix);

	return 0;
}