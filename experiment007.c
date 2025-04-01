#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode, * HTree;

typedef struct
{
	char HCode[20];
	char ch_value;
}HCodeForValue;

HCodeForValue HCodeArray[5];	//��Ų�ͬ�ַ���Ӧ�Ĺ���������
char str[50];		//����û�������ַ���
char HuffCode[250];	    //����ַ����Ĺ���������
char DeHuffCode[50];		//����ɹ���������HuffCode�������õ��ַ���

void HTree_init(int n, HTree HuffmanTree)
{
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

void Get_Corresponding_HCode(HTree HuffmanTree, int n)//�õ���ͬ�ַ���Ӧ�Ĺ���������
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

	//�ҵ���һ����Сֵ
	for (i = 0; i < n; i++)		//�ҵ���һ�������
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

	//�ҵ��ڶ�����Сֵ
	for (i = 0; i < n; i++)		//�ҵ���һ�������
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
	for (i = 0; i < 2 * n - 1; i++)		//�ҵ������
	{
		if (HuffmanTree[i].parent == -1)
		{
			root = i;
			break;
		}
	}
	i = 0;
	int p = root;
	int pos = 0;	//ָʾ��ǰ�������������λ��
	while (pos < strlen(HuffCode))
	{
		while (HuffmanTree[p].lchild != -1 && HuffmanTree[p].rchild != -1)		//����Ҷ�ӽڵ㼴Ϊ����ʾ���ַ�
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
		p = root;	//����ָ������
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	HTree HuffmanTree = (HTree)malloc((2 * n - 1) * sizeof(HTNode));
	HTree_init(n, HuffmanTree);
	CreateHTree(HuffmanTree, n);
	Get_Corresponding_HCode(HuffmanTree, n);
	scanf("%49s", str);
	Encode(HuffmanTree, n);
	printf("%s", HuffCode);
	Decode(HuffmanTree, n);
	printf("\n%s", DeHuffCode);
	
	return 0;
}