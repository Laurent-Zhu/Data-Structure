//����һ������ͼ�����ڽӱ�G��Ϊ�洢�ṹ�����һ���㷨�ڴ��ھ�������v�ļ򵥻�·ʱ������еļ򵥻�·��
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

	bool HasCycle(AdjGraph& G, int v)
	{
		ClearTag();
		bool has = false;
		vector<int> path;

		HasCycle1(G, v, v, -1, has, path);
		return has;
	}
	void HasCycle1(AdjGraph& G, int v, int u, int d, bool& has, vector<int> path)		//���Ĵ���
	{
		d++;
		path.push_back(u);
		visited[u] = 1;
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (visited[w] == 0)
				HasCycle1(G, v, w, d, has, path);
			else if (w == v && d > 1)
			{
				path.push_back(w);
				has = true;
				for (int i = 0; i < path.size(); i++)
					cout << path[i] << " ";
				cout << endl;
				visited[u] = 0;
				return;
			}
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
	cout << "������Ҫ�жϵĶ���v��";
	int v;
	cin >> v;
	printf("������%d�����м򵥻�·��\n", v);
	if (G.HasCycle(G, v))
	{}
	else
		printf("�����ھ�������%d�ļ򵥻�·\n", v);

	return 0;
}