#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100//规定数组的最大元素个数

struct SqList {
    int last; //指示数组最后一个元素的下标
    int a[MAXSIZE];
};

void GetList(struct SqList* list)//从用户处得到数组
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
void Merge(struct SqList* list1, struct SqList* list2, struct SqList* list3)//合并两个升序数组
{
    if (list3 == NULL)
        printf("FALSE");
    int i, j, k = 0;
    list3->last = list1->last + list2->last;
    for (i = 0, j = 0; i <= list1->last && j <= list2->last; k++)//逐个元素比较
    {
        if (list1->a[i] <= list2->a[j])//较小的元素进入第三个数组
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
    k--;//for循环中最后多加了一次，要减回去
    if (i < list1->last)//将剩余的元素直接添加到第三个数组
    {
        for (; i <= list1->last; i++, k++)
        {
            list3->a[k] = list1->a[i];
        }
    }
    else if (j < list2->last)//同上if语句作用
    {
        for (; j <= list2->last; j++, k++)
        {
            list3->a[k] = list2->a[j];
        }
    }
    else return;//若没有剩余，直接返回
}
void PrintList(struct SqList* list3)
{
    if (list3 == NULL)//空顺序表判断
        printf("FALSE");
    for (int i = 0; i < list3->last; i++)//逐个元素打印
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
