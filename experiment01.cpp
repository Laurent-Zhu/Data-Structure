#include<iostream>
using namespace std;
#define MAXSIZE 100

class SqList {
public:
	int last; 
	int a[MAXSIZE];
	SqList():last(0){}
};

void GetList(SqList*& list)
{
	int n;
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> list->a[i];
	}
	list->last = i;
}
void Merge(SqList*& list1, SqList*& list2, SqList*& list3)
{
	if (list3 == nullptr)
		cout << "FALSE";
	int i, j, k=0;
	list3->last = list1->last + list2->last;
	for (i = 0, j = 0; i <= list1->last && j <= list2->last; k++)
	{
		if (list1->a[i] <= list2->a[j])
		{
			list3->a[k] = list1->a[i];
			i++;
		}
		else
		{
			list3->a[k] = list2->a[j];
			j++;
		}
	}
	k--;
	list3->last--;
	if (i < list1->last)
	{
		for (; i <= list1->last; i++, k++)
		{
			list3->a[k] = list1->a[i];
		}
	}
	else if (j < list2->last)
	{
		for (; j <= list2->last; j++, k++)
		{
			list3->a[k] = list2->a[j];
		}
	}
	else return;
}
void PrintList(SqList*& list3)
{
	if (list3 == nullptr)
		cout << "FALSE";
	for (int i = 0; i <= list3->last; i++)
	{
		cout << list3->a[i] << endl;
	}
}

int main() 
{
	SqList *list1,*list2,*list3;
	list1 = new SqList();
	list2 = new SqList();
	list3 = new SqList();
	//list1->last = 0;
	//list2->last = 0;
	GetList(list1);
	GetList(list2);
	Merge(list1, list2, list3);
	PrintList(list3);
	delete list1;
	delete list2;
	delete list3;
}
/*
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

struct SqList {
	int last;
	int a[MAXSIZE];
};

void GetList(struct SqList* list)
{
	int n;
	int i;
	//cin >> n;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		//cin >> list->a[i];
		scanf("%d",&(list->a[i]));

	}
	list->last = i;
}
void Merge(struct SqList* list1, struct SqList* list2, struct SqList* list3)
{
	if (list3 == NULL)
		//cout << "FALSE";
		printf("FALSE");
	int i, j, k=0;
	list3->last = list1->last + list2->last;
	for (i = 0, j = 0; i <= list1->last && j <= list2->last; k++)
	{
		if (list1->a[i] <= list2->a[j])
		{
			list3->a[k] = list1->a[i];
			i++;
		}
		else
		{
			list3->a[k] = list2->a[j];
			j++;
		}
	}
	k--;
	list3->last--;
	if (i < list1->last)
	{
		for (; i <= list1->last; i++, k++)
		{
			list3->a[k] = list1->a[i];
		}
	}
	else if (j < list2->last)
	{
		for (; j <= list2->last; j++, k++)
		{
			list3->a[k] = list2->a[j];
		}
	}
	else return;
}
void PrintList(struct SqList* list3)
{
	if (list3 == NULL)
		printf("FALSE");
	for (int i = 0; i <= list3->last; i++)
	{
		printf("%d\n",list3->a[i]);
	}
}

int main()
{
	struct SqList *list1,*list2,*list3;
	list1 = (struct SqList*)malloc(sizeof(struct SqList));
	list2 = (struct SqList*)malloc(sizeof(struct SqList));
	list3 = (struct SqList*)malloc(sizeof(struct SqList));
	//list1->last = 0;
	//list2->last = 0;
	GetList(list1);
	GetList(list2);
	Merge(list1, list2, list3);
	PrintList(list3);
	free(list1);
	free(list2);
	free(list3);

	return 0;
}*/