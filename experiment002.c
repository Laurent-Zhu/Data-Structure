#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100//�涨��������Ԫ�ظ���

struct SqList {
    int last; //ָʾ�������һ��Ԫ�ص��±�
    int a[MAXSIZE];
};

void GetList(struct SqList* list)//���û����õ�����
{
    int n;
    int i;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &(list->a[i]));
    }
    list->last = i;
}
void Merge(struct SqList* list1, struct SqList* list2, struct SqList* list3)//�ϲ�������������
{
    if (list3 == NULL)
        printf("FALSE");
    int i, j, k = 0;
    list3->last = list1->last + list2->last;
    for (i = 0, j = 0; i <= list1->last && j <= list2->last; k++)//���Ԫ�رȽ�
    {
        if (list1->a[i] <= list2->a[j])//��С��Ԫ�ؽ������������
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
    k--;//forѭ�����������һ�Σ�Ҫ����ȥ
    if (i < list1->last)//��ʣ���Ԫ��ֱ����ӵ�����������
    {
        for (; i <= list1->last; i++, k++)
        {
            list3->a[k] = list1->a[i];
        }
    }
    else if (j < list2->last)//ͬ��if�������
    {
        for (; j <= list2->last; j++, k++)
        {
            list3->a[k] = list2->a[j];
        }
    }
    else return;//��û��ʣ�ֱ࣬�ӷ���
}
void PrintList(struct SqList* list3)
{
    if (list3 == NULL)//��˳����ж�
        printf("FALSE");
    for (int i = 0; i < list3->last; i++)//���Ԫ�ش�ӡ
    {
        printf("%d\n", list3->a[i]);
    }
}

int main()
{
    struct SqList* list1, * list2, * list3;
    list1 = (struct SqList*)malloc(sizeof(struct SqList));
    list2 = (struct SqList*)malloc(sizeof(struct SqList));
    list3 = (struct SqList*)malloc(sizeof(struct SqList));
    GetList(list1);
    GetList(list2);
    Merge(list1, list2, list3);
    PrintList(list3);
    free(list1);
    free(list2);
    free(list3);

    return 0;
}
