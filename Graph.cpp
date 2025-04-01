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

	void DFS(AdjGraph& G, int v)
	{
		ClearTag();
		DFS1(G, v);
	}
	void DFS0(AdjGraph& G, int v)	//������DFS1��DFS0ֻ����������ӡ
	{
		visited[v] = 1;
		ArcNode* p = G.adjlist[v].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;		
			if (visited[w] == 0)		
				DFS0(G, w);
			p = p->nextarc;
		}
	}
	void DFS1(AdjGraph& G, int v)	//**��ͨͼ**��������ȱ�������ʼ��Ϊv��������ȱ�������ջ����������ʹ��ջ��ݹ���ʵ��
	{
		cout << v << " ";
		visited[v] = 1;
		ArcNode* p = G.adjlist[v].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;		//��ǰ�����ڽӵ�����
			if (visited[w] == 0)		//�����ڽӵ�δ���ʣ��������
				DFS1(G, w);
			p = p->nextarc;
		}
	}
	void DFSA(AdjGraph& G)	//**����ͨͼ**��������ȱ���
	{
		ClearTag();
		for (int i = 0; i < G.n; i++)	//��˳����ÿһ�����Ϊ��ʼ�㣬��û�з��ʹ��������DFS
		{
			if (visited[i] == 0)
				DFS1(G, i);
		}
	}

	void BFS(AdjGraph& G, int v)
	{
		ClearTag();
		BFS1(G, v);
	}
	void BFS1(AdjGraph& G, int v)	//**��ͨͼ**�Ĺ�����ȱ�������ʼ��Ϊv��������ȱ������϶��е�������ʹ�ö�����ʵ��
	{
		queue<int> qu;
		cout << v << " ";
		visited[v] = 1;
		qu.push(v);
		while (!qu.empty())
		{
			int u = qu.front();
			qu.pop();
			ArcNode* p = G.adjlist[u].firstarc;
			while (p != NULL)
			{
				if(visited[p->adjvex] == 0)
				{
					cout << p->adjvex << " ";
					qu.push(p->adjvex);
					visited[p->adjvex] = 1;
				}
				p = p->nextarc;
			}
		}
	}
	void BFSA(AdjGraph& G)	//**����ͨͼ**�Ĺ�����ȱ���
	{
		ClearTag();
		for (int i = 0; i < G.n; i++)	//��˳����ÿһ�����Ϊ��ʼ�㣬��û�з��ʹ��������BFS
		{
			if (visited[i] == 0)
				BFS1(G, i);
		}
	}

	bool IsConnected(AdjGraph& G)	//�ж�����ͼ�Ƿ���ͨ
	{
		ClearTag();
		DFS0(G, 0);		//�ȴӽ��0��ʼ����һ��DFS
		for (int i = 0; i < G.n; i++)
		{
			if (visited[i] == 0)	//���������û���ʹ��Ľ�㣬˵��������ͼ����ͨ
				return false;
		}
		return true;
	}
	
	bool HasPath(AdjGraph& G, int u, int v)		//����������ȱ����������Ƿ���ڴ�u��v�ļ�·��
	{
		ClearTag();
		return HasPath1(G, u, v);
	}
	bool HasPath1(AdjGraph& G, int u, int v)
	{
		visited[u] = 1;
		ArcNode* p = G.adjlist[u].firstarc;

		while (p != NULL)
		{
			int w = p->adjvex;
			if (w == v)
				return true;
			else if (visited[w] == 0)
			{
				if(HasPath1(G, w, v))
					return true;
			}
			p = p->nextarc;
		}
		return false;
	}
	void FindaPath(AdjGraph& G, int u, int v)
	{
		ClearTag();
		vector<int> path;
		FindaPath1(G, u, v, path);
	}
	void FindaPath1(AdjGraph& G, int u, int v, vector<int> path)	//�ҳ�һ����u��v�ļ�·����ע��path���������ò���
	{
		visited[u] = 1;
		path.push_back(u);
		if (u == v)
		{
			for (int i = 0; i < path.size(); i++)
				cout << path[i] << " ";
			cout << endl;
			return;
		}
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (visited[w] == 0)
				FindaPath1(G, w, v, path);
			p = p->nextarc;
		}
	}

	bool HasCycle(AdjGraph& G)
	{
		for(int i = 0;i < G.n;i++)		//������ÿһ�����Ϊ��ʼ����·�������Ƿ��л�·
		{
			vector<int> path;
			vector<int> inpath(G.n, 0);
			if (HasCycle1(G, i, path, inpath))
				return true;
		}
		return false;
	}
	bool HasCycle1(AdjGraph& G, int u, vector<int> path, vector<int> inpath)	 //�ж�����ͼ���Ƿ�����κμ򵥻�·
	{
		inpath[u] = 1;
		ArcNode* p = adjlist[u].firstarc;
		while (p != NULL)
		{
			int w = p->adjvex;
			if (inpath[w] == 0)
			{
				if (HasCycle1(G, w, path, inpath))
					return true;
			}
			else
				return true;
			p = p->nextarc;
		}
		return false;
	}

};

int main()
{
	AdjGraph G;
	int n = 5, e = 5;
	int A[MAXV][MAXV] = { {0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0} };
	G.CreateAdjGraph(A, n, e);
	cout << "ͼ���ڽӱ�:\n"; G.DispAdjGraph();
	cout << "\n";

	cout << "һ��������ȱ�������ͨͼ����" << endl;
	G.DFS(G, 0);
	cout << endl;
	cout << "һ��������ȱ���������ͨͼ����" << endl;
	G.DFSA(G);
	cout << endl;
	if (G.IsConnected(G))
		cout << "������ͼ����ͨ��" << endl;
	else
		cout << "������ͼ����ͨ" << endl;
	cout << endl;

	cout << "һ��������ȱ�������ͨͼ����" << endl;
	G.BFS(G, 0);
	cout << endl;
	cout << "һ��������ȱ���������ͨͼ����" << endl;
	G.BFSA(G);
	cout << endl;
	
	cout << "������Ҫ���ҵ�·������ʼ����յ㣩��";
	int u, v;
	cin >> u;
	cin >> v;
	if (G.HasPath(G, u, v))
	{
		cout << "���ڴ�" << u << "��" << v << "�ļ�·��������һ����·��Ϊ��";
		G.FindaPath(G, u, v);
		cout << endl;
	}
	else
		cout << "�����ڴ�" << u << "��" << v << "�ļ�·��" << endl;
	if (G.HasCycle(G))
		cout << "������ͼ���ڻ�·" << endl;
	else
		cout << "������ͼ�����ڻ�·" << endl;


	return 0;
}