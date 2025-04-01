//����һ��ͼ�����ڽӱ�G��Ϊ�洢�ṹ�����һ���㷨�������u��v�Ĳ���������k�����м�·����
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#define MAXV 20		//���������
const int INF = 0x3f3f3f3f;
using namespace std;

struct ArcNode		//�߽������
{
	int adjvex;		//�ڽӵ����ֵ��������
	int weight;
	ArcNode* nextarc;
};

struct HNode		//ͷ�������
{
	string info;		//��������Ϣ
	ArcNode* firstarc;
};

class AdjGraph		//���ڽӱ���ͼ
{
public:
	HNode adjlist[MAXV];
	int n, e;
	int visited[MAXV];		//���ڱ�ʶ��Ӧ�����Ľ���Ƿ���ʹ���û�з���Ϊ0�����ʹ�Ϊ1
	vector<int> cycpath;

	AdjGraph()		//���캯��
	{
		for (int i = 0; i < MAXV; i++)
		{
			adjlist[i].firstarc = NULL;
			visited[i] = 0;
		}
	}

	~AdjGraph()		//��������
	{
		ArcNode* p, * pre;
		for (int i = 0; i < n; i++)
		{
			pre = adjlist[i].firstarc;
			if (pre != NULL)
			{
				p = pre->nextarc;
				while (p != NULL)
				{
					delete pre;
					pre = p;
					p = p->nextarc;
				}
				delete pre;
			}
		}
	}

	void CreateAdjGraph(int a[][MAXV], int n, int e)		//����ͼ
	{
		ArcNode* p;
		this->n = n;
		this->e = e;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (a[i][j] != 0 && a[i][j] != INF)
				{
					p = new ArcNode();
					p->adjvex = j;
					p->weight = a[i][j];
					p->nextarc = adjlist[i].firstarc;
					adjlist[i].firstarc = p;
				}
			}
		}
	}

	void DispAdjGraph()		//��ӡͼ
	{
		cout << "(�ڽӵ��������ñ�Ȩֵ)" << endl;
		ArcNode* p;
		for (int i = 0; i < n; i++)
		{
			printf(" [%d]", i);
			p = adjlist[i].firstarc;
			if (p != NULL)
				cout << " �� ";
			while (p != NULL)
			{
				printf("(%d,%d) ", p->adjvex, p->weight);
				p = p->nextarc;
			}
			printf("\n");
		}
	}

	void ClearTag()
	{
		for (int i = 0; i < MAXV; i++)
		{
			visited[i] = 0;
		}
	}

	void FindPath_without_k(AdjGraph& G, int u, int v, int k)
	{
		vector<int> path;
		ClearTag();
		bool has = false;
		printf("���ڴ�%d��%d�Ҳ�����%d��·���У�\n", u, v, k);
		FindPath_without_k1(G, u, v, k, has, path);
		if (!has)
			printf("�����ڴ�%d��%d�Ҳ�����%d��·��\n", u, v, k);
	}
	void FindPath_without_k1(AdjGraph& G, int u, int v, int k, bool& has, vector<int> path)		//���Ĵ���
	{
		visited[u] = 1;
		path.push_back(u);
		if (u == v)
		{
			has = true;
			for (int i = 0; i < path.size(); i++)
				cout << path[i] << " ";
			cout << endl;
			visited[u] = 0;
			return;
		}
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (w == k)
			{
				p = p->nextarc;
				continue;
			}
			if (visited[w] == 0)
				FindPath_without_k1(G, w, v, k, has, path);
			p = p->nextarc;
		}
		visited[u] = 0;
	}

};


int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,1,INF,1,INF},{1,0,1,INF,INF},{INF,1,0,1,1},{1,INF,1,0,INF},{INF,INF,1,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout << "\n";

	cout << "���u��";
	int u;
	cin >> u;
	cout << "�յ�v��";
	int v;
	cin >> v;
	cout << "�������ĵ�k��";
	int k;
	cin >> k;
	G.FindPath_without_k(G, u, v, k);

	

	return 0;
}