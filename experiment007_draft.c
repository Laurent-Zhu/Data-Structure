//此程序为哈夫曼编译系统（草稿），正稿见experiment007.c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 20
#define N 2*M-1
typedef struct
{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode,*HTree;

typedef struct
{
	char HCode[20];
	char ch_value;
}HCodeForValue;

HCodeForValue HCodeArray[5];	//存放不同字符对应的哈夫曼编码
char str[50];		//存放用户输入的字符串
char HuffCode[250];	    //存放字符串的哈夫曼编码
char DeHuffCode[50];		//存放由哈夫曼编码HuffCode解码所得的字符串

void HTree_init(int n, HTree HuffmanTree) 
{
	/*char* val = (char*)malloc(2 * n * sizeof(char));
	int* w = (int*)malloc(2 * n * sizeof(int));
	for (int i = 0; i < 2 * n; i++)
	{
		scanf(" %c", &val[i]);
		if(val[i] != ' ')
			HuffmanTree[i].data = val[i];
	}
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &w[i]);
		if(w[i]!=' ')
			HuffmanTree[i].weight = w[i];
	}*/
	/*for (int i = 0; i < n; i++)
	{
		HuffmanTree[i].data = val[i];
		HuffmanTree[i].weight = w[i];
	}*/

	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &HuffmanTree[i].data);
	}
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &HuffmanTree[i].weight);
	}
	for (int i = 0; i < n; i++)
	{
		HuffmanTree[i].parent = -1;
		HuffmanTree[i].lchild = -1;
		HuffmanTree[i].rchild = -1;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		HuffmanTree[i].data = 'n';
		HuffmanTree[i].weight = 0;
		HuffmanTree[i].parent = -1;
		HuffmanTree[i].lchild = -1;
		HuffmanTree[i].rchild = -1;
	}
}

void Get_Corresponding_HCode(HTree HuffmanTree, int n)//得到不同字符对应的哈夫曼编码
{
	int i = 0, j = 0;
	int p = 0, pre = 0;
	for (; i < n; i++)
	{
		pre = i;
		p = HuffmanTree[pre].parent;
		HCodeArray[i].ch_value = HuffmanTree[i].data;
		for (j = 0; HuffmanTree[pre].parent != -1; j++)
		{
			if (HuffmanTree[p].lchild == pre)
				HCodeArray[i].HCode[j] = '0';
			else
				HCodeArray[i].HCode[j] = '1';
			pre = p;
			p = HuffmanTree[pre].parent;
		}
		HCodeArray[i].HCode[j] = '\0';
	}
	for (i = 0; i < n; i++)
	{
		int len = strlen(HCodeArray[i].HCode);
		for (j = 0; j < len / 2; j++)
		{
			char temp = HCodeArray[i].HCode[j];
			HCodeArray[i].HCode[j] = HCodeArray[i].HCode[len - j - 1];
			HCodeArray[i].HCode[len - j - 1] = temp;
		}
	}
}

void Select(HTree HuffmanTree, int n, int* s1, int* s2)
{
	int min;
	int i = 0;

	//找到第一个最小值
	for (i = 0; i < n; i++)		//找到第一个根结点
	{
		if (HuffmanTree[i].parent == -1)
		{
			*s1 = i;
			min = HuffmanTree[i].weight;
			break;
		}
	}
	for (; i < n; i++)
	{
		if (HuffmanTree[i].parent == -1 && HuffmanTree[i].weight < min)
		{
			*s1 = i;
			min = HuffmanTree[i].weight;
		}
	}

	//找到第二个最小值
	for (i = 0; i < n; i++)		//找到第一个根结点
	{
		if (HuffmanTree[i].parent == -1 && i != *s1)
		{
			*s2 = i;
			min = HuffmanTree[i].weight;
			break;
		}
	}
	for (; i < n; i++)
	{
		if (HuffmanTree[i].parent == -1 && HuffmanTree[i].weight < min && i != *s1)
		{
			*s2 = i;
			min = HuffmanTree[i].weight;
		}
	}
}

void CreateHTree(HTree HuffmanTree, int n)
{
	int i = 0;
	int s1 = 0, s2 = 0;
	for (i = n; i < 2 * n - 1; i++)
	{
		Select(HuffmanTree, i, &s1, &s2);
		HuffmanTree[s1].parent = i;
		HuffmanTree[s2].parent = i;
		HuffmanTree[i].lchild = s1;
		HuffmanTree[i].rchild = s2;
		HuffmanTree[i].weight = HuffmanTree[s1].weight + HuffmanTree[s2].weight;
	}
}

void Encode(HTree HuffmanTree, int n)
{
	int len = strlen(str);
	int i = 0, j = 0;
	int k = 0;
	int p = 0, pre = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (HCodeArray[j].ch_value == str[i])
			{
				//printf("%s", HCodeArray[j].HCode);
				strcat(HuffCode, HCodeArray[j].HCode);
				break;
			}
		}
	}
}

void Decode(HTree HuffmanTree, int n)
{
	int i = 0;
	int root = -1;
	for (i = 0; i < 2 * n - 1; i++)		//找到根结点
	{
		if (HuffmanTree[i].parent == -1)
		{
			root = i;
			break;
		}
	}
	i = 0;
	//printf("\n%d", HuffmanTree[root].weight);
	//printf("\n%d", strlen(HuffCode));
	int p = root;
	int pos = 0;	//指示当前读到哈夫曼码的位数
	while (pos < strlen(HuffCode))
	{
		while (HuffmanTree[p].lchild != -1 && HuffmanTree[p].rchild != -1)		//读到叶子节点即为所表示的字符
		{
			if (HuffCode[pos] == '0')
				p = HuffmanTree[p].lchild;
			//else if (HuffCode[pos] == '1')
			else
				p = HuffmanTree[p].rchild;
			pos++;
		}
		DeHuffCode[i] = HuffmanTree[p].data;
		i++;
		p = root;	//重新指向根结点
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	HTree HuffmanTree = (HTree)malloc((2 * n - 1) * sizeof(HTNode));
	HTree_init(n, HuffmanTree);
	/*for (int i = 0; i < n; i++)
	{
		printf("%c %d", HuffmanTree[i].data, HuffmanTree[i].weight);
	}
	*/
	CreateHTree(HuffmanTree, n);
	/*for (int i = 0; i < n; i++)
	{
		printf("%d\n", HuffmanTree[HuffmanTree[i].parent].weight);
	}*/
	Get_Corresponding_HCode(HuffmanTree, n);
	/*for (int i = 0; i < n; i++)
	{
		printf("%c->%s\n", HCodeArray[i].ch_value, HCodeArray[i].HCode);
	}*/

	
	/*for (int i = 0; i < 50; i++)
	{
		scanf("%c", &str[i]);
		if (str[i] == '\n' && i != 0)
		{
			str[i] = '\0';
			break;
		}
	}*/
	scanf("%49s", str);
	//fgets(str, 50, stdin);
	//gets(str);
	//printf("%s", str);
	//printf("1");
	//char* HCode[20];
	Encode(HuffmanTree, n);
	printf("%s", HuffCode);
	Decode(HuffmanTree, n);
	printf("\n%s", DeHuffCode);
	/*for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < strlen; j--)
		{
			printf("%c", HCode[i][j]);
		}
	}*/
	return 0;
}